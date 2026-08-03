# 电流环 过流 / 欠压 保护设计说明（量产标准）

> 项目：last364（TC364 双核，10 kHz 电流环）
> 代码：`Appl/Source/CDD/MotorFoc/MotorFoc_CurrentLoop.c / .h`
> 更新：2026-08-03

## 1. 概述

电流环保护在每拍（10 kHz，100 µs）的 `MotorFoc_RunCurrentLoop()` 中执行，按固定顺序判定。设计目标：

- **过流两级保护**：瞬时硬跳闸（OC1，2×额定）+ 持续超限保护（OC2，默认持续 20 s），兼顾快速保护与抗误报。
- **欠压保护**：阈值 + 确认延时 + 迟滞恢复 + 可配置自动恢复，避免临界电压抖动导致反复报故障。
- **启动 blanking**：只屏蔽"确认式"检查，**瞬时过流永远生效**。
- **故障锁存策略**：过流锁存需显式清除；欠压按迟滞自动恢复（可关）。
- **诊断完备**：峰值电流、故障时刻运行计数、故障现场快照（电压/电流/dq/PWM）全部可观测。

## 2. 每拍判定流程

```
MotorFoc_RunCurrentLoop()           每 10 kHz 一拍
│
├─ 1. 显式清除请求 (FaultClearRequest) ?
│       是 ──► ClearFault()          // 上层/用户主动清故障
│
├─ 2. 已锁存故障 ?
│      ├─ 欠压 且 UvAutoRecover=1 ─► 母线 ≥ (跳闸阈值+迟滞) 连续 N 拍 ?
│      │       是 ──► ClearFault()   // 自动恢复，上层重新使能
│      │       否 ──► 保持关断
│      └─ 其他(过流) ────────────► 保持关断（必须显式清除）
│      ──► CurrentLoopStop(); return
│
├─ 3. 峰值电流统计（诊断用）
│
├─ 4. OC1 瞬时过流: |I| > InstantTripCurrentA (2×额定=130A)
│      ──► 立即锁存 FAULT_OVERCURRENT_INST（无确认、不受 blanking 影响）
│
├─ 5. 启动 blanking 中?（使能后前 StartupBlankingCount=100 拍）
│      ├─ 是 ──► 跳过 6/7 步，确认计数清零（OC1 仍生效）
│      └─ 否 ──►
│            ├─ 6. OC2 确认过流: |I| > MaxCurrentA (65A) 持续 20s
│            │        ──► 锁存 FAULT_OVERCURRENT
│            └─ 7. 欠压: vdc < MinVdcRunV (6V) 连续 20 拍 (2ms)
│                     ──► 锁存 FAULT_UNDERVOLT
│
└─ 正常电流环（Clarke/Park/PI/SVPWM/ApplyPwm）
```

## 3. 过流保护（两级）

### OC1 瞬时过流（硬跳闸）
- 判据：任一相原始电流（未滤波）绝对值 > `MotorFoc_ProtObs.cfg.instantTripCurrentA`（默认 2×额定 = 130A）。
- 特性：**一拍即跳，无确认延时**；启动 blanking 期间也生效。
- 用途：堵转、直通、短路等瞬时大电流的软件级快速响应。
- 量产提示：软件 100 µs 响应仍慢于硬件比较器，量产应叠加硬件级快速关断（TLE9180 故障输入/外部比较器），软件 OC1 作为第二道防线。

### OC2 持续过流（长时间超限才报错）
- 判据：任一相原始电流绝对值 > `MotorFoc_ProtObs.cfg.maxCurrentA`（默认 65A）**持续** `MotorFoc_ProtObs.cfg.overCurrentTripSec`（默认 20 秒）才锁存。
- 特性：瞬时尖峰（如停机给 iq=0 时的电流冲击）不触发；启动 blanking 期间被屏蔽。
- 用途：持续过载/堵转保护（I²t 热模型的简化替代，量产建议用热模型）。

### 过流故障恢复
- `overCurrentAutoRecover`=1（默认开）：三相电流回落到 `maxCurrentA - overCurrentRecoverHystA` 以下并持续 `overCurrentRecoverSec`（默认 1 s）后自动清除，上层重新使能。
- 置 0：锁存，必须显式清除（`MotorCdd_FocClearFault()` / 重新使能流程）。

## 4. 欠压保护（阈值 + 迟滞 + 自动恢复）

| 参数 | 默认 | 说明 |
|---|---|---|
| `MotorFoc_ProtObs.cfg.minVdcRunV` | 6.0 V | 跳闸阈值（母线低于此值开始计数） |
| `MotorFoc_ProtObs.cfg.undervoltConfirmCount` | 20 拍 (2 ms) | 低于阈值连续拍数后锁存 |
| `MotorFoc_ProtObs.cfg.vdcHysteresisV` | 1.0 V | 恢复阈值 = 跳闸阈值 + 迟滞（7V） |
| `MotorFoc_ProtObs.cfg.undervoltRecoverCount` | 50 拍 (5 ms) | 母线稳定高于恢复阈值的拍数 |
| `MotorFoc_ProtObs.cfg.uvAutoRecover` | 1（开） | 是否自动清除欠压故障 |

- 母线电压使用 ADC 实测值（`vinv_V`，上限 clamp 到 18V）。
- 恢复条件：`vdc ≥ MinVdcRunV + VdcHysteresisV` 连续 `UndervoltRecoverCount` 拍。迟滞防止在阈值附近来回跳。
- 自动恢复后，由上层（`MotorControll_ApplyOutputGating`）重新执行输出使能流程（`PrepareOutputEnable` 会重新挂起启动 blanking，实现软启动）。
- 若量产要求"欠压必须人工复位"，将 `UvAutoRecover` 置 0。

## 5. 启动 blanking

- 输出使能时 `MotorCdd_FocPrepareOutputEnable()` 调用 `MotorFoc_CurrentLoopArmStartupBlanking()`，挂起 `StartupBlankingLeft = 100`（10 ms）。
- blanking 期间：
  - OC1（瞬时过流）**始终生效**；
  - OC2/欠压的确认计数被保持为 0（不累计、不锁存），容忍使能瞬间的母线跌落与电流冲击。
- blanking 结束后的第一拍恢复全部保护。

## 6. 故障锁存与清除

| 故障 | 锁存 | 恢复方式 |
|---|---|---|
| `FAULT_OVERCURRENT_INST` (3) | 是 | autoRecover=1 时电流回落自动清除；否则显式清除 |
| `FAULT_OVERCURRENT` (2) | 是 | autoRecover=1 时电流回落自动清除；否则显式清除 |
| `FAULT_UNDERVOLT` (1) | 是 | `UvAutoRecover=1` 时母线恢复后自动清除，否则显式清除 |

`MotorFoc_CurrentLoopClearFault()` 同时复位：确认计数、恢复计数、峰值电流、故障现场快照。

## 7. 参数表（UDE 可调）

| 变量 | 默认 | 单位 | 含义 |
|---|---|---|---|
| `MotorFoc_ProtObs.cfg.instantTripCurrentA` | 130.0 | A | OC1 瞬时硬跳闸（2×额定） |
| `MotorFoc_ProtObs.cfg.maxCurrentA` | 65.0 | A | OC2 持续过流阈值 |
| `MotorFoc_ProtObs.cfg.overCurrentTripSec` | 20 | s | OC2 持续超限时间 |
| `MotorFoc_ProtObs.cfg.overCurrentRecoverSec` | 1 | s | OC 自动恢复保持时间 |
| `MotorFoc_ProtObs.cfg.overCurrentRecoverHystA` | 2 | A | OC 恢复迟滞（低于 max-hyst） |
| `MotorFoc_ProtObs.cfg.overCurrentAutoRecover` | 1 | - | OC 自动恢复开关 |
| `MotorFoc_ProtObs.cfg.minVdcRunV` | 6.0 | V | 欠压跳闸阈值 |
| `MotorFoc_ProtObs.cfg.undervoltConfirmCount` | 20 | 拍 | 欠压确认拍数（2 ms） |
| `MotorFoc_ProtObs.cfg.vdcHysteresisV` | 1.0 | V | 欠压恢复迟滞 |
| `MotorFoc_ProtObs.cfg.undervoltRecoverCount` | 50 | 拍 | 恢复确认拍数（5 ms） |
| `MotorFoc_ProtObs.cfg.uvAutoRecover` | 1 | - | 欠压自动恢复开关 |
| `MotorFoc_ProtObs.cfg.startupBlankingCount` | 100 | 拍 | 启动 blanking 长度（10 ms） |

## 8. 诊断变量（UDE 观察）

| 变量 | 说明 |
|---|---|
| `MotorFoc_ProtObs.fault.active` / `FaultReason` | 故障标志/原因（0/1/2/3） |
| `MotorFoc_ProtObs.fault.runCount` | 故障发生时刻的运行计数（10 kHz 拍号） |
| `MotorFoc_ProtObs.fault.iuA/IvA/IwA` | 故障时刻三相电流快照 |
| `MotorFoc_ProtObs.fault.vdcV` | 故障时刻母线电压 |
| `MotorFoc_ProtObs.fault.idA/IqA/VdV/VqV` | 故障时刻 dq 电流/电压 |
| `MotorFoc_ProtObs.fault.pwmU/V/W` | 故障时刻占空比 |
| `MotorFoc_ProtObs.peak.iuA/IvA/IwA` | 运行峰值电流（清除/使能时复位） |
| `MotorFoc_ProtObs.cnt.undervoltCounter` | 欠压确认计数（过程值） |
| `MotorFoc_ProtObs.cnt.uvRecoverCounter` | 欠压恢复计数（过程值） |
| `MotorFoc_ProtObs.cnt.overCurrentCounter` | OC2 持续超限累计拍数（过程值） |

## 9. 量产进一步建议

1. **硬件级过流快速关断**：外部比较器或 TLE9180 故障输入直接关断 PWM（µs 级），软件保护只做确认与记录。
2. **I²t / 热模型保护**：对持续过流叠加电机绕组热模型（`∫I²dt`），阈值随温升下降，量产电机保护标准做法。
3. **欠压分级**：UV1（降功率/限流，报警不跳闸）+ UV2（立即停机），本实现为单级，可按需扩展。
4. **故障码管理**：将 `FaultReason` 映射到 DTC/诊断服务（当前仅 UDE 可见）。
5. **使能前母线预检**：输出使能前确认母线稳定高于运行阈值（当前 `MotorControll` 已有部分检查）。

## 10. 验证清单

1. 上电未使能：`Fault=0`，`RunCount` 递增，峰值电流≈0。
2. 正常开环/闭环运行：无故障，`PeakI*` 记录运行峰值。
3. 母线跌落 < 6V 超过 2 ms：锁 `FAULT_UNDERVOLT`；母线回升 > 7V 持续 5 ms 自动恢复并重新使能。
4. 堵转/大电流 > 130A：一拍锁 `FAULT_OVERCURRENT_INST`（blanking 期间也锁）。
5. 持续 > 65A 达 20 s：锁 `FAULT_OVERCURRENT`；电流回落 < 63A 持续 1 s 自动恢复。
6. 故障后重新使能：输出经 neutral → blanking 软启动，无冲击。