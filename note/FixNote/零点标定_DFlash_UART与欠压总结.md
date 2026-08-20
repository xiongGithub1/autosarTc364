# 零点标定 / DFlash / UART / 欠压 — 本轮总结

> 工程：`last364`（TC364 AUTOSAR，电机在 Core1）  
> 日期：2026-08-18  
> 相关：`note/Guides/MotorZeroCal_DFlash.md`，`note/FixNote/FOC_开环调试_VOFA与电流波形总结.md`

本文记录本轮台架上「写不进零点、切模式电流尖峰、母线欠压误报」的原因和已落地改动。

---

## 1. 现象与结论（先看这张表）

| 现象 | 不是 | 实际原因 |
|------|------|----------|
| DFlash 写失败 / 20 s 超时、`NvLastResult=PENDING` | UART 和 DFlash 抢硬件 | Fee InitGC 没完成，或 Core0 被 UART 忙等占死，NvM job 走不完 |
| `StartRejectReason=5` | 栅驱没好 | `DflashReadComplete=0`，boot `ReadBlock` 在等 InitGC=5 |
| `FaultReason=3`，`ElapsedMs≈20000` | 对齐算法挂了 | SAVING 在等 Fee，却拿对齐总超时在空等 |
| 切开环 / 标定给 Id，三相冲十几安、电源被拉垮 | 斜坡步长太大（后来已很慢仍欠压） | PWM 未开时 Id 指令已到目标；使能瞬间 PI 按大误差出压 |
| 欠压经常报 | 斜坡太陡 | VINV 无滤波 + UV 只确认 2 ms；锁存后标定/开环清不掉 |

---

## 2. Fee InitGC 是什么

Infineon Fee 上电内部状态机：**Init Garbage Collection**。双扇区 DFlash 先扫盘、建缓存，必要时把上次复位打断的 GC 做完。

`Fee_StateVar.FeeInitGCState`（UDE 可看）：

| 值 | 含义 |
|---:|------|
| 5 | **COMPLETE**，可以 `NvM_Read/WriteBlock` |
| 6 | **FAIL**（`Fee_GetStatus()` 仍可能是 `MEMIF_IDLE`） |
| 其它 | 还在扫盘 / 卡住 |

`MEMIF_IDLE` **不等于** 能写。InitGC≠5 时发出去的 job 会一直 PENDING。

NvM/Fee/Fls 的 `MainFunction` 在 **Core0** `Default_BSW_ASync_Task_10ms`（NON，优先级 30）。

---

## 3. UART 占死 Core0

`Default_Appl_Task`（Core0 1 ms）也是 **NON**。曾经在 `UartTest_MainFunction` 里 `WaitIdle` 自旋等 ASCLIN 发完（最多 10 帧 × 200 µs），同核 Fee/NvM/Fls 进不来，InitGC 完不成。

**已改：** 不再忙等。1 ms 把最多 10 个 JustFloat 帧打进一块缓冲，一次异步 `Uart_Write`，任务立刻返回。

文件：`Appl/Source/CDD/UartTest.c`

### 4 Mbps 能发多少帧

当前帧：8×float32 + `00 00 80 7F` = **36 B**，8N1 → 约 **90 µs/帧**。

- 10 帧 ≈ **0.9 ms**，1 ms 理论最多约 11 帧，10 帧已经顶满。  
- 下一拍若仍 BUSY 会跳过，`DropCount` 会涨。  
- 4 M 想稳可把 `UARTTEST_BURST_PER_1MS` 改成 8。CH340 在 4 M 丢数是 PC 侧问题。

若改成 int16（电流×100，PWM/角度原值）：载荷约 **16 B**，加帧尾约 18～20 B，约 **50 µs/帧**，1 ms 大约 20 帧。VOFA 要对电流通道配 `×0.01`。

---

## 4. NvM_WriteBlock 在哪一核

上次能写入的提交（`5b7526d`）就是 **Core1** `MotorZeroCal_MainFunction` 里 `WriteBlock`。Fee 健康时跨核调用往往能碰巧成功。

本轮曾迁到 Core0 `StartApp_Cyclic1ms`，后又按要求 **迁回 Core1**（与上次提交一致）。

| 项 | 现状 |
|----|------|
| `NvM_ReadBlock` / `WriteBlock` / job 轮询 | Core1 `MotorZeroCal_MainFunction()` |
| NvM/Fee/Fls `MainFunction` | 仍在 Core0 10 ms |
| Fee 未 IDLE/COMPLETE | 最多等 **3 s** → `FAULT_FLASH`，不再吃 20 s 对齐预算 |
| 写 job 一直 PENDING | **5 s** 后 `NvM_CancelJobs` → `FAULT_FLASH` |
| 20 s `ElapsedMs` | **只统计 RUNNING（对齐）**，不含 SAVING |
| 上电 3 s 仍读不完 | 按无 DFlash 记录放行，允许标定 |

`SaveToFlash()` 只置 `NvSaveRequest`；真正 `WriteBlock` 在 PWM 关掉之后由 1 ms 任务发出。

写成功 UDE：`NvLastOp=2`，`NvLastResult=0`，`Stage=COMPLETE`，`DflashValid=1`。

---

## 5. 零点标定时序（当前代码）

文件：`MotorZeroCal.c` / `.h`

```text
ALIGN_RAMP（Id 斜坡）
  → ALIGN_HOLD（首次 1.5 s / 重试 0.3 s）
  → READ_ANGLE
  → 已在 0 ±1° 电角度 → 关 PWM，排队写 DFlash
  → 未到 0 → 写 TLE5012 ANG_BASE，RetryCount++，再 HOLD
```

| 参数 | 当前值 |
|------|--------|
| `IdRefTargetA` | **3 A**（UDE 可改） |
| `ID_RAMP_STEP_A` | **0.0001 A / 10 kHz 拍**（3 A 约 3 s 爬完） |
| 首次保持 | **1.5 s**（`DELAY_MS`） |
| 每次重试保持 | **0.3 s**（`RETRY_DELAY_MS`） |
| 最大重试 | **30** |
| 对齐总超时 | **20 s**（不含写 Flash） |
| 角度判据 | `Angle ≤ 5` 或 `≥ 8186`（±约 1° 电角度） |

`RetryCount==0` 用 1.5 s，之后用 0.3 s。斜坡时间不算在 1.5 s 里。

### 标定「电流故障」怎么判

`FaultReason=1` **不是**「Id 没跟到 3 A」。1 ms 任务看到 `MotorFoc_ProtObs.fault.active` 且原因不是欠压，就记电流故障。真正门槛在 10 kHz 保护：

| `ProtObs.fault.reason` | 含义 | 默认 |
|---:|------|------|
| 3 | OC1 瞬时过流 | 任一相 \|I\| > 130 A |
| 2 | OC2 确认过流 | 任一相 \|I\| > 65 A 持续 20 s |
| 1 | 欠压 | `vdc < minVdcRunV`（默认 6 V）确认若干拍 |

Id 斜坡只比**指令**是否到目标（差 ≤ 0.02 A）。

---

## 6. 给 Id 时三相尖峰（开环 + 标定）

VOFA：使能瞬间蓝/紫相冲到十几安，随后才是约 3 A 幅值的三相波。电源被拉垮 → 欠压。

根因：**PWM 还没开，状态机已经把 Id 指令斜到目标（开环甚至已开始转角）**。门极一开，电流环误差 ≈ 3 A，PI 猛推电压。

**已改（`MotorCdd_Foc.c`）：**

- 开环：`OutputEnabled=0` 时不 `FastLoopStep`，`IdRef/IqRef` 清零。  
- 标定：输出关掉或还在启动 blanking（约 10 ms）时 `IdRefA=0`，只出中性占空比；blanking 结束后再从 0 斜坡。

斜坡再慢也挡不住「使能瞬间指令已经是 3 A」。

---

## 7. 母线欠压容易报（与斜坡无关）

三件事叠在一起：

1. `vinv` **原先无滤波**，PWM 边沿 VINV 单点可能掉到 6 V 以下。  
2. 欠压确认原 **20 拍 = 2 ms**，毛刺也能锁存。  
3. 锁存后 `OutputEnabled=0`，电流环不再跑，UV 自动恢复进不去；以前 **只在 IDLE 清 UV**，标定/开环会一直停着，再被记成电流故障。

**已改：**

- 母线约 **100 Hz** 一阶低通（`MotorCdd_Adc.c`）  
- 确认 **200 拍 = 20 ms**  
- **任意模式** 母线回到 `minVdc+0.5 V` 即清 UV  
- 标定遇到 UV **不中止**，只有过流才 `FAULT_CURRENT`

UDE：`MotorFoc_ProtObs.fault.vdcV`（锁存瞬间）、`vinv_V`（滤波后）。滤波后长期低于 6 V 才是电源真撑不住。

---

## 8. 关键文件

| 路径 | 本轮相关 |
|------|----------|
| `Appl/Source/CDD/UartTest.c` | 打包发送、禁止 WaitIdle |
| `Appl/Source/StartApp.c` | Core0 1 ms 只发 UART（WriteBlock 已迁回 Core1） |
| `Appl/Source/CDD/MotorFoc/MotorZeroCal.c/.h` | 标定、NvM、时序、UV 不中止标定 |
| `Appl/Source/CDD/MotorFoc/MotorCdd_Foc.c` | 开环/标定 Id 仅在输出使能后斜坡 |
| `Appl/Source/CDD/MotorFoc/MotorCdd_Adc.c` | 母线 LPF |
| `Appl/Source/CDD/MotorFoc/MotorFoc_CurrentLoop.c` | UV 确认 20 ms |
| `Appl/Source/MotorControll.c` | 任意模式恢复 UV |

---

## 9. 刷机后建议看的量

```text
Fee_StateVar.FeeInitGCState          // 要到 5
MotorZeroCal_DflashReadComplete      // 要到 1
MotorZeroCal_StartRejectReason       // 0 才能进标定
MotorZeroCal_IdRefA / IdRefTargetA
MotorZeroCal_Stage / RetryCount
MotorZeroCal_FaultReason             // 1电流 2对齐 3超时 4Flash
MotorFoc_ProtObs.fault.reason        // 1欠压 2/3过流
MotorFoc_ProtObs.fault.vdcV
UartTest_TxOkCount / DropCount / TxBusyCount
```

标定成功：`DflashValid=1`，`NvLastResult=0`，复位后再等读完成仍为 1。
