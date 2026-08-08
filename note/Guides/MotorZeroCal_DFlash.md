# 电机零点标定与 DFlash 持久化

## 功能

零点标定把转子吸到固定电角度，读取 TLE5012 角度并修正 `MOD_3.ANG_BASE`。成功后会将下列内容作为同一个 4 字节 NvM/Fee 数据块写入 DFlash：

```text
magic = 0xA5A4   // 持久化的“零点标定有效”标志
angBase          // TLE5012 MOD_3.ANG_BASE
```

该 NvM 块已有 CRC16 保护，配置块名为 `NvMBlock_MotorZeroCal`，长度保持 4 字节，未修改生成配置。

## 上电行为

1. `MotorZeroCal_Init()` 将 `MotorZeroCal_DflashReadComplete` 清零。
2. Fee 初始化完成并空闲后，1 ms 任务请求 `NvM_ReadBlock()`。
3. 读取完成：
   - `magic` 正确：`MotorZeroCal_DflashValid=1`，恢复 `ANG_BASE`，并延迟写入传感器。
   - `magic` 错误、CRC/读取失败：`MotorZeroCal_DflashValid=0`，认为必须重新标定。
4. `MotorZeroCal_IsCalibrationRequired()` 返回 1，代表“已完成 DFlash 读取且记录无效”。应用可据此提示需要标定；不会自动转动电机。

在 `MotorZeroCal_DflashReadComplete=0` 前发起标定会被拒绝，拒绝码为 `MOTORZEROCAL_START_REJECT_NVM_NOT_READY`。

## 标定状态

`MotorZeroCal_State` 表示粗状态，`MotorZeroCal_Stage` 用于 UDE 观察细节：

|Stage|含义|
|---:|---|
|0|IDLE|
|1|ALIGN_RAMP：Id 从 0 斜坡至对齐电流|
|2|ALIGN_HOLD：固定电角度，等待转子稳定|
|3|READ_ANGLE：读取当前传感器角度|
|4|APPLY_OFFSET：修改 ANG_BASE 后等待复核|
|5|SAVE_DFLASH：PWM 已关闭，等待 NvM/Fee 写入|
|6|COMPLETE：NvM 返回成功|
|7|FAULT：电流、角度、Flash 或总超时故障|

## 时间和默认参数

- 对齐电流默认 `1.0 A`；先确认安全后再增加。
- 初次对齐保持 `1.5 s`；每次重试保持 `200 ms`。
- 最大重试 10 次。
- `MotorZeroCal_ElapsedMs` 从标定开始到 DFlash 写入结束只使用一个总时间预算：`8 s`。
- 超过 8 秒会停止并置 `MOTORZEROCAL_FAULT_TIMEOUT`；不会无限等待 Flash。

## 成功、失败与擦除

- 成功：先把新 `ANG_BASE` 和有效标志放进 RAM 镜像，关闭 PWM 后由 StartApp 1 ms 异步调用 `NvM_WriteBlock()`；只有 NvM 返回 `NVM_REQ_OK` 才进入 COMPLETE。
- 写 Flash 失败：当前会话保留 RAM 内标定结果，但 DFlash 不视为更新成功；下次上电按旧记录/无效记录处理。
- 擦除：`MOTOR_MODE_CALIBRATION_ERASE` 将 `ANG_BASE=0` 和有效标志=0 写入 DFlash。重启后 `MotorZeroCal_IsCalibrationRequired()` 应返回 1。

## UDE 建议观察项

```text
MotorZeroCal_DflashReadComplete
MotorZeroCal_DflashValid
MotorZeroCal_Stage
MotorZeroCal_ElapsedMs
MotorZeroCal_IdRefA
MotorZeroCal_RetryCount
MotorZeroCal_AngBase
MotorZeroCal_NvWritePending
MotorZeroCal_NvLastResult
MotorZeroCal_FaultReason
```

正常标定的最后状态应为：`DflashValid=1`、`NvWritePending=0`、`NvLastResult=NVM_REQ_OK`，随后重启并等待读取完成后仍保持 `DflashValid=1`。