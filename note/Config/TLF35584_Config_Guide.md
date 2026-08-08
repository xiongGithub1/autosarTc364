# TLF35584 配置与排障指南（last364）

> 工程：`last364.dpa`（AURIX TC364 + Vector MICROSAR 4.2.2 + Infineon MCAL 20.10.0）
> 芯片手册：`infineon-tlf35584-datasheet-en.pdf`（第 13 章 SPI）
> 相关模块：`Port` · `Spi` · `Sbc` · `ResourceM` · `BswM` · `EcuM`
> 从属：[DaVinci_Sbc.md](DaVinci_Modules/DaVinci_Sbc.md) · [DaVinci_Spi.md](DaVinci_Modules/DaVinci_Spi.md) · [Sbc_30_Tlf35584_Fix.md../FixNote/Sbc_30_Tlf35584_Fix.md)

---

## 1. 概述

TLF35584 是本板的 **PMIC（电源管理）**，通过 **QSPI1** 与 TC364 通信。Vector 驱动为 `Sbc_30_Tlf35584`（Complex Driver，DET ModuleId = **255**）。

上电后驱动会依次完成：

1. SPI 缓冲区 Setup
2. **PROTCFG 解锁**（写 0xAB / 0xEF / 0x56 / 0x12）
3. 写受保护寄存器（SYSPCFG、WDCFG 等）并重新加锁
4. 写 **DEVCTRL / DEVCTRLN** 进入 **NORMAL** 状态

任一步 SPI 通信失败，会报 **`SBC_E_INITIALIZATION_FAILED (0x14)`**。

📷 **图片位 P1**：板级 Power 原理图 TLF35584 部分（SCS/SCL/SDI/SDO 与 MCU 连接）

<!-- 在此插入图片，建议路径：../image/TLF35584_Config_Guide/01_power_schematic.png -->

---

## 2. 硬件引脚（Port + QSPI1）

| Port 容器名 | MCU 引脚 | 方向 | Port 模式 | TLF35584 信号 | QSPI1 功能 |
| --- | --- | --- | --- | --- | --- |
| `PortPin_tle35584_CSN` | **P11.2** | OUT | ALT4 | SCS | SLSO5（CS） |
| `PortPin_tle35584_Clk` | **P11.6** | OUT | ALT3 | SCL | SCLK |
| `PortPin_tle35584_MTSR` | **P11.9** | OUT | ALT3 | SDI（MOSI） | MTSR |
| `PortPin_tle35584_MRST` | **P11.3** | IN | ALL / GPIO | SDO（MISO） | MRST（由 Spi 硬件选路） |

**Spi 硬件 MRST 选路**（`SpiHwConfigurationQspi_35584`）：

| 参数 | 值 |
| --- | --- |
| `SpiHwConfigKernel` | QSPI1 |
| `SpiHWPinMRSTQspix` | `MRST1B_PORT11_PIN3` |

📷 **图片位 P2**：DaVinci Port 模块中 35584 四根 SPI 脚配置截图

<!-- ../image/TLF35584_Config_Guide/02_port_pins.png -->

📷 **图片位 P3**：原理图 / TC36x User Manual 中 P11.2 / P11.6 / P11.9 / P11.3 复用功能对照

<!-- ../image/TLF35584_Config_Guide/03_pin_mux_table.png -->

---

## 3. SPI 配置（关键）

### 3.1 手册要求（第 13 章）

| 项目 | TLF35584 要求 |
| --- | --- |
| 帧长 | **16 bit**（SCS 低期间必须正好 **16** 个 SCLK） |
| 位序 | **MSB 先发**（CMD → A5..A0 → D7..D0 → Parity） |
| 时钟空闲 | **低电平** |
| 采样/移出 | SDI **上升沿采样**，**下降沿移出**（SPI Mode 0） |
| 最大速率 | NORMAL 态约 **5 MHz**（bring-up 建议先用 **1 MHz**） |

16 bit 帧格式（与 Vector 驱动 `Sbc_Ll_MkWrCommand` 一致）：

```text
Bit15 .. Bit0（MSB 先发）:
  [15] CMD (写=1, 读=0)
  [14:9] 地址 A5..A0
  [8:1]  数据 D7..D0
  [0]    Parity（驱动内 Sbc_Ll_CalcSpiParity 计算）
```

📷 **图片位 P4**：手册 Figure 74「SPI frame in normal mode」截图

<!-- ../image/TLF35584_Config_Guide/04_datasheet_spi_frame.png -->

### 3.2 DaVinci 正确参数（`SpiChannel_35584` / `SpiExternalDevice_35584`）

| 对象 | 参数 | **正确值** | 常见错误 |
| --- | --- | --- | --- |
| `SpiChannel_35584` | `SpiDataWidth` | **16** | 32（旧配置） |
| `SpiChannel_35584` | `SpiTransferStart` | **MSB** | LSB |
| `SpiChannel_35584` | `SpiChannelType` | EB | — |
| `SpiExternalDevice_35584` | `SpiHwUnit` | QSPI1 | — |
| `SpiExternalDevice_35584` | `SpiCsIdentifier` | **CHANNEL5** | 与 P11.2 SLSO5 不一致 |
| `SpiExternalDevice_35584` | `SpiCsPolarity` | LOW | — |
| `SpiExternalDevice_35584` | `SpiShiftClockIdleLevel` | **LOW** | HIGH |
| `SpiExternalDevice_35584` | `SpiDataShiftEdge` | **TRAILING** | LEADING |
| `SpiExternalDevice_35584` | `SpiBaudrate` | 1000000 | 过高导致首板不稳定 |
| `SpiExternalDevice_35584` | `SpiCsSelection` | CS_VIA_PERIPHERAL_ENGINE | — |
| `SpiJob_35584` | 模式 | SYNCHRONOUS | — |
| `SpiSequence_35584` | 挂接 | `SpiJob_35584` | — |

📷 **图片位 P5**：`SpiChannel_35584`（DataWidth=16, TransferStart=MSB）

<!-- ../image/TLF35584_Config_Guide/05_spi_channel.png -->

📷 **图片位 P6**：`SpiExternalDevice_35584`（TRAILING, Idle=LOW, 1MHz, CHANNEL5）

<!-- ../image/TLF35584_Config_Guide/06_spi_external_device.png -->

📷 **图片位 P7**：`SpiJob_35584` / `SpiSequence_35584` / `SpiHwConfigurationQspi_35584`

<!-- ../image/TLF35584_Config_Guide/07_spi_job_sequence_hw.png -->

### 3.3 Generate 后 GenData 自检

重新 Generate + 全量编译后，检查 `Appl/GenData/src/Spi_PBcfg.c`：

| 检查项 | 正确表现 | 错误表现 |
| --- | --- | --- |
| Channel 编码 | `0x90U`（MSB + 16bit） | `0x10U`（LSB + 16bit）或 `0xA0U`（32bit LSB） |
| Job CPH/CPOL | `(0x00U), (0x00U)` | `(0x01U), (0x00U)`（Mode 1，与手册不符） |

```c
/* 正确示例 */
0x90U,   /* MSB[7], DataWidth=16[6:0] */
(0x00U), (0x00U),  /* CPH , CPOL  → Mode 0 */
```

---

## 4. Sbc 模块配置

DaVinci 路径：`Sbc`（`Sbc_30_Tlf35584`）。

| 参数 | 值 |
| --- | --- |
| `SbcSpiChannelRef` | `SpiChannel_35584` |
| `SbcSpiSequenceRef` | `SpiSequence_35584` |
| `SbcErrPinMonitor` | true（若板级接 ERR） |
| `NumberOfWdg` | 0（初始化阶段关闭看门狗） |
| 上电输出 | LDO_Stby / Tracker1/2 / LDO_Com / VoltRef 等按板级需求使能 |

当前生成值（`Sbc_30_Tlf35584_Lcfg.c` 摘录）：

| 配置项 | 值 | 说明 |
| --- | --- | --- |
| `DEVCTRLnormal` | `0xE8` | NORMAL 态电源输出 |
| `SYSPCFG0normal` | `0x01` | LDO_Stby 等 |
| `SYSPCFG1` | `0x08` | ErrPin 监控相关 |

📷 **图片位 P8**：Sbc 模块 SPI 引用与 Supply 配置截图

<!-- ../image/TLF35584_Config_Guide/08_sbc_module.png -->

---

## 5. 初始化顺序

必须保证 **Spi 先于 Sbc** 完成初始化：

```text
EcuM_AL_DriverInitOne (Core0)
  ├─ Mcu_Init / Port_Init / ...
  ├─ IrqSpi_Init
  └─ Spi_Init(&Spi_Config)          ← 必须先于 Sbc

BswM 初始化动作
  ├─ Uart_Init(...)
  └─ Sbc_30_Tlf35584_Init(...)      ← 依赖 Spi
```

📷 **图片位 P9**：BswM Action List 中 Init 顺序截图（Spi 在 Sbc 之前）

<!-- ../image/TLF35584_Config_Guide/09_bswm_init_order.png -->

**ResourceM**：QSPI1 / `SpiHwConfigurationQspi_35584` 归属 **Core0**。

---

## 6. 编译兼容补丁（重生成后必查）

详见 [Sbc_30_Tlf35584_Fix.md../FixNote/Sbc_30_Tlf35584_Fix.md)。摘要：

| 文件 | 补丁内容 |
| --- | --- |
| `BSW364/_Common/Implementation/_MemMap.h` | 补充 `SBC_30_TLF35584_*` 段映射 |
| `BSW364/_Common/Implementation/_Compiler_Cfg.h` | 补充 `SBC_30_TLF35584_CONST/CODE/VAR_*` |
| `BSW364/Sbc_30_Tlf35584/Implementation/Sbc_30_Tlf35584.c` | `Sbc_SpiDataType` → `Spi_DataBufferType` |

---

## 7. 故障现象与排查

### 7.1 DET：`ModuleId=255, ErrorId=0x14`

| 字段 | 含义 |
| --- | --- |
| ModuleId **255** | Complex Driver（`Sbc_30_Tlf35584`） |
| ErrorId **0x14** | `SBC_E_INITIALIZATION_FAILED` |

📷 **图片位 P10**：调试器 DET 报错窗口截图

<!-- ../image/TLF35584_Config_Guide/10_det_error_0x14.png -->

**驱动内失败点**（`Sbc_30_Tlf35584.c` → `Sbc_Ll_InitDevice`）：

```text
Sbc_SpiSetupEB
  → Sbc_Ll_ReadAndUnlockProtectedRegisters   ← 最常见失败点
  → Sbc_Ll_WriteAndLockProtectedRegisters
  → Write DEVCTRL / DEVCTRLN (NORMAL)
```

解锁失败时：`PROTSTAT` 的 **LOCK 位仍为 1**。

### 7.2 根因对照表

| 现象 | 可能原因 | 处理 |
| --- | --- | --- |
| 首次加 Sbc 即 0x14 | SPI **LSB** 或 **LEADING**（Mode 1） | 改为 **MSB + TRAILING**，见 §3.2 |
| 改过 32→16 仍失败 | 只改位宽，位序/相位未改 | GenData 检查 `0x90U` 与 CPH=0 |
| `SPISF.LENE=1` | 时钟数 ≠ 16（曾用 32bit） | 确认 DataWidth=16 |
| `SPISF.PARE=1` | 位序/相位错导致 parity 错 | 改 MSB + Mode 0 |
| Loopback 全 0 | CS/CLK/MOSI 无波形 | 查 Port ALT、示波器 |
| `Spi_SyncTransmit` 返回 E_NOT_OK | QSPI1 未 Init 或 Sequence ID 错 | 查 EcuM/BswM 顺序 |
| 芯片未上电 | VS 未到、INIT 未完成 | 查 Power 原理图与 `DEVSTAT` |

### 7.3 推荐调试步骤

1. **断点**：`Sbc_Ll_ReadAndUnlockProtectedRegisters` 内读 `PROTSTAT` 之后。
2. **观察变量**：
   - `Sbc_Ll_SpiOutBuffer[0]` — 写 PROTCFG(0x03, 0xAB) 后应为合法 16bit 命令字
   - `Sbc_Ll_SpiInBuffer[0]` — 写操作应 **loopback** 相同帧；全 0 表示 MISO 无回读
3. **读寄存器**（通信正常后）：
   - `0x28` PROTSTAT — LOCK 应为 0（解锁后）
   - `0x1F` SPISF — LENE/PARE/DURE 标志
   - `0x27` DEVSTAT — 设备状态机
4. **示波器**：CS(P11.2)、CLK(P11.6)、MOSI(P11.9)、MISO(P11.3)，确认 16 个 SCLK、Mode 0。

📷 **图片位 P11**：示波器四线 SPI 波形（16 clock，CS 低期间）

<!-- ../image/TLF35584_Config_Guide/11_scope_spi_waveform.png -->

📷 **图片位 P12**：调试器 Watch 窗口（SpiOutBuffer / SpiInBuffer / PROTSTAT）

<!-- ../image/TLF35584_Config_Guide/12_debug_watch_buffers.png -->

### 7.4 临时隔离（确认是否仅 Sbc 问题）

在 `BswM_Lcfg.c` 中 **临时注释** `Sbc_30_Tlf35584_Init(...)`，其余模块正常启动 → 则问题限定在 SPI/35584 路径。

---

## 8. 配置变更检查清单

Generate → TouchGenData（若改系统日期）→ 全量 Build → 上板前逐项打勾：

- [ ] `SpiChannel_35584`：**16 bit + MSB**
- [ ] `SpiExternalDevice_35584`：**TRAILING + Idle LOW + CHANNEL5**
- [ ] `Spi_PBcfg.c`：Channel = **`0x90U`**，CPH/CPOL = **0/0**
- [ ] Port：P11.2/6/9 ALT 正确，P11.3 MRST 与 `MRST1B_PORT11_PIN3` 一致
- [ ] Sbc：`SbcSpiChannelRef` / `SbcSpiSequenceRef` 指向 35584
- [ ] EcuM：`Spi_Init` 在 `Sbc_30_Tlf35584_Init` **之前**
- [ ] 编译补丁：`_MemMap.h` / `_Compiler_Cfg.h` / `Sbc_SpiDataType` 仍在
- [ ] 上板：无 DET 0x14，`DEVSTAT` 进入预期状态

---

## 9. 截图清单（用户自插）

| 图片位 | 建议文件名 | 内容 |
| --- | --- | --- |
| P1 | `01_power_schematic.png` | Power 原理图 TLF35584 |
| P2 | `02_port_pins.png` | Port 四脚配置 |
| P3 | `03_pin_mux_table.png` | 引脚复用对照 |
| P4 | `04_datasheet_spi_frame.png` | 手册 SPI 帧格式 |
| P5 | `05_spi_channel.png` | SpiChannel_35584 |
| P6 | `06_spi_external_device.png` | SpiExternalDevice_35584 |
| P7 | `07_spi_job_sequence_hw.png` | Job/Sequence/HwConfig |
| P8 | `08_sbc_module.png` | Sbc 模块配置 |
| P9 | `09_bswm_init_order.png` | BswM 初始化顺序 |
| P10 | `10_det_error_0x14.png` | DET 报错 |
| P11 | `11_scope_spi_waveform.png` | 示波器波形 |
| P12 | `12_debug_watch_buffers.png` | 调试 Watch |

建议图片目录：`note/../image/TLF35584_Config_Guide/`

插入示例：

```markdown
![35584 SPI Channel](../image/TLF35584_Config_Guide/05_spi_channel.png)
```

---

## 10. 相关文件索引

| 用途 | 路径 |
| --- | --- |
| Spi ECUC | `Config/ECUC/last364_Spi_Spi_ecuc.arxml` |
| Port ECUC | `Config/ECUC/last364_Port_Port_ecuc.arxml` |
| Sbc 生成配置 | `Appl/GenData/Sbc_30_Tlf35584_Lcfg.c` |
| Spi 生成配置 | `Appl/GenData/src/Spi_PBcfg.c` |
| Sbc 驱动 | `BSW364/Sbc_30_Tlf35584/Implementation/Sbc_30_Tlf35584.c` |
| BswM 调用 | `Appl/GenData/BswM_Lcfg.c` |
| EcuM Spi Init | `Appl/Source/EcuM_Callout_Stubs.c` |
| 编译修复记录 | [Sbc_30_Tlf35584_Fix.md../FixNote/Sbc_30_Tlf35584_Fix.md) |

---

## 11. 版本记录

| 日期 | 说明 |
| --- | --- |
| 2026-08-08 | 初版：16bit MSB + TRAILING 正确配置；DET 0x14 排障流程 |
