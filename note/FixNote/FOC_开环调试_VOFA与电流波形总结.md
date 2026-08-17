# FOC 开环调试总结（VOFA / 电流环 / 角度）

> 工程：`last364`（TC364 AUTOSAR）  
> 对照参考：`upperComputer` PMSM FOC  
> 观测工具：VOFA+ JustFloat（ASCLIN0 UART）+ UDE  

本文汇总本轮开环 FOC 台架调试结论、已落地改动与后续建议。

---

## 1. 目标与现象

| 目标 | 说明 |
|------|------|
| UART 波形 | 用 VOFA 看三相电流、马鞍波（SVPWM `Tcmp`）、电角度 |
| 开环运行 | 强制电角度 + 电流 PI（非纯电压 VF） |
| 调速 | UDE 可改目标机械转速 |

| 现象 | 结论 |
|------|------|
| 马鞍波绕 ~2500 摆 | 正常（`Tpwm/4` 中性点，`pwm_Out` 半周期比较值） |
| 低速电流毛、偏负、非正弦 | 死区/低调制 + 采样零偏 + 开环跟角不稳，滤波只能削高频 |
| 高速比低速好看 | 反电动势与惯量变大，畸变占比下降，属预期 |
| 10 rpm 角度：强制角直、5012 鼓包 | 强制角理想匀速；5012 是真实转子（齿槽顿挫） |
| 100 rpm 角度贴合更好 | 惯量抹平顿挫 |

---

## 2. VOFA / UART 通道约定

文件：`Appl/Source/CDD/UartTest.c`  

- 协议：JustFloat（`float32` LE + 帧尾 `00 00 80 7F`）  
- 采集：Core1 FOC 拍入环形缓冲  
- 发送：Core0 `StartApp_Cyclic1ms` 尽量发不同采样（勿在 Core1 直接 `Uart_Write`）  

| 通道 | 变量 | VOFA 页建议 |
|------|------|-------------|
| f0 | `i_motor.u` | **三相电流** 只绑 f0–f2 |
| f1 | `i_motor.v` | |
| f2 | `i_motor.w` | |
| f3 | `pwm_OutU` | **马鞍波** 只绑 f3–f5（中心约 2500） |
| f4 | `pwm_OutV` | |
| f5 | `pwm_OutW` | |
| f6 | FOC 运行电角度 `angle.angleRaw`（0..8192） | **角度** |
| f7 | TLE5012 电角度 `Tle5012bd_Sensor.Angle`（0..8192） | **角度** |

注意：

- Y 轴在 2000～3500 却标成「三相电流」→ 实际画的是马鞍波，通道绑错。  
- 波特率建议 ≤ **1.152M**（CH340 在 4M/8M 易失败；MCU 侧 `TxOkCount` 仍可能涨）。  
- 横轴缩到 **200～500 ms** 再判平滑度。

---

## 3. 开环控制要点

文件：`MotorFoc_OpenLoop.c` / `.h`，入口 `MotorCdd_FocFastLoop`  

开环含义：**仅电角度强制**；Clarke / Park / dq 电流 PI / SVPWM **始终运行**。  

阶段：`ALIGN_RAMP → ALIGN_HOLD → RAMP → RUN`  

### 3.1 UDE 调速

| 变量 | 作用 |
|------|------|
| `MotorFoc_OpenLoop_TargetRpmCmd` | 目标机械转速 (rpm)；`>0` 时换算 `TargetAngleStep` |
| `MotorFoc_OpenLoop_EstRpm` | 由当前角度步长估算的转速（只读） |
| `MotorFoc_OpenLoop_Direction` | 0 正转 / 1 反转 |
| `MotorFoc_OpenLoop_TargetAngleStep` | 角度表步长（`TargetRpmCmd=0` 时可手改） |
| `MotorFoc_OpenLoop_StepDivider` | 分频（默认 1） |

换算（10 kHz、8192 表、**4 对极**）：

```text
ElectricalHz = TargetAngleStep * 10000 / (8192 * StepDivider)
MechanicalRPM = ElectricalHz * 60 / PolePairs
≈ TargetAngleStep * 18.3   （StepDivider=1）
```

例：750 rpm ≈ step 41；100 rpm ≈ step 5～6。

RUN 阶段也可跟 `TargetRpmCmd` 升降速（按 `AccelerationTicks` 斜坡）。

### 3.2 电流指令建议

| 工况 | 建议 |
|------|------|
| 对齐 | `AlignCurrentA` 从小电流开始（如 ≤1 A） |
| 低速开环 | **给一定 `Iq`（如 1～2 A）**，不要长期 `Id` 大、`Iq=0` |
| 低速角线鼓包 | 先加 `Iq` 压齿槽，再谈零点/闭环 |

---

## 4. 已落地硬件 / 算法修正

### 4.1 ATOM W 相同步更新（必留）

- 问题：AGC `UPEN` 原先只使能 CH1/CH2，**CH3（W）影子寄存器未同步**。  
- 修复：`MOTORFOC_PWM_ATOM_UPEN_*` 同时覆盖 CH1/2/3。  
- 文件：`MotorFoc_CurrentLoop.c`

### 4.2 PWM 占空比映射（勿照搬 upperComputer）

| 工程 | PWM | 映射 |
|------|-----|------|
| upperComputer | 边沿对齐 | `SR1=Tcmp`, 脉宽 ≈ `Tpwm-2*Tcmp` |
| last364 | MCAL **中心对齐** Period=10000 | **`ScaledDuty = 2 * pwm_Out`** |

曾误用参考的取反公式 → 电流到几十安、PWM 尖刺 → **已改回** `duty = 2*pwm_Out`。

### 4.3 SVPWM 扇区滞回

- 低速电流噪声导致扇区 `N` 单拍翻转 → `Tcmp` 单点尖刺。  
- 对 `sA/sB/sC` 符号比较加滞回；观测变量 `MotorFoc_SvpwmSector`。  

### 4.4 电流采样

文件：`MotorCdd_Adc.c`

| 项 | 现状 |
|----|------|
| 第三相重构 | 默认 `MotorCdd_AdcReconstructEnable=1`，`Phase=2` → **`iw = -(iu+iv)`**（U/V 在 G0/G2 同步组） |
| 共模剔除 | 重构开启时跳过（和已强制为 0） |
| 一阶 LPF | `y += α(x−y)`，`α = 2π·fc·Ts/(1+2π·fc·Ts)` |
| 默认 α | **0.6110** → `fc = fs/4 = 2500 Hz` @ 10 kHz |
| 可选 α | **0.6768** → `fc ≈ fs/3`（UDE 改 `MotorCdd_AdcCurrentFilterAlpha`） |

说明：此前误用 `α=0.1116`（≈400 Hz）过重；滤波**消不掉**死区造成的低频畸变。

### 4.5 电流环带宽

文件：`MotorFoc_Config.c`

- `rs/lm`：保持 last364 电机参数（勿盲目抄 upperComputer）。  
- `w_i_dq`：约 **400 Hz**（`2513.2741`），在跟踪与毛刺间折中。  
- PI：`P = w·Lm`，`I = w·Rs`，`DisTimer = 100 µs`。

### 4.6 开环读 5012

- 原先开环跳过每拍 SPI → f7 不更新。  
- 现：**开环也读 5012**（擦除/保存标定仍跳过），便于 f6/f7 对比。  

### 4.7 曾试失败、已回退（勿再盲目启用）

| 尝试 | 结果 |
|------|------|
| RAMP/RUN 改电压开环（固定 Vd/Vq） | 更差 → 已回退电流开环 |
| 照搬 upperComputer 占空比取反 | 失稳 → 已回退 |
| 照搬 upperComputer `rs/lm` | 不适配 → 已回退 |

---

## 5. 低速差 / 高速好 — 原因清单

1. **死区与逆变器非线性**：低调制时占比大 → 电流肩膀、锯齿。  
2. **开环强制角 vs 转子**：低速齿槽使 5012 锯齿鼓包；高速惯量抹平。  
3. **电流环仍在出压**：`pwm_Out` 会叠 PI 对噪声的响应，马鞍波不会像纯 VF 那样丝滑。  
4. **VOFA 绑错通道 / 抽点过稀**：会放大“很毛”的观感。  
5. **滤波**：只压开关频附近毛刺，不解决死区与失步。

---

## 6. 推荐台架步骤（简版）

1. PWM 关闭完成电流零偏。  
2. 进 `MOTOR_MODE_OPEN_LOOP`，确认 ALIGN 完成。  
3. UDE：`TargetRpmCmd` 从 50～100 起，`Iq` 给 1～2 A。  
4. VOFA：电流看 f0–f2；马鞍看 f3–f5；角度叠 f6/f7。  
5. 低速先看 **f6 是否笔直**：笔直则强制角 OK；f7 鼓包先加 Iq。  
6. 开环稳定后再做零点标定与闭环切换。  

相关文档：`note/Guides/FOC_OpenLoop_Startup.md`

---

## 7. 关键文件索引

| 路径 | 内容 |
|------|------|
| `Appl/Source/CDD/UartTest.c` | VOFA JustFloat |
| `Appl/Source/CDD/MotorFoc/MotorCdd_Adc.c` | 采样、滤波、第三相重构 |
| `Appl/Source/CDD/MotorFoc/MotorFoc_CurrentLoop.c` | FOC / SVPWM / ATOM |
| `Appl/Source/CDD/MotorFoc/MotorFoc_OpenLoop.c` | 开环状态机与 RPM 调速 |
| `Appl/Source/CDD/MotorFoc/MotorFoc_Config.c` | `rs/lm/w_i_dq` |
| `Appl/Source/CDD/MotorFoc/MotorCdd_Foc.c` | 快环调度、5012 SPI |

---

## 8. 后续可做（未做）

- 死区补偿（改善低速电流正弦度）  
- 闭环电流/速度模式验证（用 5012 角进 Park）  
- ADC 采样点相对中心对齐的再标定（高调制时避开开关沿）  
- 按实测槽极数细化齿槽与低速 Iq 策略  

---

*文档根据本轮台架与代码改动整理，便于后续接着调死区与闭环。*
