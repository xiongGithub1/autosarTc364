# TLE9183 初始化流程说明

本文档按当前工程 `last364` 中的实际代码整理，重点说明 9183 初始化现在是 **周期 state machine**，不是启动阶段一次性阻塞初始化。

相关代码：

| 文件 | 作用 |
|---|---|
| `Appl/Source/StartApp.c` | 10ms 周期调用 9183/9180 MainFunction，1ms 执行 5012 采样 |
| `Appl/Source/CDD/TLE9180/Tle9183.c` | TLE9183 初始化状态机、SPI 读写、CRC3 |
| `Appl/Source/CDD/TLE9180/Tle9183.h` | TLE9183 状态、阶段、调试结构体定义 |
| `Appl/Source/TestFiles/tle9183_test.c` | 9183 测试/观测代码，不再推进初始化 |

## 1. 总体原则

CDD 驱动初始化推荐分两层：

| 阶段 | 放什么 | 不应该放什么 |
|---|---|---|
| `EcuM` / MCAL 初始化 | `Mcu_Init`、`Port_Init`、`Dio_Init`、`Spi_Init` 等底层模块初始化 | 外设芯片等待 ready、SPI 轮询配置 |
| `CDD_Init` / `StartApp_Init` | 软件变量清零、状态机置初值、测试模块 Init | `while` 等待、ms 级 delay、完整 SPI 初始化序列 |
| 周期 `MainFunction` | 按状态机一步一步推进硬件初始化 | 长时间阻塞、等待某个引脚到 timeout |

当前 9183 初始化放在：

```c
StartApp_Cyclic10ms()
{
  Tle9180_Driver_MainFunction();
  Tle9183_MainFunction();
}
```

也就是说：9183 每 10ms 推进一步，失败后等待 1s 再重试，不堵塞 1ms 任务。

## 2. 当前调用链

启动后大致调用关系：

```text
EcuM / BSW init
  -> Mcu / Port / Dio / Spi 等初始化完成

RTE start
  -> StartApp_Init()
       -> CanTest_Init()
       -> SpiTest_Init()
       -> Tle9183Test_Init()
       -> Tle5012Test_Init()
       -> AdcTest_Init()
       -> PwmTest_Init()

周期运行
  -> StartApp_Cyclic1ms()
       -> PwmTest_RunOnce()
       -> Tle5012Test_RunOnce()

  -> StartApp_Cyclic10ms()
       -> Tle9180_Driver_MainFunction()
       -> Tle9183_MainFunction()

  -> StartApp_Cyclic250ms()  // 实际配置注释里是 500ms
       -> SpiTest_RunOnce()
       -> Tle9183Test_RunOnce()
       -> AdcTest_RunOnce()
```

注意：`Tle9183Test_RunOnce()` 现在只读取 `Tle9183_Status` 并做 NOP 读测试，不再调用 `Tle9183_MainFunction()`，避免 250ms runnable 干扰初始化节拍。

## 3. TLE9183 状态机步骤

当前内部状态枚举在 `Tle9183.c`：

```c
typedef enum
{
  TLE9183_INIT_STEP_SLEEP_PINS = 0U,
  TLE9183_INIT_STEP_WAIT_SLEEP,
  TLE9183_INIT_STEP_WAKE_PINS,
  TLE9183_INIT_STEP_WAIT_WAKE,
  TLE9183_INIT_STEP_WAIT_ERR,
  TLE9183_INIT_STEP_CONFIGURE,
  TLE9183_INIT_STEP_DONE
} Tle9183_InitStepType;
```

流程如下：

```text
TLE9183_INIT_STEP_SLEEP_PINS
  -> INH = LOW, ENA = LOW, SOFF = LOW
  -> 记录当前 ms tick
  -> 进入 WAIT_SLEEP

TLE9183_INIT_STEP_WAIT_SLEEP
  -> 等待 >= 5ms
  -> 进入 WAKE_PINS

TLE9183_INIT_STEP_WAKE_PINS
  -> SOFF = HIGH, ENA = LOW, INH = HIGH
  -> 记录当前 ms tick
  -> 进入 WAIT_WAKE

TLE9183_INIT_STEP_WAIT_WAKE
  -> 等待 >= 5ms
  -> PowerUpDone = TRUE
  -> InitPhase = POWER_DONE
  -> 记录当前 ms tick
  -> 进入 WAIT_ERR

TLE9183_INIT_STEP_WAIT_ERR
  -> 读取 ERR 引脚
  -> ERR == HIGH: 进入 CONFIGURE
  -> 超过 20ms 仍不为 HIGH: InitPhase = ERR_TIMEOUT，等待 1s 重试

TLE9183_INIT_STEP_CONFIGURE
  -> SPI NOP pipeline flush
  -> 校验 MISO CRC3
  -> 写 conf_sig = 0xBA
  -> 再读 NOP，检查 Config Valid
  -> 成功后 State = CONFIGURED，InitPhase = CONFIG_DONE

TLE9183_INIT_STEP_DONE
  -> 初始化结束，后续 MainFunction 直接返回
```

## 4. 引脚控制

### 4.1 唤醒相关 DIO

| 信号 | 当前代码通道 | 初始化阶段作用 |
|---|---|---|
| `INH` | `DioConf_DioChannel_DioChannel_9183INH` | 低电平进入休眠，高电平唤醒 |
| `ENA` | `DioConf_DioChannel_DioChannel_9183ENA` | 初始化阶段保持低，避免输出提前使能 |
| `SOFF` | `DioConf_DioChannel_DioChannel_9183SOFF` | 初始化阶段先低后高，保持安全输出状态 |
| `ERR` | `DioConf_DioChannel_DioChannel_9183ERR` | 输入，等待芯片数字部分 ready |

### 4.2 当前代码的引脚动作

休眠阶段：

```c
INH  = LOW
ENA  = LOW
SOFF = LOW
```

唤醒阶段：

```c
SOFF = HIGH
ENA  = LOW
INH  = HIGH
```

## 5. SPI 初始化配置动作

进入 `TLE9183_INIT_STEP_CONFIGURE` 后执行 `Tle9183_ConfigureDefault()`。

主要动作：

1. 发送 NOP 读命令 `TLE9183_REG_NOP = 0x32`。
2. 因为 SPI 有 pipeline，当前 flush 次数是 `TLE9183_SPI_PIPELINE_FLUSH_CNT = 1`，循环 `0..1`，所以 NOP 读 2 次。
3. 每次解析 MISO，并检查 CRC3。
4. 如果 SPI 传输失败，置 `InitPhase = TLE9183_INIT_PHASE_SPI_HW_FAIL`。
5. 如果 CRC 错误，置 `InitPhase = TLE9183_INIT_PHASE_SPI_CRC_FAIL`。
6. NOP/CRC 通过后，置 `InitPhase = SPI_OK`，`State = IDLE_READY`。
7. 写 `conf_sig(0x00) = 0xBA`。
8. 再读一次 NOP，检查 MISO status 中的 Config Valid 位。
9. 如果 `LastCrcOk == TRUE` 且 Config Valid 置位，则：
   - `State = TLE9183_STATE_CONFIGURED`
   - `InitPhase = TLE9183_INIT_PHASE_CONFIG_DONE`

## 6. SPI 帧格式和 CRC

当前代码按 24 bit SPI 帧处理：

```text
MOSI:
bit20      : R/W，1=write，0=read
bit19..13  : address，7 bit
bit12..5   : data，8 bit
bit2..0    : CRC3
```

代码中生成 MOSI 的函数：

```c
static uint32 Tle9183_BuildMosiFrame(boolean isWrite, uint8 addr, uint8 data)
```

CRC3 函数：

```c
static uint8 Tle9183_CalcCrc3(uint32 data, uint8 numBits)
```

CRC 参数：

| 项 | 当前实现 |
|---|---|
| CRC 初值 | `0x4` |
| 多项式等效异或 | `0x3` |
| 计算位数 | 21 bit |
| 最终帧宽 | 24 bit |

## 7. 对外状态定义

### 7.1 `Tle9183_StateType`

| 枚举 | 含义 |
|---|---|
| `TLE9183_STATE_UNINIT` | 未完成初始化 |
| `TLE9183_STATE_IDLE_READY` | SPI 已通过基础检查，但 Config Valid 尚未确认 |
| `TLE9183_STATE_CONFIGURED` | 配置完成，可以认为 9183 初始化成功 |

### 7.2 `Tle9183_InitPhaseType`

| 枚举 | 含义 |
|---|---|
| `TLE9183_INIT_PHASE_NONE` | 未开始或准备重试 |
| `TLE9183_INIT_PHASE_POWER_DONE` | INH/SOFF 唤醒流程完成 |
| `TLE9183_INIT_PHASE_ERR_TIMEOUT` | ERR 等待超时 |
| `TLE9183_INIT_PHASE_SPI_HW_FAIL` | SPI Setup/Transmit/Sequence 失败 |
| `TLE9183_INIT_PHASE_SPI_CRC_FAIL` | SPI 收到数据但 CRC3 校验失败 |
| `TLE9183_INIT_PHASE_SPI_OK` | NOP 通信和 CRC 检查通过 |
| `TLE9183_INIT_PHASE_CONFIG_DONE` | `conf_sig = 0xBA` 写入并确认 Config Valid |

## 8. 失败重试策略

`Tle9183_MainFunction()` 中，如果检测到以下失败阶段：

```c
TLE9183_INIT_PHASE_ERR_TIMEOUT
TLE9183_INIT_PHASE_SPI_HW_FAIL
TLE9183_INIT_PHASE_SPI_CRC_FAIL
```

则不会立即反复重试，而是等待：

```c
TLE9183_RETRY_PERIOD_MS = 1000U
```

等待满 1s 后：

```text
InitStep  -> SLEEP_PINS
InitPhase -> NONE
```

然后从休眠/唤醒流程重新开始。

## 9. 调试时建议观察的变量

| 变量 | 正常现象 |
|---|---|
| `StartApp_Cyclic1msCounter` | 上电后应立即按 1ms 增长，不应等 78 次/几十秒后才正常 |
| `Tle9183_Status.State` | 最终应到 `TLE9183_STATE_CONFIGURED` |
| `Tle9183_Status.InitPhase` | 最终应到 `TLE9183_INIT_PHASE_CONFIG_DONE` |
| `Tle9183_Status.PowerUpDone` | 唤醒流程完成后为 1 |
| `Tle9183_Status.ErrPinLevel` | 9183 ready 后应为 1 |
| `Tle9183_Status.LastCrcOk` | SPI MISO CRC 正常时为 1 |
| `Tle9183_Status.LastTxFrame` | 最近一次 MOSI 帧 |
| `Tle9183_Status.LastRxFrame` | 最近一次 MISO 帧 |
| `Tle9183_Status.InitAttemptCounter` | 每次从 `SLEEP_PINS` 重新开始加 1 |
| `Tle9183_Status.SpiOkCounter` | SPI 成功次数，正常会增长 |
| `Tle9183_Status.SpiFailCounter` | SPI 失败次数，正常应保持不变或很少 |

## 10. 与之前问题的关系

之前出现“前面约 78 次后 1ms 才正常”的关键原因是：

1. RTE 当前把 `StartApp_Cyclic1ms`、`StartApp_Cyclic10ms`、`StartApp_Cyclic250ms` 放在同一个 `Default_Appl_Task` 里顺序执行。
2. 旧的 9183 初始化路径里有 busy-wait 和 timeout。
3. 当 250ms/500ms runnable 内部执行旧初始化时，会拖住同一个 task，导致 1ms runnable 也不能及时执行。

现在的处理方式是：

| 旧方式 | 新方式 |
|---|---|
| `Tle9183_MainFunction()` 里调用完整阻塞式 `Tle9183_Init()` | `Tle9183_MainFunction()` 每 10ms 只推进一个状态机步骤 |
| `Tle9183Test_RunOnce()` 推进初始化 | `Tle9183Test_RunOnce()` 只观测状态/做测试读 |
| 启动或 250ms runnable 可能阻塞 1ms | 初始化后台推进，减少对 1ms 的影响 |

## 11. 仍需注意的点

1. `Tle9183_ConfigureDefault()` 里仍然会一次执行多个同步 SPI 传输，但时间应远小于 ms 级 busy-wait。
2. `Tle9183_GetMsTick()` 依赖 `Mcal_DelayTickResolution()`，如果 tick 换算异常，状态机等待时间会不准确。
3. 9183 和 5012 如果共用 SPI 硬件或互相抢占，应继续通过 `Spi_GetStatus() == SPI_IDLE` 保护，避免同时访问。
4. 如果量产需要完整诊断，应在 `Tle9183_ConfigureDefault()` 后补充手册要求的错误寄存器读取和项目专用寄存器配置。

## 12. 当前成功判据

最低成功：

```text
Tle9183_Status.PowerUpDone == TRUE
Tle9183_Status.InitPhase == TLE9183_INIT_PHASE_SPI_OK
Tle9183_Status.State == TLE9183_STATE_IDLE_READY 或 CONFIGURED
```

完整成功：

```text
Tle9183_Status.State == TLE9183_STATE_CONFIGURED
Tle9183_Status.InitPhase == TLE9183_INIT_PHASE_CONFIG_DONE
Tle9183_Status.LastCrcOk == TRUE
```

同时确认：

```text
StartApp_Cyclic1msCounter 按 1ms 连续增长
Tle5012Test_Angle / RawVal 按 1ms 更新
```
