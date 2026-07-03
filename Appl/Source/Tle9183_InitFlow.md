# TLE9183QK 初始化流程说明（last364 / TC364）

本文档基于当前工程实现（`Tle9183.c` / `Tle9183.h`）及 Infineon TLE9183QK 数据手册 Figure 21，描述 **9183 从上电到 SPI 配置完成** 的完整流程。

---

## 1. 适用范围

| 项目 | 内容 |
|------|------|
| MCU | TC364 |
| 驱动芯片 | TLE9183QK |
| 通信接口 | QSPI3，24 bit MSB，CPOL=0/CPHA=0，100 kHz |
| 软件模块 | `Appl/Source/Tle9183.c`，`Tle9183.h` |
| 调用入口 | `StartApp_Init()` → `Tle9183_Init()`；周期重试 `Tle9183_MainFunction()` |

---

## 2. 前置条件（BSW / MCAL）

9183 初始化前，底层必须已就绪：

```
EcuM_AL_DriverInitOne():
  Mcu_Init()
  Mcu_InitClock()          ← QSPI 时钟源必须使能（非 DISABLED）
  Mcu_DistributePllClock()
  Port_Init()              ← GPIO + QSPI3 引脚复用
  Spi_Init()               ← QSPI3 Job/Channel 配置
```

**关键配置：**

| 层级 | 配置位置 | 说明 |
|------|----------|------|
| Mcu | `McuQspiClockSourceSelection` | 必须为有效时钟源（不能 `QSPI_CLOCK_SOURCE_DISABLED_SEL0`） |
| Port | P22.0/1/2/3 | MTSR / MRST / CSN / SCLK |
| Port | P0.2/4/12, P2.8 | SOFF / ERR / INH / ENA |
| Spi | `SpiExternalDevice_9183` | QSPI3，CHANNEL12，100 kHz，24 bit |

应用层 `StartApp_Init()` 在 RTE 启动后调用 `Tle9183_Init()`，此时 Port/Spi 已初始化完毕。

---

## 3. 硬件控制引脚

### 3.1 控制信号（Dio）

| 信号 | MCU 引脚 | Dio 通道 | 初始化中的作用 |
|------|----------|----------|----------------|
| INH | P0.12 | `DioChannel_9183INH` | 休眠拉低 / 唤醒拉高 |
| SOFF | P0.2 | `DioChannel_9183SOFF` | 关断 FET 控制 |
| ENA | P2.8 | `DioChannel_9183ENA` | 使能（唤醒阶段保持低） |
| ERR | P0.4 | `DioChannel_9183ERR` | 数字就绪指示（输入，无 MCU 上拉） |

### 3.2 SPI 信号（QSPI3）

| 信号 | MCU 引脚 | 说明 |
|------|----------|------|
| MOSI (MTSR) | P22.0 ALT3 | QSPI3 发送 |
| MISO (MRST) | P22.1 GPIO IN | MRIS=3 |
| CSN (SLSO12) | P22.2 ALT3 | 片选 |
| CLK_SPI | P22.3 ALT3 | 串行时钟 |

---

## 4. 初始化总流程

```
Tle9183_Init()
    │
    ├─ State == CONFIGURED ? ──是──► 直接返回
    │
    ├─ 阶段1: 硬件上电/唤醒 (ApplyPowerUpSequence)
    │
    ├─ 阶段2: 等待 ERR 拉高 (WaitErrHigh, 超时 20ms)
    │       └─ 失败 → InitPhase = ERR_TIMEOUT
    │
    ├─ 延时 500µs
    │
    └─ 阶段3: SPI 配置 (ConfigureDefault)
            ├─ 读 nop(0x32) ×2，校验 CRC3
            │     └─ 失败 → SPI_HW_FAIL / SPI_CRC_FAIL
            ├─ State = IDLE_READY, InitPhase = SPI_OK
            ├─ 写 conf_sig(0x00) = 0xBA
            ├─ 再读 nop(0x32)
            └─ Config Valid 置位 → State = CONFIGURED, InitPhase = CONFIG_DONE
```

对应数据手册 Figure 21 的 **简化实现**：包含上电、ERR 就绪、SPI 握手和配置签名；**未实现** 手册中 error 寄存器 0x42–0x4D 的完整轮询（可按量产需求扩展）。

---

## 5. 各阶段详细说明

### 5.1 调用与重试策略

- **首次调用**：`StartApp_Init()` → `Tle9183_Init()`
- **失败重试**：`Tle9183_MainFunction()`，间隔 **1 s**，直到 `State == CONFIGURED`
- **上电序列**：`PowerUpDone == TRUE` 后不再重复拉 INH 休眠，避免破坏 9183 状态

### 5.2 阶段 1：硬件上电 / 唤醒

函数：`Tle9183_ApplyPowerUpSequence()`

| 步骤 | INH | ENA | SOFF | 延时 |
|------|-----|-----|------|------|
| 1 休眠 | LOW | LOW | LOW | **≥ 5 ms** |
| 2 唤醒 | HIGH | LOW | HIGH | **≥ 5 ms** |

完成后：

- `PowerUpDone = 1`
- `InitPhase = TLE9183_INIT_PHASE_POWER_DONE`

**含义**：电荷泵/逻辑供电启动，FET 仍通过 SOFF/ENA 保持关断，仅唤醒数字与 SPI 接口。

### 5.3 阶段 2：等待 ERR 就绪

函数：`Tle9183_WaitErrHigh()`

| 项目 | 值 |
|------|-----|
| 监测引脚 | P0.4（ERR） |
| 期望电平 | **HIGH** |
| 超时 | **20 ms** |
| 成功后延时 | **500 µs** |

- 成功：ERR 表示数字核心就绪，可开始 SPI
- 失败：`InitPhase = TLE9183_INIT_PHASE_ERR_TIMEOUT`

### 5.4 阶段 3：SPI 通信与配置

函数：`Tle9183_ConfigureDefault()`

#### SPI 帧格式（24 bit，MSB 先发）

```
| Bit23..21 | Bit20      | Bit19..13 | Bit12..5 | Bit4..0 |
| 保留      | R/W (0=读) | 地址 7bit | 数据 8bit| CRC3    |
```

- **CRC3**：多项式 x³+x+1，种子 `0x4`（有效种子 100）
- 读 `nop(0x32)` 的 MOSI 帧：`0x00320003`

#### 管道刷新

- 读 `nop(0x32)` **2 次**（`TLE9183_SPI_PIPELINE_FLUSH_CNT = 1`，循环 0..1）
- 每次校验 MISO **CRC3**
- 失败分类：
  - `SPI_HW_FAIL`：`Spi_SyncTransmit` 失败
  - `SPI_CRC_FAIL`：收到数据但 CRC 错误

成功后：

- `InitPhase = TLE9183_INIT_PHASE_SPI_OK`
- `State = TLE9183_STATE_IDLE_READY`

#### 写入配置签名

| 寄存器 | 地址 | 写入值 | 说明 |
|--------|------|--------|------|
| `conf_sig` | `0x00` | `0xBA` | 默认配置签名（`TLE9183_CONF_SIG_DEFAULT`） |

#### 配置有效性确认

- 再次读 `nop(0x32)`
- 检查 MISO 状态字 **bit2（Config Valid，`TLE9183_SPI_STATUS_CONFIG_VALID`）**
- 若 `LastCrcOk == TRUE` 且 Config Valid = 1：
  - `State = TLE9183_STATE_CONFIGURED`
  - `InitPhase = TLE9183_INIT_PHASE_CONFIG_DONE`

---

## 6. 状态机定义

### 6.1 运行状态（`State`）

| 值 | 枚举 | 含义 |
|----|------|------|
| 0 | `TLE9183_STATE_UNINIT` | 未完成初始化 |
| 1 | `TLE9183_STATE_IDLE_READY` | SPI 已通，尚未确认 Config Valid |
| 2 | `TLE9183_STATE_CONFIGURED` | 配置完成，可正常运行 |

### 6.2 初始化阶段（`InitPhase`）

| 值 | 枚举 | 含义 |
|----|------|------|
| 0 | `TLE9183_INIT_PHASE_NONE` | 未开始 |
| 1 | `TLE9183_INIT_PHASE_POWER_DONE` | 上电序列完成 |
| 2 | `TLE9183_INIT_PHASE_ERR_TIMEOUT` | ERR 超时未拉高 |
| 3 | `TLE9183_INIT_PHASE_SPI_HW_FAIL` | SPI 硬件传输失败 |
| 4 | `TLE9183_INIT_PHASE_SPI_CRC_FAIL` | SPI CRC 校验失败 |
| 5 | `TLE9183_INIT_PHASE_SPI_OK` | SPI 通信正常 |
| 6 | `TLE9183_INIT_PHASE_CONFIG_DONE` | 配置签名写入并确认 |

---

## 7. 初始化成功判据（调试验证）

| 变量 | 成功值 | 说明 |
|------|--------|------|
| `State` | `IDLE_READY` 或 `CONFIGURED` | 基本 / 完全成功 |
| `InitPhase` | `SPI_OK` 或 `CONFIG_DONE` | SPI / 配置完成 |
| `PowerUpDone` | `1` | 上电完成 |
| `ErrPinLevel` | `1` | ERR 就绪 |
| `LastCrcOk` | `1` | 最后一帧 CRC 正确 |
| `LastTxFrame` | `0x00320003` | nop 读命令 |
| `LastRxFrame` | 非 0，CRC 合法 | 有效 MISO 回读 |
| `SpiOkCounter` | 持续增加 | SPI 成功计数 |
| `SpiFailCounter` | `0` | 无失败 |

API 判断：

```c
Tle9183_GetState() != TLE9183_STATE_UNINIT        /* 基本成功 */
Tle9183_GetState() == TLE9183_STATE_CONFIGURED    /* 完全成功（含 Config Valid） */
```

---

## 8. 软件接口说明

| 接口 | 功能 |
|------|------|
| `Tle9183_Init()` | 执行完整初始化（可重复调用） |
| `Tle9183_MainFunction()` | 1 s 周期重试，直至 `CONFIGURED` |
| `Tle9183_ReadRegister(addr, &data)` | 读寄存器 |
| `Tle9183_WriteRegister(addr, data)` | 写寄存器 |
| `Tle9183_GetState()` | 查询当前状态 |
| `Tle9183_Status` | 调试状态结构体（Watch 用） |

---

## 9. 与数据手册的差异（后续可扩展）

当前实现为 **最小可用初始化**，以下内容手册 Figure 21 有要求但 **尚未在代码中实现**：

1. 唤醒后读 error 寄存器 **0x42–0x4D** 并确认无致命错误
2. 更完整的 supervision / watchdog 配置
3. 应用相关的 IHx/ILx、PWM、电流采样等寄存器配置

量产前建议对照 TLE9183 User Manual 寄存器表，在 `Tle9183_ConfigureDefault()` 之后增加项目专用配置。

---

## 10. 时序概览

| 时刻 | 动作 |
|------|------|
| t = 0 | Port/Spi 已由 EcuM 初始化；`Tle9183_Init()` 开始 |
| t = 0 | INH/ENA/SOFF = 休眠态，等待 5 ms |
| t = 5 ms | SOFF=H, INH=H, ENA=L，等待 5 ms |
| t = 10 ms | 轮询 ERR（最多 20 ms） |
| t = 10~30 ms | ERR 变高，等待 500 µs |
| t ≈ 30 ms | SPI 读 nop ×2，CRC 校验 |
| t ≈ 30 ms | 写 conf_sig = 0xBA |
| t ≈ 30 ms | 再读 nop，检查 Config Valid |
| t ≈ 30 ms | 初始化完成 → `IDLE_READY` / `CONFIGURED` |

---

## 11. 相关源文件与配置索引

| 文件 | 内容 |
|------|------|
| `Appl/Source/Tle9183.c` | 初始化与 SPI 实现 |
| `Appl/Source/Tle9183.h` | API 与状态定义 |
| `Appl/Source/StartApp.c` | 调用 `Tle9183_Init()` / 周期测试 |
| `Appl/Source/EcuM_Callout_Stubs.c` | Mcu/Port/Spi 初始化顺序 |
| `Config/ECUC/last364_Mcu_Mcu_ecuc.arxml` | QSPI 时钟（`McuQspiClockSourceSelection`） |
| `Config/ECUC/last364_Spi_Spi_ecuc.arxml` | SPI 波特率/模式（`SpiExternalDevice_9183`） |
| `Config/ECUC/last364_Port_Port_ecuc.arxml` | 引脚配置 |
| `infineon-tle9183qk-datasheet-en.pdf` | 芯片数据手册（Figure 21 上电流程） |

---

## 12. 修订记录

| 日期 | 说明 |
|------|------|
| 2026-07-03 | 初版：基于 last364 工程 `Tle9183` 驱动及台架验证通过状态编写 |
