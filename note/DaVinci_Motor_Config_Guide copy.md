# TC364 电机工程 DaVinci Configurator 模块配置指南

> 适用范围：`last364.dpa`（AURIX TC364 + Vector MICROSAR 4.2.2 + Infineon MCAL 20.10.0）
> 依据：工程 `Config\ECUC\last364_*.arxml` 实际配置、`Appl\Source` 应用代码、`BSW364/MCAL364` 生成代码。
> 本文档给出“电机相关模块在 DaVinci Configurator 里每一项怎么配”，参数均为本工程当前值。

---

## 模块配置文档索引（逐模块）

> 每个模块都有一份独立的配置文档（含操作步骤与截图位），点击下方链接打开；本指南保留全部参数作为总表。

| 模块 | 本章节 | 详细配置文档 |
| --- | --- | --- |
| Mcu | [§1](#1-mcu-模块) | [DaVinci_Mcu.md](DaVinci_Modules/DaVinci_Mcu.md) |
| Port | [§2](#2-port-模块) | [DaVinci_Port.md](DaVinci_Modules/DaVinci_Port.md) |
| Pwm | [§3](#3-pwm-模块) | [DaVinci_Pwm.md](DaVinci_Modules/DaVinci_Pwm.md) |
| Adc | [§4](#4-adc-模块) | [DaVinci_Adc.md](DaVinci_Modules/DaVinci_Adc.md) |
| Spi | [§5](#5-spi-模块) | [DaVinci_Spi.md](DaVinci_Modules/DaVinci_Spi.md) |
| Dio | [§6](#6-dio-模块) | [DaVinci_Dio.md](DaVinci_Modules/DaVinci_Dio.md) |
| Irq | [§7](#7-irq-模块) | [DaVinci_Irq.md](DaVinci_Modules/DaVinci_Irq.md) |
| Os | [§8](#8-os-模块) | [DaVinci_Os.md](DaVinci_Modules/DaVinci_Os.md) |
| EcuM | [§9](#9-ecum-模块) | [DaVinci_EcuM.md](DaVinci_Modules/DaVinci_EcuM.md) |
| BswM | [§10](#10-bswm-模块) | [DaVinci_BswM.md](DaVinci_Modules/DaVinci_BswM.md) |
| Can | [§11](#11-can--canif--com-模块) | [DaVinci_Can.md](DaVinci_Modules/DaVinci_Can.md) |
| CanIf | [§11](#11-can--canif--com-模块) | [DaVinci_CanIf.md](DaVinci_Modules/DaVinci_CanIf.md) |
| Com | [§11](#11-can--canif--com-模块) | [DaVinci_Com.md](DaVinci_Modules/DaVinci_Com.md) |
| NvM | [§12](#12-nvm--fee--fls-模块零位标定存储) | [DaVinci_NvM.md](DaVinci_Modules/DaVinci_NvM.md) |
| Fee | [§12](#12-nvm--fee--fls-模块零位标定存储) | [DaVinci_Fee.md](DaVinci_Modules/DaVinci_Fee.md) |
| Fls | [§12](#12-nvm--fee--fls-模块零位标定存储) | [DaVinci_Fls.md](DaVinci_Modules/DaVinci_Fls.md) |
| ResourceM | [§13](#13-resourcem-模块多核归属) | [DaVinci_ResourceM.md](DaVinci_Modules/DaVinci_ResourceM.md) |
| Sbc | [§14](#14-sbc-模块tlf35584) | [DaVinci_Sbc.md](DaVinci_Modules/DaVinci_Sbc.md) |
| Rte | [§15](#15-rte--应用-sw-c-映射) | [DaVinci_Rte.md](DaVinci_Modules/DaVinci_Rte.md) |

---

## 0. 系统总览

### 0.1 硬件链路


| 功能            | 硬件资源                                                | 引脚/通道                                                             | 芯片/外设            |
| ------------- | --------------------------------------------------- | ----------------------------------------------------------------- | ---------------- |
| 三相 PWM 上桥     | GTM ATOM0 CH1/2/3                                   | P02.1 / P02.2 / P02.3（IH1/2/3）                                    | TLE9180 栅极驱动     |
| 三相 PWM 下桥（互补） | GTM ATOM0 CH4/5/6 + CDTM 死区                         | P02.4 / P02.5 / P02.6（IL1/2/3）                                    | TLE9180          |
| 相电流 / 母线电压采样  | EVADC G0/G2/G3 同步组                                  | VO1=ADC0 CH4、VRO=ADC0 CH1、VO2=ADC2 CH4、VINV=ADC2 CH1、VO3=ADC3 CH4 | 运放 + 分流电阻        |
| ADC 触发        | GTM ATOM0 CH7（CM0 时钟，10000 ticks @100 MHz = 10 kHz） | 内部触发（无引脚）                                                         | EVADC GxREQTRI   |
| 转子角度          | QSPI2（SSC）                                          | MTSR=P15.5、MRST=P15.7、SCLK=P15.6、CS=P14.6（SLSO2）                  | TLE5012B         |
| 栅驱 SPI        | QSPI3                                               | MTSR=P22.0、MRST=P22.1、SCLK=P22.3、CS=P22.2（SLSO0）                  | TLE9180，24-bit 帧 |
| 栅驱控制脚         | Dio                                                 | INH=P00.12、SOFF=P00.2、ERR=P00.4、ENA=P02.8                         | TLE9180          |
| 电源管理 SBC      | QSPI1                                               | CSN=P03.2、CLK=P03.6、MTSR=P03.7、MRST=P03.3                         | TLF35584         |
| 通信            | MCAN0                                               | RX=P20.7、TX=P20.8；NSTB=P20.6、EN=P20.9、NERR=P20.10                 | CAN / CAN FD     |
| 非易失存储         | DFlash（Fls DMU）                                     | 基址 0xAF000000，2×64 KB                                             | Fee → NvM（零位标定）  |
| 调试灯/示波        | Dio                                                 | led1=P33.0、led2=P33.1、test=P15.2、test2=P15.3                      | —                |


大致模块图，xcp 用于配置标定的通信协议栈
![20260805112339](https://cdn.jsdelivr.net/gh/xiongGithub1/picGoUpload/image/20260805112339.png)

### 0.2 软件运行架构（双核）


| 核     | 角色     | 任务/中断                                    | 内容                                                          |
| ----- | ------ | ---------------------------------------- | ----------------------------------------------------------- |
| Core0 | BSW 主核 | `Default_Appl_Task`（5 ms 级事件）            | StartApp 1/10/250/1000 ms 周期函数、Com/ComM/EcuM 等 BSW          |
| Core0 | BSW    | `Default_BSW_ASync_Task_10ms`            | Com 主函数、CanSM 等                                             |
| Core1 | 电机控制核  | `MotorTask`（优先级 100，1 ms 事件）             | MotorControll 1 ms 状态机、MotorCdd 主函数、TLE9180/5012 轮询、零位标定    |
| Core1 | 快速环    | `AdcIsr_G0`（ADC0 SR0，CAT1，优先级 83，10 kHz） | ADC 通知 → 电流换算 → FOC 快速环（Clarke/Park/PI/SVPWM → ATOM0 影子寄存器） |


---



## 1. Mcu 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Mcu.md](DaVinci_Modules/DaVinci_Mcu.md)

DaVinci 路径：`Mcu`。

### 1.1 时钟

`McuModuleConfiguration > McuClockSettingConfig_0`（`McuClockSettingId = 0`）：


| 参数                                | 当前值                  | 说明               |
| --------------------------------- | -------------------- | ---------------- |
| `McuSystemPllSettingConfig`       | N=29、P=0、K2=1，输入 OSC | CPU0/1 = 300 MHz |
| `McuPeripheralPllSettingConfig`   | N=31、P=0、K2=1        | 外设 PLL           |
| `McuPllDistributionSettingConfig` | —                    | 见下表              |


关键时钟分配（`McuPllDistributionSettingConfig`）：


| 时钟                                       | 值                    |
| ---------------------------------------- | -------------------- |
| `McuCPU0Frequency` / `McuCPU1Frequency`  | 300000000（300 MHz）   |
| `McuSPBFrequency`                        | 100000000（100 MHz）   |
| `McuGTMFrequency`                        | 200000000（200 MHz）   |
| `McuMCanFrequency` / `McuMcanHFrequency` | 80000000 / 100000000 |
| `McuQspiFrequency`                       | 80000000             |
| `McuAdcFrequency`                        | 160000000            |
| `McuSTMFrequency`                        | 100000000            |


时钟参考点（电机相关，必须与各模块引用一致）：

时钟


| 参考点                          | 频率      | 被谁引用                                        |
| ---------------------------- | ------- | ------------------------------------------- |
| `McuClockReferencePoint_Pwm` | 100 MHz | Pwm 通道 `PwmMcuClockReferencePoint`          |
| `McuClockReferencePoint_0`   | 100 MHz | Spi/Adc 的 `McuClockReferencePointConfig` 体系 |
| `McuClockReferencePoint_can` | 80 MHz  | Can 控制器 `CanCpuClockRef`                    |




### 1.2 GTM 配置

`McuModuleConfiguration > GtmGlobalConfiguration_0`：

`GtmAtomGlobalConf_0 > GtmAtomChannelConf_N`（ATOM0 各通道）：


| 通道  | `GtmTimerPortPinSelect`    | 用途                             |
| --- | -------------------------- | ------------------------------ |
| CH0 | NONE                       | PWM 参考通道（`PwmChannel_9180REF`） |
| CH1 | `TOUT1_SELC_2_PORT02_PIN1` | IH1（U 相上桥）                     |
| CH2 | `TOUT2_SELC_2_PORT02_PIN2` | IH2（V 相上桥）                     |
| CH3 | `TOUT3_SELC_2_PORT02_PIN3` | IH3（W 相上桥）                     |
| CH4 | `TOUT4_SELC_2_PORT02_PIN4` | IL1（U 相下桥，互补）                  |
| CH5 | `TOUT5_SELC_2_PORT02_PIN5` | IL2（V 相下桥，互补）                  |
| CH6 | `TOUT6_SELC_2_PORT02_PIN6` | IL3（W 相下桥，互补）                  |
| CH7 | NONE                       | ADC 触发（内部）                     |


`McuGtmClockManagementConf`：


| 参数                                        | 当前值                                 | 说明                |
| ----------------------------------------- | ----------------------------------- | ----------------- |
| `GtmCmuConfigClock0Div` = 0、Enable = true | —                                   | CMU0 使能           |
| `GtmCmuClusterInputClockDividerEnable`    | `CLS_CLK_CFG_ENABLED_WITH_DIV_SEL2` | 集群时钟 ÷2 → 100 MHz |
| `GtmCmuGlobalClockNumerator/Denominator`  | 1 / 1                               | —                 |


> 结论：GTM 全局 200 MHz ÷2 = 100 MHz，PWM 周期 10000 ticks → 100 µs → 10 kHz；ADC 触发同源同频。

`GtmTriggerForAdc_0`：


| 参数                        | 当前值                 | 说明                       |
| ------------------------- | ------------------- | ------------------------ |
| `GtmAdcTrigger0Select`    | `TRIG_8`            | ATOM0 CH7 → EVADC0 TRIG0 |
| `GtmAdcTrigger1..4Select` | `TRIG_0_NO_TRIGGER` | 其余不用                     |




### 1.3 硬件资源分配

`McuHardwareResourceAllocationConf_0 > McuGtmAllocationConf_0 > McuGtmAtomAllocationConf_0`：


| 分配项                                    | 值                                                     |
| -------------------------------------- | ----------------------------------------------------- |
| `McuGtmAtomChannelAllocationConf_0..3` | `GTM_ATOM_CHANNEL_USED_BY_PWM`                        |
| `McuGtmAtomChannelAllocationConf_4..6` | `GTM_ATOM_CHANNEL_NOT_USED`（应用层用 CDTM 做互补，不占 MCAL 通道） |
| `McuGtmAtomChannelAllocationConf_7`    | `GTM_ATOM_CHANNEL_USED_BY_ADC`                        |


其余（CCU6、GPT12、ERU、TOM、TIM、DMA 通道等）均未分配。

### 1.4 注意事项

- 改 PWM 频率时，`PwmPeriodDefault`、ADC `GtmTimerCM0Ticks`、应用层 `MOTORCDD_ADC_TRIGGER_PERIOD_TICKS` 三处必须一致。
- ATOM 通道“USED_BY_PWM / USED_BY_ADC”分配冲突会导致生成报错；CH7 必须保持 `USED_BY_ADC`。
- `McuClockReferencePoint_Pwm` 决定 Pwm 模块周期换算，改成其他频率后 Pwm 模块里要同步改。

---



## 2. Port 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Port.md](DaVinci_Modules/DaVinci_Port.md)

DaVinci 路径：`Port > PortConfigSet`（按 `PortContainer_N` 分组，端口号以 `PortPinId/16` 为准）。

### 2.1 电机相关引脚表


| 引脚名（DaVinci 容器）                  | 端口.引脚         | 方向       | 模式                   | 初始电平 | 用途                      |
| -------------------------------- | ------------- | -------- | -------------------- | ---- | ----------------------- |
| `PortPin_9183IH1`                | P02.1         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM ATOM0 CH1（U 上桥）     |
| `PortPin_9183IH2`                | P02.2         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM ATOM0 CH2（V 上桥）     |
| `PortPin_9183IH3`                | P02.3         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM ATOM0 CH3（W 上桥）     |
| `PortPin_9183IL1`                | P02.4         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM 互补（U 下桥）            |
| `PortPin_9183IL2`                | P02.5         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM 互补（V 下桥）            |
| `PortPin_9183IL3`                | P02.6         | OUT      | `PORT_PIN_MODE_ALT1` | LOW  | GTM 互补（W 下桥）            |
| `PortPin_9183SOFF`               | P00.2         | OUT      | `PORT_PIN_MODE_GPIO` | HIGH | 9183 Safe-Off（低有效）      |
| `PortPin_9183ERR`                | P00.4         | IN       | `PORT_PIN_MODE_ALL`  | LOW  | 9183 错误标志（高有效）          |
| `PortPin_19183INH`               | P00.12        | OUT      | `PORT_PIN_MODE_GPIO` | LOW  | 9183 Inhibit            |
| `PortPin_9183ENA`                | P02.8         | OUT      | `PORT_PIN_MODE_GPIO` | LOW  | 9183 输出使能               |
| `PortPin_9183PFB1/2/3`           | P00.0/1/3     | IN       | GPIO                 | LOW  | 9183 反馈（备选）             |
| `PortPin_5012CSN`                | P14.6         | OUT      | `PORT_PIN_MODE_ALT3` | HIGH | QSPI2 SLSO2（TLE5012 CS） |
| `PortPin_5012MTSR`               | P15.5         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI2 MTSR              |
| `PortPin_5012CLK`                | P15.6         | OUT      | `PORT_PIN_MODE_ALT5` | LOW  | QSPI2 SCLK              |
| `PortPin_5012MRST`               | P15.7         | IN       | GPIO                 | LOW  | QSPI2 MRST              |
| `PortPin_9183Qspi3MTSR`          | P22.0         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI3 MTSR              |
| `PortPin_9183Qspi3MRST`          | P22.1         | IN       | ALL                  | LOW  | QSPI3 MRST              |
| `PortPin_9183QspiCSN`            | P22.2         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI3 SLSO0（9183 CS）    |
| `PortPin_9183Qspi3CLK`           | P22.3         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI3 SCLK              |
| `PortPin_tle35584_CSN`           | P03.2         | OUT      | `PORT_PIN_MODE_ALT4` | LOW  | QSPI1 SLSO（SBC CS）      |
| `PortPin_tle35584_Clk`           | P03.6         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI1 SCLK              |
| `PortPin_tle35584_MTSR`          | P03.7         | OUT      | `PORT_PIN_MODE_ALT3` | LOW  | QSPI1 MTSR              |
| `PortPin_tle35584_MRST`          | P03.3         | IN       | ALL                  | LOW  | QSPI1 MRST              |
| `PortPin_CAN1Tx/Rx`              | P20.8 / P20.7 | OUT / IN | ALL                  | LOW  | MCAN0                   |
| `PortPin_CAN1Nstb`               | P20.6         | OUT      | ALL                  | HIGH | 收发器 STB                 |
| `PortPin_CAN1EN`                 | P20.9         | OUT      | ALL                  | HIGH | 收发器使能                   |
| `PortPin_CAN1NERR`               | P20.10        | IN       | ALL                  | LOW  | 收发器错误                   |
| `PortPin_test` / `PortPin_test2` | P15.2 / P15.3 | OUT      | ALL / GPIO           | LOW  | 示波器测试点                  |
| `PortPin_led1` / `PortPin_Led2`  | P33.0 / P33.1 | OUT      | ALL                  | LOW  | 状态灯                     |




### 2.2 注意事项

- EVADC 模拟输入（VO1/VO2/VO3/VRO/VINV/G8CH3）不需要建 Port 引脚，DaVinci 只配置数字功能脚。
- IH/IL 六根脚必须都是 `ALT1`（对应 GTM TOUT 输出），IL 的互补信号由应用层 `MotorCdd_PwmComplementaryInit()` 通过 GTM CDTM 生成（`TOUTSEL0=0x28882222`、死区 200 ticks）。
- `PortPin_5012MRST` 在 Port 里是 GPIO 输入，但 QSPI2 硬件接收走 MRST（`SpiHWPinMRSTQspix = MRST2B_PORT15_PIN7`），以 SPI 配置为准。
- 初始电平很关键：SOFF 上电必须 HIGH（安全关断无效），INH 低、ENA 低，由驱动初始化后再拉高。

---



## 3. Pwm 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Pwm.md](DaVinci_Modules/DaVinci_Pwm.md)

DaVinci 路径：`Pwm > PwmChannelConfigSet`。

### 3.1 通道配置


| 通道                   | `PwmChannelId` | Class                             | 周期    | 空闲/极性     | 相干更新  | ATOM 通道   |
| -------------------- | -------------- | --------------------------------- | ----- | --------- | ----- | --------- |
| `PwmChannel_9180REF` | 0              | `PWM_FIXED_PERIOD`                | 10000 | LOW / LOW | false | ATOM0 CH0 |
| `PwmChannel_9180IH1` | 1              | `PWM_FIXED_PERIOD_CENTER_ALIGNED` | 10000 | LOW / LOW | true  | ATOM0 CH1 |
| `PwmChannel_9180IH2` | 2              | `PWM_FIXED_PERIOD_CENTER_ALIGNED` | 10000 | LOW / LOW | true  | ATOM0 CH2 |
| `PwmChannel_9180IH3` | 3              | `PWM_FIXED_PERIOD_CENTER_ALIGNED` | 10000 | LOW / LOW | true  | ATOM0 CH3 |


每个通道的 `GtmTimerOutputModuleConfiguration`：


| 参数                    | 值                                         |
| --------------------- | ----------------------------------------- |
| `GtmTimerClockSelect` | `GTM_CONFIGURABLE_CLOCK_0`（100 MHz）       |
| `GtmTimerUsed`        | `McuGtmAtomChannelAllocationConf_0/1/2/3` |


公共参数（`PwmGeneral` / `PwmConfigurationOfOptApiServices`）：


| 参数                                                              | 值     |
| --------------------------------------------------------------- | ----- |
| `PwmSetDutyCycle` / `PwmSetPeriodAndDuty` / `PwmGetOutputState` | true  |
| `PwmDeInitApi` / `PwmInitCheckApi`                              | true  |
| `PwmNotificationSupported`                                      | false |
| `PwmDevErrorDetect`                                             | false |




### 3.2 与应用的衔接

- Pwm 模块只负责 **初始化** GTM ATOM 的周期/对齐方式（PBCfg 0x2710 = 10000，中心对齐）。
- FOC 快速环（`MotorFoc_ApplyAtomDuties`）直接写 `GTM_ATOM0_CH1/2/3` 的 SR0/SR1 影子寄存器做 SVPWM 中心对齐更新，不再调用 `Pwm_SetDutyCycle`。
- 互补输出与死区在 `MotorCdd.c` 的 `MotorCdd_PwmComplementaryInit()` 中直接配置 GTM CDTM0/DTM4（`CH_CTRL2` 使能 6 路、死区 `DTV=200` ticks ≈ 2 µs），不属于 DaVinci 配置范围。



### 3.3 注意事项

- 周期 10000 ticks @100 MHz = 100 µs（10 kHz），与 ADC 触发 `GtmTimerCM0Ticks=10000` 严格一致。
- 三通道 `PwmCoherentUpdate = true`，保证三相同拍更新（FOC 需要三相一致性）。
- 不要勾选 `PwmNotificationSupported`（本项目不用 PWM 中断）。

---



## 4. Adc 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Adc.md](DaVinci_Modules/DaVinci_Adc.md)

DaVinci 路径：`Adc > AdcConfigSet`。

### 4.1 硬件单元


| 硬件单元             | 同步角色              | `AdcPrescale` | 用途                   |
| ---------------- | ----------------- | ------------- | -------------------- |
| `AdcHwUnit_ADC0` | `ADC_SYNC_MASTER` | 4             | 相电流 VO1 + 母线 VRO（G0） |
| `AdcHwUnit_ADC2` | `ADC_SYNC_SLAVE`  | 4             | 相电流 VO2 + VINV（G2）   |
| `AdcHwUnit_ADC3` | `ADC_SYNC_SLAVE`  | 4             | 相电流 VO3（G3）          |
| `AdcHwUnit_ADC8` | `ADC_STAND_ALONE` | 4             | SBC 电池检测（G8CH3，软件触发） |


输入类（`AdcGlobalInputClass_1` / 各 `AdcHwUnitInputClass`）：


| 参数                        | 值                              |
| ------------------------- | ------------------------------ |
| `AdcChSampleTime`         | 10                             |
| `AdcChPreChargeClkCycles` | `ADC_INPUT_PRECHARGE_CYCLES_0` |
| `AdcChConvMode`           | `ADC_NOISE_REDUCTION_STEPS_0`  |




### 4.2 采样组



#### G0：`AdcGroup_9183Sense`（主组，groupId 0）


| 参数                       | 值                                                                     |
| ------------------------ | --------------------------------------------------------------------- |
| `AdcGroupTriggSrc`       | `ADC_TRIGG_SRC_HW`                                                    |
| `AdcHwExtTrigSelect`     | `ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0`                                  |
| `AdcHwTrigSignal`        | `ADC_HW_TRIG_RISING_EDGE`                                             |
| `AdcNotification`        | `Adc_9183SenseVo1andVro_Notification`                                 |
| `AdcGroupAccessMode`     | `ADC_ACCESS_MODE_SINGLE`                                              |
| `AdcGroupConversionMode` | `ADC_CONV_MODE_ONESHOT`                                               |
| 通道                       | `AdcChannel_9183_VO1`（G0CH4，chId1）、`AdcChannel_9183_VRO`（G0CH1，chId0） |
| 结果寄存器                    | RES0=VO1、RES1=VRO（`AdcResRegDefinition` 0/1）                          |


`GtmTriggerTimerConfig`（挂在 G0 组下）：


| 参数                    | 值                                              |
| --------------------- | ---------------------------------------------- |
| `GtmTimerClockSelect` | `GTM_CONFIGURABLE_CLOCK_0`                     |
| `GtmTimerTimePeriod`  | 100（µs，周期 100 µs）                              |
| `GtmTimerCM0Ticks`    | 10000                                          |
| `GtmTimerUsed`        | `McuGtmAtomChannelAllocationConf_7`（ATOM0 CH7） |




#### G2：`AdcGroup`（groupId 64，同步从机）

- 通道：`AdcChannel_9183_VO2`（G2CH4）、`AdcChannel_V_INV`（G2CH1）
- 硬件触发同上（`ADC_TRIG_8_GxREQTRI_GTM_ADCx_TRIG0`），与主组同步转换。



#### G3：`AdcGroup_1`（groupId 96，同步从机）

- 通道：`AdcChannel_9183_VO3`（G3CH4）



#### G8：`AdcGroup_2`（groupId 256）

- 通道：`AdcChannel_SS_BatteryCheck`（G8CH3）
- `AdcGroupTriggSrc = ADC_TRIGG_SRC_SW`（软件触发，周期性检测）



### 4.3 公共参数


| 参数                                                              | 值                                    |
| --------------------------------------------------------------- | ------------------------------------ |
| `AdcSyncConvEnable`                                             | true（G0/G2/G3 同步）                    |
| `AdcResultHandlingImplementation`                               | `ADC_INTERRUPT_MODE_RESULT_HANDLING` |
| `AdcResultAlignment`                                            | `ADC_ALIGN_RIGHT`                    |
| `AdcGrpNotifCapability` / `AdcHwTriggerApi` / `AdcReadGroupApi` | true                                 |
| `AdcMaxChannelResolution`                                       | 12                                   |
| `AdcRuntimeApiMode` / `AdcInitDeInitApiMode`                    | `ADC_MCAL_SUPERVISOR`                |




### 4.4 多核初始化（关键！）

- `ResourceM` 中 G0/G2/G3 归属 **Core1**，G8 归属 **Core0**。
- Core0 的 `EcuM_AL_DriverInitOne` 只初始化 ADC8（`Adc_Init` + `IrqAdc_Init` + `SRC_VADC_G0_SR0.SRE=1` + `Adc_TriggerStartupCal`）。
- Core1 的 `MotorCdd_AdcInit()` 会**再次**调用 `Adc_Init(&Adc_Config)`（否则 Core1 侧运行 `Adc_`* 会报 ADC_UNINIT），然后：
  1. `Adc_SetupResultBuffer(AdcGroup_9183Sense, buf, 6)`（MCAL ISR 用 6 slot）
  2. `Adc_EnableHardwareTrigger(AdcGroup_9183Sense)`
  3. `Adc_EnableGroupNotification(AdcGroup_9183Sense)`
- ADC0 SR0 中断：`Irq` 模块 `IrqAdc0SR0Cat=CAT1`、`Prio=83`、`Tos=CPU1`，OS 中登记为 `AdcIsr_G0`。



### 4.5 应用层换算（了解即可）

- 电流：`i = (VRO − VOx − offset) × 0.0310885`（分流电阻+增益）
- 母线：`VINV × 0.0095238`，`VRO × 0.0012210`
- 采样点：默认 5000 ticks（周期中心，避开开关沿），可用 UDE 通过 `MotorCdd_AdcSetTriggerTick()` 调整（限幅 400~9600）。
- 零位 offset：PWM 关断时累计 100 拍平均值（`MotorCdd_AdcCurrentOffsetReady`）。

---



## 5. Spi 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Spi.md](DaVinci_Modules/DaVinci_Spi.md)

DaVinci 路径：`Spi > SpiDriver`。

### 5.1 通道 / 外设 / Job / Sequence


| 对象                         | 参数                                          | 值                              |
| -------------------------- | ------------------------------------------- | ------------------------------ |
| `SpiChannel_9183`          | `SpiDataWidth`                              | 24（MSB 先发）                     |
| `SpiExternalDevice_9183`   | `SpiHwUnit`                                 | QSPI3                          |
|                            | `SpiBaudrate`                               | 4000000（4 MHz）                 |
|                            | `SpiCsIdentifier`                           | `CHANNEL12`（QSPI3 SLSO0，P22.2） |
|                            | `SpiCsPolarity`                             | LOW                            |
|                            | `SpiDataShiftEdge`                          | TRAILING                       |
|                            | `SpiIdleTime/TrailingTime/SpiTimeClk2Cs`    | 6E-7（600 ns）                   |
| `SpiJob_9183`              | `SpiJobId` 0、优先级 0、`SYNCHRONOUS`、非帧基 CS     | 挂 `SpiChannel_9183`            |
| `SpiSequence_9183`         | `SpiSequenceId` 0、不可中断                      | 挂 `SpiJob_9183`                |
| `SpiChannel_5012BD1`       | `SpiDataWidth`                              | 32（MSB 先发）                     |
| `SpiExternalDevice_5012BD` | `SpiHwUnit`                                 | QSPI2                          |
|                            | `SpiBaudrate`                               | 4000000                        |
|                            | `SpiCsIdentifier`                           | `CHANNEL2`（QSPI2 SLSO2，P14.6）  |
|                            | `SpiCsPolarity`                             | LOW                            |
|                            | `SpiDataShiftEdge`                          | LEADING                        |
|                            | 各延时                                         | 6E-7                           |
| `SpiJob_5012BD`            | `SpiJobId` 1、优先级 2、`SpiFrameBasedCS = true` | 挂 `SpiChannel_5012BD1`         |
| `SpiSequence_5012BD`       | `SpiSequenceId` 1                           | 挂 `SpiJob_5012BD`              |
| `SpiChannel_35584`         | `SpiDataWidth`                              | 32（LSB 先发）                     |
| `SpiExternalDevice_35584`  | `SpiHwUnit`                                 | QSPI1                          |
|                            | `SpiBaudrate`                               | 1000000（1 MHz）                 |
|                            | `SpiCsIdentifier`                           | `CHANNEL5`（QSPI1 SLSO，P03.2）   |
|                            | `SpiDataShiftEdge`                          | LEADING                        |
|                            | 各延时                                         | 1E-7                           |
| `SpiJob_35584`             | `SpiJobId` 2、优先级 0                          | 挂 `SpiChannel_35584`           |
| `SpiSequence_35584`        | `SpiSequenceId` 2                           | 挂 `SpiJob_35584`               |




### 5.2 硬件配置（`SpiHwConfiguration`）


| QSPI  | 参数                                                     | 值                    |
| ----- | ------------------------------------------------------ | -------------------- |
| QSPI1 | `SpiHWPinMRSTQspix`                                    | `MRST1B_PORT11_PIN3` |
| QSPI2 | `SpiHWPinMRSTQspix`                                    | `MRST2B_PORT15_PIN7` |
| QSPI3 | `SpiHWPinMRSTQspix`                                    | `MRST3D_PORT22_PIN1` |
| 全部    | `SpiJobQueueLengthQspix` = 2、`SpiSLSO0StrobeDelay` = 2 | —                    |




### 5.3 使用方式与注意事项

- TLE9180：应用层 `Tle9180_Port_SpiExchange()` 用 `Spi_SetupEB(SpiChannel_9183) + Spi_SyncTransmit(SpiSequence_9183)`，24-bit 帧（掩码 0x00FFFFFF）。
- TLE5012B：应用层 `Tle5012bd_Spi.c` **绕过 MCAL**，直接操作 QSPI2 SFR（BACON：32-bit、MSB、CS=SLSO2、LAST=1、8 MHz 时序）。因此 `SpiJob_5012BD` 的作用是让 `Spi_Init` 把 QSPI2 的 ECON/SSOC/GLOBALCON 配置成与直读代码一致（应用层再按 `TLE5012BD_QSPI2_`* 常量校验/重写）。
- SBC TLF35584：`SpiSequence_35584`（QSPI1，1 MHz，32-bit LSB）。
- 多核：ResourceM 中 QSPI2/QSPI3 归属 Core1，QSPI1 归属 Core0；`Spi_Init` 在 Core0 与 Core1 的 `EcuM_AL_DriverInitOne` 中各调用一次。
- `SpiLevelDelivered = 0`，`SpiSyncTransmitTimeoutDuration = 65535`。

---



## 6. Dio 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Dio.md](DaVinci_Modules/DaVinci_Dio.md)

DaVinci 路径：`Dio > DioConfig`。


| Dio 通道                                        | 端口.引脚                  | 方向         | 用途            |
| --------------------------------------------- | ---------------------- | ---------- | ------------- |
| `DioChannel_9183INH`                          | P00.12                 | OUT        | 9183 Inhibit  |
| `DioChannel_9183SOFF`                         | P00.2                  | OUT        | 9183 Safe-Off |
| `DioChannel_9183ERR`                          | P00.4                  | IN         | 9183 错误输入     |
| `DioChannel_9183ENA`                          | P02.8                  | OUT        | 9183 输出使能     |
| `DioChannel_test` / `DioChannel_test2`        | P15.2 / P15.3          | OUT        | 测试点           |
| `DioChannel_led1` / `DioChannel_led2`         | P33.0 / P33.1          | OUT        | 状态灯           |
| `DioChannel_Can1Nstb` / `Can1En` / `Can1Nerr` | P20.6 / P20.9 / P20.10 | OUT/OUT/IN | CAN 收发器控制     |


`DioGeneral`：`DioFlipChannelApi = true`、`DioDevErrorDetect = true`。

应用层通过 `Tle9180_Port_Activate/DeactivateInhibit/Enable/SafeOff()` 与 `Tle9180_Port_GetErrorState()` 使用这些通道（`Dio_WriteChannel / Dio_ReadChannel`）。

---



## 7. Irq 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Irq.md](DaVinci_Modules/DaVinci_Irq.md)

DaVinci 路径：`Irq > IrqAdcConfig_0 / IrqCanConfig_0 / IrqStmConfig_0 / IrqQSPIConfig_0`。


| 中断                 | 配置项                              | 当前值                  |
| ------------------ | -------------------------------- | -------------------- |
| ADC0 SR0（电机采样/FOC） | `IrqAdc0SR0Cat` / `Prio` / `Tos` | CAT1 / 83 / **CPU1** |
| ADC8 SR0（电池检测）     | `IrqAdc8SR0Cat` / `Prio` / `Tos` | CAT2 / 78 / CPU0     |
| CAN0 SR0           | `IrqCanSR0*`                     | CPU0（OS 侧优先级 60）     |
| STM1（Core1 系统定时器）  | `IrqStm1SR0*`                    | CPU1                 |
| QSPI 各中断           | `IrqQspi*`                       | CAT1 / 0 / CPU0（未使用） |
| GTM ATOM           | `IrqGtmATOM*`                    | CAT1 / 0 / CPU0（未使用） |


注意事项：

- ADC0 SR0 必须 TOS=CPU1，才能与 Core1 的 `AdcIsr_G0`（OS）和快速环匹配。
- `IrqAdc_Init()` 在 Core0 执行，之后需在 `EcuM_AL_DriverInitOne` 中显式置 `SRC_VADC_G0_SR0.SRE = 1`，否则 G0 中断不触发（工程里已有该处理）。
- 电机侧不依赖 QSPI 中断（TLE5012 用轮询直读、TLE9180 用同步发送）。

---



## 8. Os 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Os.md](DaVinci_Modules/DaVinci_Os.md)

DaVinci 路径：`Os`（Vector Os，2 核，SC1）。

### 8.1 计数器


| 计数器            | 硬件       | tick                           |
| -------------- | -------- | ------------------------------ |
| `SystemTimer`  | STM0 Ch0 | 1 ms（`OsSecondsPerTick=0.001`） |
| `SystemTimer1` | STM1 Ch0 | 1 ms                           |




### 8.2 任务


| 任务                                | 核     | 优先级     | 周期/事件                                                                             | 内容                                |
| --------------------------------- | ----- | ------- | --------------------------------------------------------------------------------- | --------------------------------- |
| `Default_Init_Task`               | Core0 | 50      | 启动                                                                                | EcuM 初始化序列                        |
| `Default_Init_Task_Trusted`       | Core0 | 49      | 启动                                                                                | 可信初始化                             |
| `Default_Appl_Init_Task`          | Core0 | 45      | 启动                                                                                | RTE 启动（StartApp_Init 等）           |
| `Default_BSW_ASync_Task_10ms`     | Core0 | 30      | 10/20 ms 事件                                                                       | Com 主函数等                          |
| `Default_Appl_Task`               | Core0 | 5       | 1/10/250/1000 ms 事件                                                               | StartApp 周期函数                     |
| `Default_MotorInitTask`           | Core1 | 0       | 自启动                                                                               | Core1 启动入口（`brsStartupEntry`）     |
| `Default_Init_Task_Core1`         | Core1 | 50      | 启动                                                                                | Core1 EcuM 初始化                    |
| `Default_Init_Task_Core1_Trusted` | Core1 | 49      | 启动                                                                                | 可信初始化                             |
| `BswCore1Task`                    | Core1 | 20      | 10 ms 事件（`Rte_Al_TE2_EcuM_EcuM_MainFunction`）                                     | EcuM_MainFunction                 |
| `MotorTask`                       | Core1 | **100** | `Rte_Ev_Cyclic_MotorTask_0_1ms`（1 ms 报警）+ `Rte_Ev_Run_MotorCdd_AdcSampleReady...` | MotorControll 1 ms + MotorCdd 主函数 |




### 8.3 中断


| ISR                       | 核     | 类别       | 优先级    | 源                            |
| ------------------------- | ----- | -------- | ------ | ---------------------------- |
| `CounterIsr_SystemTimer`  | Core0 | CAT2     | 80     | STM0 SR0（768）                |
| `CounterIsr_SystemTimer1` | Core1 | CAT2     | 1      | STM1 SR0（776）                |
| `AdcIsr_G0`               | Core1 | **CAT1** | **83** | ADC0 SR0（1648），`ADC0SR0_ISR` |
| `AdcIsr_G8`               | Core0 | CAT2     | 78     | ADC8 SR0（1776）               |
| `CanIsr_0`                | Core0 | CAT2     | 60     | CAN0 SR0（1456）               |
| `XSignalIsr_OsCore0/1`    | 各核    | CAT2     | 70     | 核间信号                         |




### 8.4 注意事项

- MotorTask 优先级 100 最高，保证 1 ms 电机主循环不被 BSW 任务抢占（快速环在 CAT1 ISR 里，天然最高）。
- Core1 的 1 ms 报警 `Rte_Al_TE_MotorTask_0_1ms` 挂在 `SystemTimer1` 上；Core0 的 StartApp 周期挂在 `SystemTimer` 上。
- `OsCore1` 入口符号为 `brsStartupEntry`，非自启动，由 Core0 通过 XSignal/启动流程拉起。

---



## 9. EcuM 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_EcuM.md](DaVinci_Modules/DaVinci_EcuM.md)

DaVinci 路径：`EcuM`。

### 9.1 驱动初始化列表

`EcuMCommonConfiguration`：

`EcuMDriverInitListZero`（按序执行）：

`BswM_InitMemory → Can_InitMemory → CanIf_InitMemory → CanSM_InitMemory → Com_InitMemory → ComM_InitMemory → Det_InitMemory → PduR_InitMemory → Rte_InitMemory → BswM_PreInit → IpduM_InitMemory`

`EcuMDriverInitListOne`（按序执行）：

`Mcu_Init → Mcu_InitClock → Mcu_GetPllStatus → Mcu_DistributePllClock → Port_Init → Adc_Init → Dma_Init → IpduM_Init → PduR_PreInit → Fls_17_Dmu_Init → Fee_Init → IrqDma_Init → IrqSpi_Init → Spi_Init`

### 9.2 多核 Callout（`EcuM_AL_DriverInitOne`）


| 核          | 额外执行                                                                     |
| ---------- | ------------------------------------------------------------------------ |
| Core0（BSW） | `IrqAdc_Init()`、`SRC_VADC_G0_SR0.SRE=1`、`Adc_TriggerStartupCal()` 等待校准完成 |
| Core1      | `Spi_Init(&Spi_Config)`、`IrqGtm_Init()`、`Pwm_17_GtmCcu6_Init()`          |




### 9.3 其他


| 参数                                   | 值                                                             |
| ------------------------------------ | ------------------------------------------------------------- |
| `EcuMMainFunctionPeriod`             | 0.01（10 ms）                                                   |
| `EcuMDefaultAppMode`                 | `OSDEFAULTAPPMODE`                                            |
| `EcuMFlexConfiguration`              | Partition core0 + core1                                       |
| 唤醒源                                  | `CN_CAN00_5e566ad9`（CAN 唤醒，id 5）、RESET/POWER/WDG 等            |
| `EcuMIncludeComM` / `EcuMIncludeRte` | true                                                          |
| RUN 请求                               | 应用 `StartApp_Init()` 调 `EcuM_RequestRUN(EcuMFixedUserConfig)` |


---



## 10. BswM 模块

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_BswM.md](DaVinci_Modules/DaVinci_BswM.md)

DaVinci 路径：`BswM`。

### 10.1 初始化动作表

`BswMModeControl > BswMInitActionListRef = INIT_AL_Initialize`，`BswMActionListExecution = BSWM_CONDITION`，动作顺序：

`Det_Init → EnableInterrupts → ComM_PreInit → E2EXf_Init → Can_Init → CanIf_Init → Com_Init → PduR_Init → CanSM_Init → ComM_Init → ComM_PostInit → NvM_Init`

### 10.2 CAN 通道规则


| 规则                           | 条件                                     | 动作                         |
| ---------------------------- | -------------------------------------- | -------------------------- |
| `CC_CN_CAN00_5e566ad9_RX`    | `CanSMIndication ≠ NO_COMMUNICATION`   | 使能 `MyECU_oCAN00_Rx` PDU 组 |
| `CC_CN_CAN00_5e566ad9_TX`    | `CanSMIndication = FULL_COMMUNICATION` | 使能 `MyECU_oCAN00_Tx` PDU 组 |
| `CC_CN_CAN00_5e566ad9_RX_DM` | `CanSMIndication = FULL_COMMUNICATION` | 使能 RX 诊断（DM）               |




### 10.3 注意事项

- 电机调试帧（0x511）不走 Com 发送：`MotorFoc_OpenLoopCan_Init/Transmit()` 中先 `Com_IpduGroupStop(MyECU_oCAN00_Tx_1ae5d671)` 停掉 Com 组，再 `CanIf_Transmit` 直发，避免与 Com 的 0x511 PDU 冲突。
- 因此 BswM 的 TX PDU 组使能规则主要服务于 Com 组内的其他报文（0x200 等）。

---



## 11. Can / CanIf / Com 模块

> 详细配置文档：Can → [DaVinci_Can.md](DaVinci_Modules/DaVinci_Can.md) · CanIf → [DaVinci_CanIf.md](DaVinci_Modules/DaVinci_CanIf.md) · Com → [DaVinci_Com.md](DaVinci_Modules/DaVinci_Com.md)



### 11.1 Can（MCAN0）

`CanConfigSet > CT_CAN00_9df8a959`：


| 参数                                                 | 值                                                                                         |
| -------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| `CanControllerBaseAddress` / `CanBasisAddressEnum` | 4028662016 / `M_CAN0`                                                                     |
| 波特率                                                | 500 kbps（`CanControllerBaudRate=500`，时钟 80 MHz，Prescaler=8，PropSeg=7，Seg1=8，Seg2=4，SJW=1） |
| FD 波特率                                             | 2000 kbps（Prescaler=1，PropSeg=16，Seg1=15，Seg2=8，SSP=80）                                   |
| `CanFdSupport`                                     | `FULL`                                                                                    |
| Rx/Tx/Busoff 处理                                    | INTERRUPT                                                                                 |
| `CanUseCore`                                       | `Core_0`                                                                                  |




### 11.2 CanIf


| PDU                                 | 类型              | CAN ID          | DLC    | 用途             |
| ----------------------------------- | --------------- | --------------- | ------ | -------------- |
| `msg_MyECU_Lamp_oCAN00_41befc25_Tx` | STANDARD_FD_CAN | **0x511（1297）** | **32** | 电机调试/观测帧（应用直发） |
| `msg_Transmit_oCAN00_29db34a4_Tx`   | STANDARD_CAN    | 0x200（512）      | 1      | Com 周期发送       |
| `msg_Receive_oCAN00_76f25845_Rx`    | STANDARD_CAN    | 0x210（528）      | 1      | Com 接收         |


Tx 缓冲：`CHNL_0fb271d2`（size 2、最大 PDU 长度 32、`PRIO_BY_CANID`）。

### 11.3 Com

- `ComConfig` 中 0x511 组（`msg_MyECU_Lamp_oCAN00_*_Tx`）映射了 MotorFoc 观测信号（`MotorFoc_IuRaw_A`、`MotorFoc_Iv_A`、`MotorFoc_FaultIv_A` 等），用于 RTE/标定侧；应用层实际用 `CanIf_Transmit` 直发同一 ID。
- `ComMainFunctionTx` 事件挂到 `Default_BSW_ASync_Task_10ms`（10 ms 报警 `Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx`）。



### 11.4 注意事项

- 0x511 是 CAN FD（DLC 32），总线另一端必须支持 FD 且仲裁波特率 500 k、数据段 2 M。
- 若想走 Com 发送 0x511，需去掉 `Com_IpduGroupStop` 与直发逻辑，并把 `ComTxMode` 周期配好；当前工程刻意绕开 Com 以便 1 ms 内自由组帧。

---



## 12. NvM / Fee / Fls 模块（零位标定存储）

> 详细配置文档：NvM → [DaVinci_NvM.md](DaVinci_Modules/DaVinci_NvM.md) · Fee → [DaVinci_Fee.md](DaVinci_Modules/DaVinci_Fee.md) · Fls → [DaVinci_Fls.md](DaVinci_Modules/DaVinci_Fls.md)



### 12.1 Fls（DFlash）


| 参数               | 值                                                     |
| ---------------- | ----------------------------------------------------- |
| `FlsBaseAddress` | 2936012800（0xAF000000，DMU DFlash）                     |
| `FlsTotalSize`   | 131072（128 KB），2 × 64 KB 扇区，页 8 B                     |
| `FlsDefaultMode` | `MEMIF_MODE_SLOW`                                     |
| `FlsCallCycle`   | 0.01                                                  |
| 通知               | `Fee_JobEndNotification` / `Fee_JobErrorNotification` |




### 12.2 Fee


| Fee 块                         | `FeeBlockNumber` | 大小  | 说明                                |
| ----------------------------- | ---------------- | --- | --------------------------------- |
| `FeeBlockConfiguration`       | 16               | 4 B | 通用块（对应 NvMConfigBlock）            |
| `FeeBlockConfiguration_cons0` | 17               | 4 B | 通用块一致性副本                          |
| `FeeBlock_MotorZeroCal`       | 32               | 6 B | **电机零位角度**（NvMBlock_MotorZeroCal） |


`FeeGeneral`：`FeeVirtualPageSize=8`、`FeeBlockTypeConfigured=FEE_DOUBLE_SECTOR_DATA_ONLY`、`FeePollingMode=false`（Fee 主函数 10 ms）。

### 12.3 NvM


| 块                       | Block Id | 类型                    | 长度    | CRC   |
| ----------------------- | -------- | --------------------- | ----- | ----- |
| `NvMBlock_MotorZeroCal` | 2        | `NVM_BLOCK_NATIVE`    | 4 B   | CRC16 |
| `NvMConfigBlock`        | 1        | `NVM_BLOCK_REDUNDANT` | 2×2 B | CRC16 |


`NvMCommon`：`NvMPollingMode=true`、`NvMMainFunctionPeriod=0.01`、`NvMDrvModeSwitch=true`。

### 12.4 应用使用（`MotorZeroCal.c`）

- 上电：等 `Fee_GetStatus()==MEMIF_IDLE` 且 `FeeInitGCState==COMPLETE` 后 `NvM_ReadBlock` 恢复 ANG_BASE。
- 标定成功：`NvM_WriteBlock(NvMBlock_MotorZeroCal, ...)`（在 StartApp 1 ms 任务中排队，不在 MotorTask 中直接调用）。
- 写前 `NvM_CancelJobs` 清队列，写后 `NvM_GetErrorStatus` 确认。

---



## 13. ResourceM 模块（多核归属）

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_ResourceM.md](DaVinci_Modules/DaVinci_ResourceM.md)

DaVinci 路径：`ResourceM > ResourceMMcalConfig_0`。


| 核     | 模块  | 资源                                                          |
| ----- | --- | ----------------------------------------------------------- |
| Core0 | SPI | `SpiHwConfigurationQspi_35584`（SBC）                         |
| Core0 | ADC | `AdcHwUnit_ADC8`                                            |
| Core1 | ADC | `AdcHwUnit_ADC0`、`AdcHwUnit_ADC2`、`AdcHwUnit_ADC3`          |
| Core1 | PWM | `PwmChannel_9180IH1/IH2/IH3/REF`                            |
| Core1 | SPI | `SpiHwConfigurationQspi_9183`、`SpiHwConfigurationQspi_5012` |


意义：MCAL 模块的 `Init` 按核执行（EcuM callout 中已体现），且生成代码会做核间一致性检查；电机相关外设全部在 Core1，BSW（CAN/COM）留在 Core0。

---



## 14. Sbc 模块（TLF35584）

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Sbc.md](DaVinci_Modules/DaVinci_Sbc.md)

DaVinci 路径：`Sbc`（`Sbc_30_Tlf35584`）。


| 参数                            | 值                                       |
| ----------------------------- | --------------------------------------- |
| `SbcSpiChannelRef`            | `SpiChannel_35584`                      |
| `SbcSpiSequenceRef`           | `SpiSequence_35584`                     |
| `SbcErrPinMonitor`            | true                                    |
| `SbcErrPinRecoveryTime`       | `ERREC_1_MS`                            |
| 上电输出（`SbcEnableSupplyNormal`） | LDO_Stby、Tracker1/2、LDO_Com、VoltRef 全使能 |


> 该工程中 SBC 的初始化/配置写入在 `Sbc_30_Tlf35584` 驱动 + `Tle9180` 电源时序里完成，DaVinci 侧只需保证 SPI 通道引用正确。

---



## 15. Rte / 应用 SW-C 映射

> 详细配置文档（操作步骤 + 截图位）：[DaVinci_Rte.md](DaVinci_Modules/DaVinci_Rte.md)



### 15.1 SW-C 与端口


| SW-C            | 核     | 运行实体（Runnable）                                                                                       | 触发                                    |
| --------------- | ----- | ---------------------------------------------------------------------------------------------------- | ------------------------------------- |
| `StartApp`      | Core0 | `StartApp_Cyclic1ms/10ms/250ms/1000ms`、`StartApp_Init`                                               | RTE TimingEvent（1/10/250/1000 ms）     |
| `MotorControll` | Core1 | `MotorControll_Init`、`MotorControll_MainFunction`                                                    | `Rte_Ev_Cyclic_MotorTask_0_1ms`（1 ms） |
| `MotorCdd`      | Core1 | `MotorCdd_Init`、`MotorCdd_MainFunction`、`AdcSampleReady`、`Pp_MotorCdd_EnableInverter_EnableInverter` | 1 ms 事件 / ADC 事件 / 服务调用               |




### 15.2 关键 RTE 数据


| 数据                                          | 方向                       | 说明                                          |
| ------------------------------------------- | ------------------------ | ------------------------------------------- |
| `Pp_MotorCtrlCmd_MotorMode`                 | MotorControll → MotorCdd | 模式（IDLE/OPEN_LOOP/CALIBRATION/CLOSED_LOOP…） |
| `Pp_MotorCurrentRef_Id_Ref / Iq_Ref`        | MotorControll → MotorCdd | Id/Iq 电流参考                                  |
| `Pp_MotorElectricalAngle_ElectricAngle`     | MotorCdd → MotorControll | 电角度反馈                                       |
| `Pp_MotorCdd_EnableInverter_EnableInverter` | 服务端                      | 逆变器使能门控（依赖 ADC offset ready）                |


> 快速环（10 kHz ISR）不直接经 RTE，而是读 `MotorCdd_CmdMirror`（volatile 镜像，由 1 ms 任务写入），避免 RTE 开销与锁问题。



### 15.3 生成产物


| 路径                            | 内容                                       |
| ----------------------------- | ---------------------------------------- |
| `Config\ECUC\last364_*.arxml` | DaVinci 工程配置                             |
| `Appl\GenData`                | RTE 头文件/源码（`Rte_*.h`、`Rte_*.c`）          |
| `BSW364`                      | MICROSAR BSW 生成代码                        |
| `MCAL364`                     | Infineon MCAL 生成代码（Adc/Spi/Pwm/Port/…）   |
| `Debug`                       | 编译输出（TASKING，Lcf_Tasking_Tricore_Tc.lsl） |


---



## 16. DaVinci 配置操作顺序（推荐）

1. **Mcu**：时钟（PLL/分配/参考点）→ GTM 通道与触发 → 资源分配。
2. **Port**：按原理图建 `PortPin`（电机 6 路 GTM、9183 控制脚、QSPI2/3、CAN、SBC、LED）。
3. **Pwm**：9180REF/IH1/IH2/IH3 通道（周期 10000、中心对齐、时钟 CMU0）。
4. **Adc**：硬件单元（主/从）、输入类、G0/G2/G3 组、通道、GTM 触发、通知函数名。
5. **Spi**：QSPI1/2/3 外设、通道、Job、Sequence。
6. **Dio**：9183 控制脚、LED、测试点。
7. **ResourceM**：把电机外设（ADC0/2/3、PWM、QSPI2/3）分给 Core1。
8. **Irq**：ADC0 SR0（CAT1/83/CPU1）、ADC8 SR0、CAN0 SR0、STM1。
9. **Os**：双核任务/报警/ISR（MotorTask、BswCore1Task、AdcIsr_G0…）。
10. **EcuM**：DriverInitList、多核 callout、RUN 请求。
11. **BswM**：初始化动作表、CAN PDU 组规则。
12. **Can/CanIf/Com**：MCAN0 波特率、PDU（0x511/0x200/0x210）、Com 信号（可导入 DBC）。
13. **NvM/Fee/Fls**：DFlash 参数、Fee 块、NvM 块（MotorZeroCal）。
14. **Rte**：SW-C 映射、事件/数据一致性检查，生成代码。
15. 编译（TASKING）→ 下载 → CANoe/UDE 调试。

---



## 17. 常见问题排查（结合本工程）


| 现象            | 排查点                                                                                                                                                                                                                      |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| PWM 无输出       | ① P02.1/2/3 是否 ALT1；② ATOM0 CH1/2/3 是否 `USED_BY_PWM`；③ PwmPeriod/时钟参考点是否 100 MHz；④ 应用层 `MotorCdd_PwmComplementaryInit` 是否已执行（TOUTSEL0=0x28882222）。                                                                       |
| 只有上桥无下桥       | GTM CDTM 死区/路径未使能（`CH_CTRL2` DT0_1/DT1_1…），或 IL 脚 Port 模式不对。                                                                                                                                                             |
| ADC 无数据/无中断   | ① ResourceM 中 G0/G2/G3 是否 Core1；② Core1 是否二次 `Adc_Init` + `SetupResultBuffer` + `EnableHardwareTrigger`；③ `SRC_VADC_G0_SR0.SRE=1`；④ GTM CH7 `USED_BY_ADC` + `GtmTriggerForAdc_0 = TRIG_8`；⑤ 通知函数名与 `AdcNotification` 一致。 |
| 采样点不对/有开关噪声   | 调 `MotorCdd_AdcSetTriggerTick()`（默认 5000，限幅 400~9600）。                                                                                                                                                                   |
| 角度读不到         | QSPI2 CS 极性/32-bit BACON（CS=SLSO2、LAST=1）；`Spi_Init` 后应用重写 ECON/SSOC；P14.6 是否 ALT3 且初始 HIGH。                                                                                                                             |
| 9183 通信失败     | 24-bit 帧掩码；QSPI3 4 MHz、TRAILING 边沿；INH/ENA/SOFF 时序；ERR 引脚状态。                                                                                                                                                             |
| CAN 0x511 发不出 | 与 Com 组冲突（需 `Com_IpduGroupStop`）；CanIf Tx PDU 为 STANDARD_FD_CAN、DLC 32；总线 FD 配置一致。                                                                                                                                       |
| 零位存不住         | Fee 是否 COMPLETE（`FeeInitGCState`）；NvM 块大小/CRC 一致；`NvM_WriteBlock` 是否在 1 ms 任务轮询中被处理。                                                                                                                                     |
| 改配置后编译报错      | 检查 ATOM/通道重复分配、时钟参考点改名、通知函数名拼写、ResourceM 归属。                                                                                                                                                                             |


---



## 18. 相关文件索引

- DaVinci 工程：`last364.dpa`、`DConfig`（DaVinci Configurator 项目）
- 模块配置：`Config\ECUC\last364_{Mcu,Port,Pwm,Adc,Spi,Dio,Irq,Os,EcuM,BswM,Can,CanIf,Com,NvM,Fee,Fls,ResourceM,Sbc,Rte}_*_ecuc.arxml`
- 应用代码：`Appl\Source\CDD\MotorFoc\`、`CDD\TLE9180\`、`CDD\TLE5012\`、`MotorControll.c`、`StartApp.c`
- 原理图：`Schematic PDF_Motor.pdf`、`Schematic PDF_Can.pdf`、`Schematic PDF_Power.pdf`
- 芯片手册：`infineon-tle9180d-31qk-datasheet-en.pdf`、`infineon-tle9183qk-datasheet-en.pdf`、`infineon-tle5012bd-datasheet-en.pdf`、`infineon-sak-tc36xdp-datasheet-en.pdf`
