# FOC 电流闭环开环启动说明

## 目的

本实现用于无位置闭环参与的启动和台架调试。电流 PI 环、Clarke/Park 变换和 SVPWM 始终正常工作；所谓开环仅指 Park 变换使用软件生成的电角度，而不是编码器角度。

这样做可避免刚使能 PWM 就推进角度的启动冲击。转子会先被固定 d 轴磁场拉到已知方向，再以受控速度开始旋转。

## 启动流程

```text
进入 MOTOR_MODE_OPEN_LOOP
        |
        v
ALIGN_RAMP : 固定 AlignAngleDeg；Id 从 0 斜坡到 AlignCurrentA；Iq = 0
        |
        v
ALIGN_HOLD : 继续固定角度和 Id，保持 AlignHoldTicks
        |
        v
RAMP       : Id/Iq 平滑过渡至外部命令；电角度步长缓慢升至目标值
        |
        v
RUN        : 按 TargetAngleStep 和 StepDivider 持续推进电角度
```

每次从其他模式切入 `MOTOR_MODE_OPEN_LOOP` 都会调用 `MotorFoc_OpenLoop_Reset()`，因此必定从对齐阶段重新开始。停止 PWM、故障锁存或切换模式后重新启动，也会再次执行完整流程。

## 默认参数

默认 PWM/电流快速环为 10 kHz 时：

|变量|默认值|含义|
|---|---:|---|
|`MotorFoc_OpenLoop_AlignAngleDeg`|0 deg|对齐时强制使用的电角度|
|`MotorFoc_OpenLoop_AlignCurrentA`|1.0 A|对齐 d 轴电流；按电机额定电流和机械负载谨慎设置|
|`MotorFoc_OpenLoop_CurrentRampStepA`|0.002 A/tick|快速环中 Id/Iq 的最大变化量|
|`MotorFoc_OpenLoop_AlignHoldTicks`|3000|到达对齐电流后的保持时间，约 300 ms|
|`MotorFoc_OpenLoop_TargetAngleStep`|1|最终每次角度更新增加的表索引数|
|`MotorFoc_OpenLoop_StepDivider`|1|隔多少个快速环更新一次角度|
|`MotorFoc_OpenLoop_AccelerationTicks`|100|加 1 个角度步长前等待的快速环数，约 10 ms|
|`MotorFoc_OpenLoop_Direction`|0|0 正向，1 反向|

电角速度计算：

```text
ElectricalHz = TargetAngleStep * FastLoopHz / (8192 * StepDivider)
MechanicalRPM = ElectricalHz * 60 / PolePairs
```

例如 10 kHz、步长 1、分频 1 时，电角频率约为 1.22 Hz。若电机有 4 对极，则机械速度约为 18.3 rpm。

## UDE 推荐观察项

将以下变量加入 Time Value Chart，并缩放到启动开始后的 0.5 到 2 秒：

```text
MotorFoc_OpenLoop_Stage
MotorFoc_OpenLoop_IdRefOut
MotorFoc_OpenLoop_IqRefOut
MotorFoc_OpenLoop_ForcedAngleRad
MotorFoc_OpenLoop_ActiveAngleStep
MotorCdd_FocContext.idqMeas.real
MotorCdd_FocContext.idqMeas.imag
MotorCdd_FocContext.i_motor.vdc
MotorFoc_CurrentLoopFaultReason
```

预期现象：

1. `Stage` 依次为 0、1、2、3。
2. 阶段 0/1 中 `IqRefOut` 必须为 0，强制角度保持不变。
3. `IdRefOut` 先平滑到 `AlignCurrentA`；进入阶段 2 后再平滑趋近用户命令。
4. 阶段 2/3 中角度连续变化，`ActiveAngleStep` 逐步升高至目标值。

## 欠压故障处理

开环使能 PWM 前，控制层会先确认 `vinv_V >= MotorFoc_CurrentLoopMinVdcRunV + 1 V`。不满足时不会使能输出，而是递增 `MotorControll_OpenLoopBlockedCounter`。

已使能后，电流环仍保留原有的欠压确认计数和锁存保护。不要仅靠降低故障阈值掩盖问题。应在故障发生前后记录：

```text
MotorCdd_AdcPhysical.vinv_V
MotorCdd_FocContext.i_motor.vdc
MotorFoc_CurrentLoopUndervoltCounter
MotorFoc_CurrentLoopFaultVdcV
MotorFoc_CurrentLoopFaultReason
```

- 若 `vinv_V` 确实低于阈值：检查电源限流、母线电容、供电线束与接插件压降，并降低对齐电流或电流斜率。
- 若 `vinv_V` 保持正常却报欠压：检查 ADC 比例系数、ADC 采样触发时刻、母线分压电路与接地。
- 若 `Id/Iq` 在阶段 0/1 已严重抖动：先检查电流零偏、相电流极性、相序和 PWM-ADC 同步；不要继续增大对齐电流。

## 台架调试顺序

1. 断开机械负载或确保电机可安全转动，确认急停可用。
2. PWM 关闭时完成三相电流零偏采集。
3. 先将 `AlignCurrentA` 设为额定电流的约 10% 到 20%，从 1 A 以下开始验证。
4. 令 `IdRefCmd=0`、`IqRefCmd=0`，进入开环，确认仅完成对齐、无异常欠压或过流。
5. 将 `IqRefCmd` 从很小的正值开始，确认旋转方向；方向错误时先停止 PWM，再修改 `Direction` 或检查相序。
6. 缓慢增大 `TargetAngleStep` 或减小 `StepDivider`，每次只调整一个参数。
7. 开环稳定后，再进行编码器零位、闭环角度和速度环调试。

> 警告：开环角度与真实转子角度失步会迅速增加电流。任何参数修改都应在 PWM 关闭或电机停止后进行；不要在 UDE 中运行时突变对齐电流、方向或角度步长。