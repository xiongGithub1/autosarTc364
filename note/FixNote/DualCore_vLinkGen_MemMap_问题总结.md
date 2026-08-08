# last364 双核 + vLinkGen + vBRS 迁移问题总结

> 项目：`last364`（TC364/TC367，Tasking VX v6.2r2 + Vector MICROSAR CBD2200508_D00）  
> 目标：Core0 跑 BSW/CAN，Core1 跑电机栈，使用 vLinkGen 链接脚本 + vBRS 启动  
> 更新：2026-08-01

---

## 目录

1. [背景](#1-背景)
2. [链接错误演进与解决方法](#2-链接错误演进与解决方法)
3. [E123 `_lc_ub_table` 问题详解](#3-e123-_lc_ub_table-问题详解)
4. [TASKING 工程关键设置](#4-tasking-工程关键设置cproject)
5. [MemMap / vLinkGen 配置](#5-memmap--vlinkgen-配置)
6. [vBRS 集成](#6-vbrs-集成)
7. [EcuM / Os 双核（配置侧）](#7-ecum--os-双核配置侧)
8. [关键文件路径速查](#8-关键文件路径速查)
9. [禁止操作清单](#9-禁止操作清单)
10. [建议验证步骤](#10-建议验证步骤)
11. [跨核 SetRelAlarm 与 Os X-Signal](#11-跨核-setrelalarm-与-os-x-signal2026-07-31)
12. [XSignalIsr Interrupt Source 错误 → Trap Class 3](#12-xsignalisr-interrupt-source-错误--trap-class-32026-07-31)
13. [MotorTask 未激活时 Alarm SetEvent → ErrorHook](#13-motortask-未激活时-alarm-setevent--errorhook2026-07-31)
14. [SystemTimer1 TicksPerBase 与 Core1 启动链](#15-systemtimer1-ticksperbase-与-core1-启动链2026-08-01)
15. [参考](#16-参考)

---

## 1. 背景

从单核 TC364 工程迁移到双核 AUTOSAR 架构时，需要同时解决：

- **MemMap / vLinkGen**：MSR 段名与链接脚本逻辑组对齐
- **vBRS 启动**：替换 Tasking 默认 `cstart` 与旧 `Autosar_Startup.c`
- **Tasking 链接器**：双核 LSL、近址寻址、拷贝表与 vBRS 初始化分工
- **EcuM / Os**：多核配置与代码生成一致性

---

## 2. 链接错误演进与解决方法

| 阶段 | 报错 | 根因 | 解决方法 |
|------|------|------|----------|
| 1 | `_MSR_VAR_INIT_START` 等符号 unresolved | 仍使用旧 `Appl/newTc364.lsl`，无 vLinkGen 段符号 | 链接脚本改为 `Appl/Source/vLinkGen_Template.lsl` |
| 2 | `ltc E157: cannot find address space 3`（`.zrodata.BswM_*` 等） | MemMap 未关联 vLinkGen + 编译器 `--default-near-size=8` 生成 near 段，LSL 无 address space 3 | MemMap 配置 MSR → vLinkGen LogicalGroup；`.cproject` 设置 `nearSize=0`；`MemMapGeneratePragmasForNearAddressing=false` |
| 3 | `brsStartupEntry` unresolved | 缺少 vBRS 源文件；空 stub 头文件遮蔽真实 `BrsHw.h` | 从 StartApplication 拷贝 vBRS 源/头；删除空 stub |
| 4 | `_SMALL_DATA_TC1` / `_LITERAL_DATA_TC1` 等 unresolved | LSL 定义 `_start_tc1` 后链接器拉入 `cstart_tc1.o`，需要 Core1 near-data 符号 | 在 `vLinkGen_Template.lsl` 末尾增加 Core1 near-data 符号块（**勿删除**） |
| 5 | `Unknown compiler` in `Brs_MemMap.h` | 未定义 `BRS_COMP_TASKING` | 新增 `Appl/Include/BrsCompiler_Cfg.h`，由 `BrsHw.h` / `Brs_MemMap.h` 包含 |
| 6 | SchM ComM 符号重复定义 | `BrsMain.c` 与 `Appl/TSC_SchM_ComM.c` 均提供 ComM SchM | 从 `BrsMain.c` 移除 ComM SchM 实现，保留 `TSC_SchM_*.c` |
| 7 | `ApplCanInterruptDisable/Restore` unresolved | 缺少 Can callout | 在 `Can_Callout_Stubs.c` 中实现中断 disable/restore |
| 8 | `Appl_LockEndinit` / `BrsHwLockInitInline` unresolved | `Appl_LockEndinit` 放在非 `BrsHw.c` 的 TU，static inline 未实例化 | Endinit 相关实现仅保留在 `BrsHw.c` |
| 9 | **`ltc E123: section ".bss.MSR_VAR_NO_INIT" requires initialization code in task "task1" for symbol "_lc_ub_table"`** | Tasking 拷贝表机制与 vBRS 初始化冲突 | 链接器勾选 **Do not use standard copy table for initialization**（见第 4 节） |
| 10 | **Core1 跑飞 / `CALL _c_init_tc1`** | `OsCoreEntrySymbol=_start_tc1` 导致链接器从 `libc_fpu.a` 拉入 `cstart_tc1.o` | DaVinci：**Os → OsCore1 → OsCoreEntrySymbol = `brsStartupEntry`**，Generate Os |
| 11 | **`SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms)` → `OS_STATUS_FUNCTION_UNAVAILABLE`** | Core0 `Rte_Start()` 跨核设置 Core1 Alarm，但 **Os X-Signal 未启用**（`OS_CFG_XSIGNAL=STD_OFF`） | 配置 **Os X-Signal**（双向 Channel + XSignalIsr + `SetRelAlarm` API），Generate Os（见第 11 节） |
| 12 | **Core1 MPU `0x00010006`（Adc 空指针）** | Core1 `EcuM_AL_DriverInitOne` 调用 `Adc_GetStartupCalStatus()`，但 ADC 仅在 Core0 Init | `EcuM_Callout_Stubs.c`：MCAL Init 加 `GetCoreID()==ECUM_CORE_ID_BSW` 守卫 |
| 13 | **`Os_Api_Init()` 后 Trap @ `0x80022960`（`osTrap_3_Core0` / Class 3）** | X-Signal 启用后 **`XSignalIsr` 的 `OsIsrInterruptSource = 1`**，写坏 SRC；两核共用同一 Source | 改为 **GPSR** 正确偏移（2448 / 2480），Generate Os（见第 12 节） |
| 14 | **`ErrorHook`: `AlarmActionSetEvent` / `E_OS_STATE(7)` / `OS_STATUS_STATE_1`** | Core0 `SetRelAlarm(MotorTask)` 早于 Core1 `ActivateTask(MotorTask)`，Alarm 对 **SUSPENDED** 任务 SetEvent | **ESCAN00078832**：Core0 等 Core1 `Rte_Start` 完成；`Default_Init_Task` 改 **FULL**（见第 13 节） |
| 15 | **`Rte_InitState_1` ~20s 才变 3、`StartApp_Cyclic1msCounter` 迟迟不涨** | Core1 启动异常（Timer 配错 / ErrorHook）→ Core0 在 `wait(Rte_InitState_1)` 空转；非 StartApp 本身慢 | **`SystemTimer1 OsCounterTicksPerBase` 改为 100000**（与 Core0 一致）；**不要**在 Trusted 里重复 ActivateTask（见第 15 节） |
| 16 | **`MotorCdd_Os1msCounter` 百万级、`WaitEvent` 几乎不阻塞** | `TicksPerBase=1` 时 STM1 比较/Reload 与 1ms OS tick 不匹配，Counter ISR 异常频繁 | 同第 15 节；Alarm 使用 `RTE_MSEC_SystemTimer1()` 宏，禁止裸 `(TickType)1U` |
| 17 | **`Default_Init_Task_Core1_Trusted` 里 SetRelAlarm/ActivateTask 导致 ErrorHook** | 与 `Rte_Start` 重复激活；裸 tick 值错误；Trusted 职责仅是开中断 | **删除** Trusted 中 MotorTask 启动代码，仅保留 `Os_InitialEnableInterruptSources`（见第 15.4 节） |
| 18 | **`WaitEvent` → `OS_STATUS_DISABLEDINT`（Core1 ErrorHook）** | `MotorTask` 在 `Os_InitialEnableInterruptSources` 之前被调度 | Vector 标准顺序：Init Task → Trusted 开中断 → 应用 Task；**不必**把 ActivateTask 移到 Trusted |

---

## 3. E123 `_lc_ub_table` 问题详解

### 3.1 报错示例

```
ltc E123: section ".bss.MSR_VAR_NO_INIT" (variable BswM_ActionListQueue)
          requires initialization code in task "task1" for symbol "_lc_ub_table"
ltc F019: unrecoverable error: fatal locate error
```

### 3.2 原因

存在两套互斥的内存初始化机制：

| 机制 | 负责方 | 说明 |
|------|--------|------|
| Tasking 默认 | `cstart` + `_lc_ub_table` 拷贝/清零表 | LSL 中 `architecture` 含 `copytable`；定义 `_start_tc1` 时会链接 `cstart_tc1.o`，期望 Tasking 为 Core1 生成 init 表 |
| vBRS / vLinkGen | `BrsHwStartup.c`、`BrsMainStartup.c` | 按 vLinkGen 配置段做 ROM→RAM 拷贝与 BSS 清零 |

工程已采用 vBRS 启动，若链接器仍尝试为标准拷贝表生成 Core1（task1）初始化项，就会报 E123。

Vector StartApplication 参考 Makefile：

```makefile
-Wl--user-provided-initialization-code
```

### 3.3 解决方法

在 `.cproject` → **Linker → Miscellaneous** 中勾选：

> **Do not use standard copy table for initialization**

对应链接参数：`--user-provided-initialization-code`（`-i`）

**Debug 与 Release 均需配置**，且 Release 的 LSL 路径也要指向 `vLinkGen_Template.lsl`（不要再用 `newTc364.lsl`）。

配置完成后 **Clean + Rebuild**。

---

## 4. TASKING 工程关键设置（`.cproject`）

### 4.1 编译器

| 选项 | 推荐值 | 说明 |
|------|--------|------|
| Threshold for putting data in __near (`nearSize`) | `0` | 避免生成 LSL 未定义的 near 段 |
| Defined symbols | `BRS_COMP_TASKING`、`BRS_PLATFORM_AURIX` | vBRS 识别编译器与平台 |

### 4.2 链接器

| 选项 | 推荐值 |
|------|--------|
| Linker script file | `Appl/Source/vLinkGen_Template.lsl` |
| Do not use standard copy table for initialization | **true** |
| Link default libraries | **false**（即 `--no-default-libraries`，避免 `cstart_tc1.o` 覆盖 `_start_tc1`） |
| Libraries（手动补充） | `-lc_fpu`、`-lfp_fpu`、`-lrt`（须带 `-l` 前缀，不能只写 `c_fpu`） |
| Library search path | `${eclipse_home}/../lib/tc162`（即 TASKING 安装目录下 `ctc/lib/tc162`） |
| Generate Intel Hex | 按需 |

---

## 5. MemMap / vLinkGen 配置

### 5.1 DaVinci / ECUC（`last364_MemMap_MemMap_ecuc.arxml`）

- 各 MSR 寻址模式（`MSR_VAR_INIT`、`MSR_VAR_NO_INIT`、`MSR_CONST` 等）通过 **`MemMapLinkerLogicalGroupRef`** 指向 vLinkGen 逻辑组
- **`MemMapGeneratePragmasForNearAddressing = false`**：不生成 near 寻址 pragma，避免 address space 3 错误
- **`MemMapTypedPragmas`**：按实际生成结果配置（若启用 near 寻址须 LSL 同步支持）
- **`MemMapGeneration = FULL`**
- DaVinci 中 **`MemMap_ARM_Derivative = None`**（`.dpa`），避免错误 ARM 衍生配置导致 MemMap 选项灰化

### 5.2 链接脚本（`Appl/Source/vLinkGen_Template.lsl`）

- 由 vLinkGen 生成，包含双核内存布局与 MSR 段映射
- 文件开头 `architecture` 含 `copytable`（Tasking 架构要求）；配合 `--user-provided-initialization-code` 后，实际 init 由 vBRS 执行
- **文件末尾 Core1 near-data 块必须保留**（约 1780–1806 行）：

```lsl
  /* Tasking cstart_tc1.o needs Core1 near-address symbols when _start_tc1 is defined in LSL */
  group a0_tc1 ...
  "_SMALL_DATA_TC1" := ...
  "_LITERAL_DATA_TC1" := ...
  "_A8_DATA_TC1" := ...
  "_A9_DATA_TC1" := ...
```

### 5.3 废弃文件

- **`Appl/newTc364.lsl`**：单核旧脚本，**不要再用于链接**

---

## 6. vBRS 集成

### 6.1 源文件位置

vBRS **不在** `Components/vBRS`，参考实现位于 SIP：

```
CBD2200508_D00/.../StartApplication/Appl/Source/
CBD2200508_D00/.../StartApplication/Appl/Include/
```

### 6.2 已拷贝到 last364 的文件

**Source（6 个）：**

- `BrsHw.c`
- `BrsHwStartup.c`
- `BrsHwIntTb.c`
- `BrsMain.c`
- `BrsMainStartup.c`
- `BrsMain_Callout_Stubs.c`

**Include：**

- `BrsHw.h`、`BrsMain.h`、`BrsMain_Types.h`、`Brs_MemMap.h` 等
- **`BrsCompiler_Cfg.h`**（项目新增，定义 `BRS_COMP_TASKING`）

**GenData：**

- `vBrsCfg.h`、`vBrs_Lcfg.c`、`vLinkGen_Lcfg.c`

### 6.3 不要从 StartApplication 覆盖的文件

- `BswInit.c`（保留项目自有 BSW 初始化）
- `BswM_Callout_Stubs.c`（保留项目 callout）

### 6.4 需排除 / 删除的冲突项

| 文件 | 处理 | 原因 |
|------|------|------|
| `Autosar_Startup.c` | 从构建排除 | 与 `BrsMain.c` 的 `main` 冲突 |
| `Appl_HwStartup.c` | 从构建排除 | 由 `BrsHwStartup.c` 替代 |
| 空 stub `Appl/BrsHw.h`、`Appl/BrsMain_Types.h` | 已删除 | 遮蔽真实 Include 路径 |

### 6.5 SchM 与 CAN

- 保留 `Appl/TSC_SchM_*.c` 作为 SchM 桩
- `BrsMain.c` 中 **不要** 再实现已在 TSC 中提供的 SchM（如 ComM）
- 若启用 `BRS_ENABLE_CAN_SUPPORT`，可能与 TSC SchM 重复，需二选一

### 6.6 Can Callout

- `Can_Callout_Stubs.c`：`ApplCanInterruptDisable` / `ApplCanInterruptRestore`
- Endinit（`Appl_LockEndinit` 等）仅在 **`BrsHw.c`** 中实现

---

## 7. EcuM / Os 双核（配置侧）

| 问题 | 状态 / 说明 |
|------|-------------|
| `EcuMSlaveCoreHandling=true` 但 `ECUM_NUMBER_OF_CORES=1` | 需在 Os 多核配置正确后 **重新生成 EcuM**；当前 GenData 已为 `ECUM_NUMBER_OF_CORES (2u)` |
| `EcuMNormalMcuModeRef` 路径断裂 | 在 EcuM ECUC 中重新关联 McuMode |
| RTE EcuM timing 校验错误 | Os/EcuM 生成顺序与引用一致后重新 Generate |
| **Os X-Signal 跨核 API** | **已配置**（2026-07-31 Generate）；`OS_CFG_XSIGNAL=STD_ON`，见第 11 节；**Interrupt Source 须按第 12 节修正** |
| 运行时 Core1 启动 / ErrorHook | 链接通过后上板验证 |

---

## 8. 关键文件路径速查

```
last364/
├── .cproject                          # nearSize=0；LSL；userProvidedInitCode
├── Appl/Source/vLinkGen_Template.lsl  # vLinkGen 链接脚本 + Core1 near 符号
├── Appl/Source/BrsMain.c              # ESCAN00078832 wait；Core1 Trusted 仅开中断（§15）
├── Appl/Source/Brs*.c                 # vBRS 启动与硬件抽象
├── Appl/GenData/Os_Hal_Cfg.h          # OSTICKSPERBASE_SystemTimer / SystemTimer1（§15）
├── Appl/Include/BrsCompiler_Cfg.h     # BRS_COMP_TASKING
├── Appl/Source/Can_Callout_Stubs.c    # Can 中断 callout
├── Appl/TSC_SchM_*.c                  # SchM 桩（勿与 BrsMain 重复）
├── Appl/GenData/vLinkGen_Lcfg.c
├── Appl/GenData/vBrs_Lcfg.c
├── Config/ECUC/last364_MemMap_MemMap_ecuc.arxml
├── Config/ECUC/last364_Os_Os_ecuc.arxml         # X-Signal Channel / XSignalIsr
├── Appl/GenData/Os_XSignal_Cfg.h                # OS_CFG_XSIGNAL
├── Appl/GenData/Os_XSignal_Lcfg.c               # Channel / SendPort / RecvIsr
├── Appl/GenData/Os_Hal_Interrupt_Lcfg.c         # XSignalIsr Source（须 0x990/0x9B0，见第 12 节）
└── note/DualCore_vLinkGen_MemMap_问题总结.md   # 本文档
```

---

## 9. 禁止操作清单

1. **不要** 链接 `newTc364.lsl` 与 `vLinkGen_Template.lsl` 混用
2. **不要** 删除 LSL 末尾 `_SMALL_DATA_TC1` 等 Core1 符号块
3. **不要** 同时编译 `Autosar_Startup.c` 与 `BrsMain.c`
4. **不要** 在未改 LSL 的情况下开启 `MemMapGeneratePragmasForNearAddressing=true`
5. **不要** 把 `Appl_LockEndinit` 放到 `BrsHw.c` 以外的 TU（static inline 链接问题）
6. **不要** 去掉 `--user-provided-initialization-code` 却仍使用 vBRS 启动（会再现 E123）
7. **不要** 将 Core1 `SystemTimer1` 的 `OsCounterTicksPerBase` 设为 **1**（须与 Core0 一致为 **100000**，见 §15）
8. **不要** 在 `Default_Init_Task_Core1_Trusted` 中 `SetRelAlarm` / `ActivateTask(MotorTask)`（见 §15.4）

---

## 10. 建议验证步骤

1. Debug / Release 均确认 LSL 与 `userProvidedInitCode=true`
2. **Project → Clean → Build**
3. 链接成功后再查 map 中 Core0/Core1 段分布
4. 上板：Core0 BSW 启动、Core1 电机任务、EcuM 多核状态
5. 若出现 SchM E108 重复：检查 `BRS_ENABLE_CAN_SUPPORT` 与 `TSC_SchM_*.c` 是否冲突
6. **X-Signal Interrupt Source**：Generate 后确认 `Os_Hal_Interrupt_Lcfg.c` 中 XSignalIsr 的 `Source` 为 `0x990` / `0x9B0`（**不是 `0x1`**）
7. **X-Signal 验证**：`SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, 1, 1)` 返回 `E_OK`；`MotorTask` 收到 1 ms TimingEvent；map 中 `Os_XSigRecv_SetRelAlarm` 已被引用

---

## 11. 跨核 SetRelAlarm 与 Os X-Signal（2026-07-31）

### 11.1 现象

Core0 执行 `EcuM_StartupTwo()` → `Rte_Start()` 时：

```c
SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, 1, 1);
→ OS_STATUS_FUNCTION_UNAVAILABLE   // E_OS_SYS_FUNCTION_UNAVAILABLE / 0xF9
```

**不是** Alarm 参数错误或 Alarm 已激活，而是 **跨核 OS API 未配置**。

### 11.2 根因

| 对象 | 归属 |
|------|------|
| `Rte_Al_TE_MotorTask_0_1ms` | Core1 / `SystemTimer1` / `MotorTask` |
| `Rte_Start()` 调用点 | Core0（Master Core，`Appl/GenData/Rte.c`） |

Vector 多核 RTE 由 **Master Core 的 `Rte_Start()`** 统一启动各核 TimingEvent Alarm。Alarm 在 Core1 上时，Core0 的 `SetRelAlarm` 走跨核路径 `Os_XSigSend_SetRelAlarm()`。

配置前状态：

```c
// Os_XSignal_Cfg.h（旧）
#define OS_CFG_XSIGNAL       (STD_OFF)
// Os_Core_Lcfg.c
.XSignal = NULL_PTR
```

`OS_CFG_XSIGNAL=STD_OFF` 时，`Os_XSigSendSync()` 直接返回 `OS_STATUS_FUNCTION_UNAVAILABLE`。

调用链：

```
Core0 Rte_Start()
  → SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms)
    → Os_Api_SetRelAlarm()  // Alarm 不在本地核
      → Os_XSigSend_SetRelAlarm()
        → Os_XSigSendSync()
          → OS_STATUS_FUNCTION_UNAVAILABLE   // X-Signal 未启用
```

AccessRights 无问题：`Rte_Al_TE_MotorTask_0_1ms` 的 `AccessingApplications` 已包含 `SystemApplication_OsCore0`。

### 11.3 解决方法：启用 Os X-Signal

参考 SIP **StartApplication**（`CBD2200508_Os_Os_ecuc.arxml`），在 last364 中配置 **双核简化版**（仅 Core0 ↔ Core1）。

#### DaVinci 配置清单

| 步骤 | 位置 | 内容 |
|------|------|------|
| 1 | **Os → OsOS** | `OsUseXSignalAsyncApiCalls = false`（同步 X-Signal，`Rte_Start` 需等待返回） |
| 2 | **Os → ISRs** | 新建 `XSignalIsr_OsCore0`、`XSignalIsr_OsCore1`：Cat2、勾选 **Cross-core channel receiver interrupt**、`SpecialFunctionName = Os_XSigRecvIsrHandler` |
| 3 | **XSignalIsr → OsIsrXSignalReceiver** | ProvidedApis 至少含 **`SetRelAlarm`**、**`CancelAlarm`**、**`ActivateTask`**、**`SetEvent`** |
| 4 | **Os Applications** | `SystemApplication_OsCore0` 挂 `XSignalIsr_OsCore0`；`OsApplication_OsCore1` 挂 `XSignalIsr_OsCore1` |
| 5 | **OsCore0** | Add **Cross-Core API Call Channel** `XSignalChl_OsCore1` → Receiver ISR = `XSignalIsr_OsCore1`，Channel Size = 1 |
| 6 | **OsCore1** | Add **Cross-Core API Call Channel** `XSignalChl_OsCore0` → Receiver ISR = `XSignalIsr_OsCore0`，Channel Size = 1 |
| 7 | Generate | **Validate → Generate Os** |

ECUC 路径（Basic Editor）：

```
ActiveEcuC/Os/OsOS/OsUseXSignalAsyncApiCalls = false
ActiveEcuC/Os/OsCore0/XSignalChl_OsCore1  → XSignalIsr_OsCore1
ActiveEcuC/Os/OsCore1/XSignalChl_OsCore0  → XSignalIsr_OsCore0
ActiveEcuC/Os/XSignalIsr_OsCore0|1        → OsIsrXSignalReceiver (含 SetRelAlarm)
```

### 11.4 生成代码验证（2026-07-31 14:18，**正常**）

| 检查项 | 期望 | 实际 |
|--------|------|------|
| `Os_XSignal_Cfg.h` | `OS_CFG_XSIGNAL = STD_ON` | ✅ `STD_ON` |
| `OS_CFG_XSIG_USEASYNC` | `STD_OFF` | ✅ `STD_OFF` |
| 每核 X-Signal ISR 数 | 1 | ✅ Core0/Core1 各 1 |
| 双向 SendPort | Core0→Core1、Core1→Core0 | ✅ `OsCfg_XSig_OsCore0_Send0`、`OsCfg_XSig_OsCore1_Send0` |
| `Os_Core_Lcfg.c` `.XSignal` | 非 `NULL_PTR` | ✅ `&OsCfg_XSig_OsCore0/1` |
| FunctionTable 含 SetRelAlarm | 两核 ISR 均有 | ✅ `Os_XSigRecv_SetRelAlarm` |
| `OsCfg_XSig_ServiceMap` | SetRelAlarm 在 USED 区 | ✅ 已列出 |
| `Os_Isr_Lcfg.c` | XSignalIsr 完整 HW/Context 配置 | ✅ 已生成 |
| `Os_Hal_Interrupt_Lcfg.c` XSignal `Source` | `0x9B0` / `0x990`（GPSR） | ❌ 当前均为 **`0x1`**，见第 12 节 |

关键生成片段：

```c
// Os_XSignal_Cfg.h
#define OS_CFG_XSIGNAL       (STD_ON)
#define OS_CFG_XSIG_USEASYNC   (STD_OFF)

// Os_Core_Lcfg.c
.XSignal = &OsCfg_XSig_OsCore0,   // Core0
.XSignal = &OsCfg_XSig_OsCore1,   // Core1

// Os_XSignal_Lcfg.c — Core0 发往 Core1
OsCfg_XSig_OsCore0_Send0 → XSignalIsr_OsCore1 → Os_XSigRecv_SetRelAlarm
```

当前 ECUC 参数摘要：

| 参数 | 值 |
|------|-----|
| `XSignalIsr_OsCore0/1` Priority | 70 |
| `XSignalChl_*` Channel Size | 1 |
| Buffer 深度 | 2（生成宏 `OS_CFG_SIZE_*_BUFFER = 2u`） |

### 11.5 上板验证（待确认，须先完成第 12 节 Interrupt Source 修复）

1. `SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, 1, 1)` 返回 **`E_OK`**
2. `MotorTask` 周期性收到 **`Rte_Ev_Cyclic_MotorTask_0_1ms`**
3. `Rte_Stop()` 中跨核 **`CancelAlarm(Rte_Al_TE_MotorTask_0_1ms)`** 同样正常（需反向 Channel）
4. 若仍有问题：须先完成 **§13**（Core1 `Rte_Start` 先于 Core0 `SetRelAlarm`）；另参考 `BrsMain.c` ESCAN00078832

### 11.6 与 SchM 的对比

| 模块 | Core1 Alarm 启动方式 |
|------|---------------------|
| **SchM** | `SchM_StartTimingCore1()` 在 **Core1 本地** 调 `SetRelAlarm`（正确） |
| **RTE App TimingEvent** | `Rte_Start()` 在 **Core0** 跨核调 `SetRelAlarm`（**必须 X-Signal**） |

---

## 12. XSignalIsr Interrupt Source 错误 → Trap Class 3（2026-07-31）

### 12.1 现象

上板调试时，Core0 执行 `Os_Api_Init()`，单步越过 `Os_Hal_CoreInitHardware(systemCfg->HwConfig)` 后，PC 落到 **`0x80022960`**，反汇编为 **`SVLCX`**（Trap 入口）。

| 项目 | 内容 |
|------|------|
| Map 符号 | `0x80022960 = osTrap_3_Core0` |
| Trap 类型 | **Class 3 — Context Management** |
| 调用栈 | `Os_Hal_UnhandledExceptionHandler` → `Os_ErrProtectionException` → `Os_ThreadGetCore()` **反复递归**（double-fault 表现） |

**注意**：`Os_Hal_CoreInitHardware()` 在 TC3xx 上为**空函数**，trap 并非发生在该函数内部，而是紧接其后的 **`Os_SystemInterruptHandlingInit()`** 初始化系统级 ISR 的 SRC 寄存器时触发。

```c
// Os_Core.c — Os_Api_Init() 硬件初始化核路径
Os_Hal_CoreInitHardware(systemCfg->HwConfig);   // 空函数，直接返回
Os_SystemInterruptHandlingInit(systemCfg);      // ← 实际 trap 点
Os_MpSystemInit(systemCfg->MemoryProtection);
```

`Os_SystemInterruptHandlingInit()` 会遍历 `OsCfg_Hal_System_InterruptSourceRefs[]`，对所有 ISR（含两个 XSignalIsr）调用 `Os_IsrInterruptSourceInit()` 写 SRC。

### 12.2 根因

X-Signal 通道结构（第 11 节）配置正确，但 **`XSignalIsr_OsCore0` / `XSignalIsr_OsCore1` 的 `OsIsrInterruptSource` 均为 `1`**，Generate 后：

```c
// Appl/GenData/Os_Hal_Interrupt_Lcfg.c（错误配置）
OsCfg_Hal_IntIsr_XSignalIsr_OsCore0 = { .Level = 70, .Source = 0x1uL, .CoreAssignment = 0 };
OsCfg_Hal_IntIsr_XSignalIsr_OsCore1 = { .Level = 70, .Source = 0x1uL, .CoreAssignment = 2 };
```

ECUC（`last364_Os_Os_ecuc.arxml`）：

```
ActiveEcuC/Os/XSignalIsr_OsCore0/OsIsrInterruptSource = 1
ActiveEcuC/Os/XSignalIsr_OsCore1/OsIsrInterruptSource = 1
```

**为何致命：**

1. **`OsIsrInterruptSource` 即 SRC 字节偏移**（相对 `0xF0038000`）。`1` → 访问 **`0xF0038001`**，为 **未 4 字节对齐** 的 SRC 写操作（正常 ISR 如 STM 为 `768` → `0x300` → `SRC_STM0_SR0`）。
2. **两个 XSignalIsr 共用同一 Source**，Core0/Core1 跨核中断源冲突。
3. `0x1` 落在 `SRC_CPU0_SB`（`0xF0038000`）区域内，写坏 CPU0 关键中断/调试相关 SRC，引发硬件异常；异常处理再失败 → Trap 3 递归。

对比正常 ISR 偏移规律（TC36x，`IfxSrc_reg.h`）：

| ISR | `OsIsrInterruptSource` | 生成 `Source` | 硬件寄存器 |
|-----|------------------------|---------------|------------|
| `CounterIsr_SystemTimer` | 768 | `0x300` | `SRC_STM0_SR0` @ `0xF0038300` |
| `CounterIsr_SystemTimer1` | 776 | `0x308` | `SRC_STM1_SR0` @ `0xF0038308` |
| **XSignalIsr（错误）** | **1** | **`0x1`** | **`0xF0038001`（非法）** |
| **XSignalIsr（正确）** | **2448 / 2480** | **`0x990` / `0x9B0`** | **`SRC_GPSR00` / `SRC_GPSR10`** |

### 12.3 解决方法

X-Signal 跨核中断须使用 **GPSR（Generic Parallel Service Request）**，不能用手填的 `1`。

#### 推荐配置（TC364/TC36x 双核）

| ISR | 跨核方向 | `OsIsrInterruptSource` | 生成 `Source` | 硬件 | TOS |
|-----|----------|------------------------|---------------|------|-----|
| `XSignalIsr_OsCore1` | Core0 → Core1 调用入口 | **2448** | `0x990` | `SRC_GPSR00` | CPU1 |
| `XSignalIsr_OsCore0` | Core1 → Core0 调用入口 | **2480** | `0x9B0` | `SRC_GPSR10` | CPU0 |

逻辑：`OsCfg_XSig_OsCore0_Send0` 触发 **`XSignalIsr_OsCore1`** 的 SRC；`OsCfg_XSig_OsCore1_Send0` 触发 **`XSignalIsr_OsCore0`** 的 SRC（见 `Os_XSignal_Lcfg.c`）。

#### DaVinci 操作步骤

| 步骤 | 位置 | 内容 |
|------|------|------|
| 1 | **Os → ISRs → XSignalIsr_OsCore0** | 删除 `OsIsrInterruptSource = 1`；从 Irq 列表选 **GPSR1 SR0**（或填 **2480**） |
| 2 | **Os → ISRs → XSignalIsr_OsCore1** | 删除 `OsIsrInterruptSource = 1`；选 **GPSR0 SR0**（或填 **2448**） |
| 3 | **Irq → GPSR**（可选） | 对应 SR0 设为 Cat2，TOS 分别指向 CPU0 / CPU1，与 Os 一致 |
| 4 | Generate | **Validate → Generate Os** |
| 5 | 验证 | 检查 `Os_Hal_Interrupt_Lcfg.c` 中 `Source` 已为 `0x9B0` / `0x990` |

**不要**手动填 `1`；应使用 DaVinci **Suggest** 或从 Irq 模块关联 GPSR。

#### Generate 后期望代码

```c
// Appl/GenData/Os_Hal_Interrupt_Lcfg.c（修复后）
OsCfg_Hal_IntIsr_XSignalIsr_OsCore0 = { .Level = 70, .Source = 0x9B0uL, .CoreAssignment = 0 };
OsCfg_Hal_IntIsr_XSignalIsr_OsCore1 = { .Level = 70, .Source = 0x990uL, .CoreAssignment = 2 };
```

### 12.4 TRACE32 快速确认

1. 在 `Os_Hal_CoreInitHardware` 处 **Step Over**，再 **Step Into** `Os_SystemInterruptHandlingInit`
2. 观察 trap 是否在第 6/7 个 ISR（`XSignalIsr_OsCore0/1`）初始化时出现
3. 读 **DSTR** 得 Trap Class / TIN（Class 3 可区分 FCD / FCU / CSU 等）
4. 查看 `Os_Callout_UnhandledExc` / `OsCfg_Core_OsCore0_Dyn.LastUnhandledExc`

### 12.5 与第 11 节的关系

| 项 | 第 11 节（X-Signal 通道） | 第 12 节（Interrupt Source） |
|----|---------------------------|------------------------------|
| Channel / SendPort / RecvIsr | ✅ 已正确 | — |
| `OS_CFG_XSIGNAL = STD_ON` | ✅ 已启用 | — |
| `OsIsrInterruptSource` | — | ❌ 均为 `1`，须改为 GPSR |
| 上板 `SetRelAlarm` 验证 | 被 §12 trap 阻塞；通过后还可能遇 **§13 竞态** | 两节均修复后继续 §11.5 验证 |

---

## 13. MotorTask 未激活时 Alarm SetEvent → ErrorHook（2026-07-31）

### 13.1 现象

上板进入 `ErrorHook`，`Os_Callout_Stubs.c` 中捕获：

| 字段 | 值 | 含义 |
|------|-----|------|
| `Service` | `OsServiceId_AlarmActionSetEvent` | Alarm 到期执行 **SetEvent** |
| `Error` | `7` | `E_OS_STATE` |
| `DetailedError` | `OS_STATUS_STATE_1` | 目标 Task 处于 **SUSPENDED**，不能接受 Event |

调用栈：`Os_CounterWorkJobs(SystemTimer1)` → `Os_AlarmActionSetEvent` → `ErrorHook`；Core1 仍在 `Default_Init_Task_Core1` / `EcuM_StartupTwo()` 路径上。

### 13.2 根因：Core0 / Core1 `Rte_Start()` 职责拆分 + 启动竞态

Vector 多核 RTE 生成的 `Rte_Start()`（`Appl/GenData/Rte.c`）把 **MotorTask** 的启动拆在两核：

```c
// Core0（Master）— EcuM_StartupTwo → Rte_Start
SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, 1ms, 1ms);   // Alarm → SetEvent → MotorTask

// Core1 — Default_Init_Task_Core1 → EcuM_StartupTwo → Rte_Start
ActivateTask(MotorTask);
ActivateTask(Default_MotorInitTask);
```

两核 **并行** 跑各自的 Init Task。若 Core0 先完成 `SetRelAlarm`，`SystemTimer1` 在 **1 tick** 后触发 Alarm，此时 Core1 尚未 `ActivateTask(MotorTask)`，Task 仍为 **SUSPENDED** → `SetEvent` 返回 `E_OS_STATE` → `ErrorHook`。

这与 X-Signal / GPSR 无关，是 **RTE 多核启动顺序** 问题（Vector **ESCAN00078832**）。

### 13.3 解决方法（已实施）

#### ① Core0 等待 Core1 完成 `Rte_Start()`（`BrsMain.c`）

在 `Default_Init_Task` 里、调用 `EcuM_StartupTwo()` **之前** 等待 `Rte_InitState_1 == RTE_STATE_INIT`（Core1 已 `ActivateTask(MotorTask)` 并置位）：

```c
#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  #include "Rte_Type.h"
#endif

TASK(Default_Init_Task)
{
  ...
#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  while(Rte_InitState_1 != RTE_STATE_INIT)
  {
    (void)Schedule();
  }
#endif
  EcuM_StartupTwo();   // 内部 Rte_Start → SetRelAlarm(MotorTask)
  (void)TerminateTask();
}
```

#### ② `Default_Init_Task` 必须为 **FULL 抢占**（DaVinci Os）

等待循环里调用 `Schedule()`，要求 Core0 Init Task **可被抢占**，否则 Core1 Init Task 跑不起来，形成死锁。

| Task | 修改前 | 修改后 |
|------|--------|--------|
| `Default_Init_Task`（Core0） | `OsTaskSchedule = NON` | **`FULL`** |
| `Default_Init_Task_Core1` | `FULL` | 保持不变 |

ECUC：`last364_Os_Os_ecuc.arxml` → `Default_Init_Task/OsTaskSchedule = FULL` → **Generate Os**。

#### ③ 启动顺序（修复后）

```
Core1: Default_Init_Task_Core1 → EcuM_StartupTwo → Rte_Start → ActivateTask(MotorTask) → Rte_InitState_1=INIT
Core0: Default_Init_Task → wait(Rte_InitState_1) → EcuM_StartupTwo → Rte_Start → SetRelAlarm(MotorTask)
SystemTimer1: Alarm 到期 → SetEvent(MotorTask)  ✓ Task 已在 WAITING/RUNNING
```

### 13.4 其他可选方案（一般不推荐）

| 方案 | 说明 |
|------|------|
| 加大 `SetRelAlarm` 首周期 offset | 仅缓解竞态，不能保证 |
| 在 Core1 本地 `SetRelAlarm` | 需改 RTE 生成策略或手写，Generate 会覆盖 |
| Core0 跨核 `ActivateTask(MotorTask)` 再 SetRelAlarm | 可行但违背 RTE 生成模型 |

### 13.5 验证

1. 不再进入 `ErrorHook`（`AlarmActionSetEvent` / `E_OS_STATE`）
2. `MotorTask` 周期运行，1 ms TimingEvent 正常
3. Core0 `Default_Init_Task` 在 `wait` 期间会短暂 `Schedule()`，属正常现象

---

## 15. SystemTimer1 TicksPerBase 与 Core1 启动链（2026-08-01）

### 15.1 现象汇总

| 现象 | 典型观测 | 说明 |
|------|----------|------|
| `Rte_InitState_1` 约 20s 才变为 **3** | 与 `StartApp_Cyclic1msCounter` 开始递增几乎同时 | Core0 在等 Core1，不是 RTE 本身需要 20s |
| `StartApp_Cyclic1msCounter` 长期为 0 | Core0 `Rte_Start` 未执行（被 `wait` 阻塞） | 墙钟时间含调试暂停，不等于 CPU 执行时间 |
| `MotorCdd_Os1msCounter` 为 0 或异常 | MotorTask 未跑或 1ms 事件未到 | 需区分 Alarm、ActivateTask、中断是否已开 |
| Counter 百万级、`EntryCounter=1` | `WaitEvent` 几乎不阻塞 | **`TicksPerBase=1` 时 Timer 行为异常** |
| Trusted 加 SetRelAlarm/ActivateTask 后进 ErrorHook | `Os_TrapTaskMissingTerminateTask` | 重复激活 + 错误 tick 值 + 栈/ISR 嵌套 |

### 15.2 SystemTimer1 正确配置（TC36x）

Core0 **SystemTimer** 与 Core1 **SystemTimer1** 必须一致：

| 参数 | Core0 `SystemTimer` | Core1 `SystemTimer1` | 说明 |
|------|---------------------|----------------------|------|
| `OsCounterTicksPerBase` | **100000** | **100000** | 100MHz STM → 1ms 中断周期 |
| `OsSecondsPerTick` | **0.001** | **0.001** | 1 OS tick = 1ms |
| 硬件通道 | `STM0_Ch0` | `STM1_Ch0` | Core1 专用 STM1 |
| `OsCounterType` | HARDWARE | HARDWARE | — |

ECUC 路径：

```
ActiveEcuC/Os/SystemTimer/OsCounterTicksPerBase   = 100000
ActiveEcuC/Os/SystemTimer1/OsCounterTicksPerBase  = 100000
```

Generate Os 后验证：

```c
// Appl/GenData/Os_Hal_Cfg.h
#define OSTICKSPERBASE_SystemTimer    (100000u)
#define OSTICKSPERBASE_SystemTimer1   (100000u)
```

**错误配置 `TicksPerBase = 1` 的影响：**

- OS 宏仍按 1ms/tick 理解 Alarm（`RTE_MSEC_SystemTimer1(1)`）
- 但 STM 比较/Reload 按 `TicksPerBase` 编程，硬件 ISR 周期与 OS 期望脱节
- 表现为 Counter 疯涨、Alarm/SetEvent 时序混乱、后续 ErrorHook / 栈损坏

**不要**把 `TicksPerBase` 改成 100000 当作“启动慢”的唯一修复手段而不排查其它项；但若 Core1 曾为 1，**必须改回 100000**。

### 15.3 `Rte_InitState_1` 延迟的根因链

```
Core1 Default_Init_Task_Core1
  → EcuM_StartupTwo → Rte_Start
  → Rte_InitState_1 = 3                    ← 正常应很快完成

Core0 Default_Init_Task
  → while (Rte_InitState_1 != 3) Schedule() ← 若 Core1 卡住则一直等
  → EcuM_StartupTwo → Rte_Start
  → SetRelAlarm(StartApp 1ms…)              ← StartApp_Cyclic1msCounter 从这里才开始
```

Core1 卡在 ErrorHook 的常见原因（与 20s 现象相关）：

| 原因 | 机制 | 修复 |
|------|------|------|
| `TicksPerBase=1` | Timer/Alarm 异常 | 改为 100000，Generate Os |
| `WaitEvent` + 中断未开 | `OS_STATUS_DISABLEDINT` | 遵循 Init → Trusted 开中断 → 应用 Task |
| Core0 先于 Core1 `SetRelAlarm` | `E_OS_STATE` on SUSPENDED task | §13 ESCAN00078832 wait |
| Trusted 重复 ActivateTask | 重复调度 / 错误 Alarm | §15.4 删除 Trusted 中 workaround |
| `Default_MotorInitTask` SPI trap | Core1 冻结在 init | 查 TLE9180/QSPI，与 Rte_InitState 无关（ActivateTask 异步） |

### 15.4 BrsMain Trusted 中错误 workaround（已撤销）

调试期间曾在 `Default_Init_Task_Core1_Trusted` 中加入：

```c
/* ❌ 错误：不要保留 */
(void)SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, (TickType)1U, (TickType)1U);
(void)ActivateTask(MotorTask);
```

**问题：**

1. **`Rte_Start()` 已在 Core1 完成** `ActivateTask(MotorTask)` / `ActivateTask(Default_MotorInitTask)`，Trusted 中再次激活是重复的
2. **裸 `(TickType)1U`** 在 `TicksPerBase=100000` 下不等于 1ms，应使用 `RTE_MSEC_SystemTimer1(1U)`
3. **SetRelAlarm 已在 Core0 `Rte_Start`** 跨核设置（需 X-Signal，§11）
4. **Trusted 职责**仅为 `Os_InitialEnableInterruptSources()`，与 Core0 Trusted 一致

**正确写法（当前工程）：**

```c
TASK(Default_Init_Task_Core1_Trusted)
{
  Os_InitialEnableInterruptSources(FALSE);
  (void)TerminateTask();
}
```

注释掉或删除 Trusted 中 MotorTask 代码后，在 **TicksPerBase=100000** 下 `Rte_InitState_1` 应快速变为 3，与实测一致。

### 15.5 标准 Core1 启动顺序（修复后）

```
两核: EcuM_Init → DriverInitOne → StartOS

Core1:
  Default_Init_Task_Core1
    → EcuM_StartupTwo → Rte_Start
    → ActivateTask(Default_MotorInitTask)
    → ActivateTask(MotorTask)
    → Rte_InitState_1 = RTE_STATE_INIT (3)
    → TerminateTask

  Default_Init_Task_Core1_Trusted
    → Os_InitialEnableInterruptSources(FALSE)
    → TerminateTask

  MotorTask / Default_MotorInitTask 开始调度

Core0:
  Default_Init_Task
    → wait(Rte_InitState_1 == RTE_STATE_INIT)   // ESCAN00078832
    → EcuM_StartupTwo → Rte_Start
    → SetRelAlarm(MotorTask, SystemTimer1)      // 跨核 X-Signal
    → SetRelAlarm(StartApp 1ms/10ms/…)
    → TerminateTask

  Default_Init_Task_Trusted
    → Os_InitialEnableInterruptSources(FALSE)
```

Init Task 按 OS 配置顺序执行完毕前，**MotorTask 不会抢占 Init 链**；Trusted 开中断后 `WaitEvent` 才合法。

### 15.6 应用层保留项（非调试变量）

| 项 | 文件 | 说明 |
|----|------|------|
| `MotorCdd_InitComplete`（`static`） | `MotorCdd.c` | Init 完成前 MainFunction 仅 return，避免未 init 调 TLE9180 |
| Core0 wait `Rte_InitState_1` | `BrsMain.c` | ESCAN00078832，须保留 |
| `Default_Init_Task` Schedule=**FULL** | Os ECUC | wait 循环中须可 Schedule |

### 15.7 调试变量说明（2026-08-01 清理）

**保留（工程原有）：**

| 变量 | 位置 |
|------|------|
| `MotorCdd_Os1msCounter` | `MotorCdd.c` / `MotorCdd.h` |
| `MotorCdd_PwmComplementaryInitDone` | `MotorCdd.c` |
| `StartApp_Cyclic1msCounter` / `StartApp_Cyclic250msCounter` | `StartApp.c` |
| `Os_Callout_LastError*` / `Os_Callout_UnhandledIrq/Exc*` | `Os_Callout_Stubs.c` |

**已删除（双核调试临时添加）：**

| 变量 | 说明 |
|------|------|
| `MotorCdd_MotorTaskEntryCounter` | MotorTask 入口计数 |
| `MotorCdd_MotorTaskWakeCounter` | WaitEvent 返回计数 |
| `MotorCdd_SetRelAlarmStatus` | SetRelAlarm 返回值 |
| `Os_ErrorHookCounter` / `_Core1` | ErrorHook 次数 |

### 15.8 验证清单

1. DaVinci：`SystemTimer` / `SystemTimer1` 的 `OsCounterTicksPerBase = 100000`，`OsSecondsPerTick = 0.001`
2. Generate Os + RTE，Full Rebuild
3. `BrsMain.c`：Trusted **无** MotorTask SetRelAlarm/ActivateTask；Core0 **有** `wait(Rte_InitState_1)`
4. 上板（少打断或记清墙钟 vs 计数器）：
   - `Rte_InitState_1` 快速 → **3**
   - `StartApp_Cyclic1msCounter`、`MotorCdd_Os1msCounter` 约 **1:1** 增长（均 ~1/ms）
   - `Os_Callout_LastError` 保持 **E_OK**（未进 ErrorHook）
5. 若 MotorTask 仍 0：查 X-Signal（§11）、GPSR Source（§12）、Alarm 返回值
6. 若 init 后 trap：查 `Default_MotorInitTask` / TLE9180 SPI（`Os_Callout_LastErrorService`）

---

## 16. 参考

- Vector StartApplication：`Appl/Makefile` 中 `-Wl--user-provided-initialization-code`
- Tasking 链接选项 ID：`com.tasking.ctc.lk.userProvidedInitCode` → `--user-provided-initialization-code`
- vLinkGen / vBRS：DaVinci Configurator 生成 `vLinkGen_Lcfg.c`、`vBrs_Lcfg.c` 与 `vLinkGen_Template.lsl`
- Os X-Signal 参考：SIP `StartApplication/Config/ECUC/CBD2200508_Os_Os_ecuc.arxml`（4 核完整版；last364 为 2 核简化）
- Vector OS 跨核错误码：`E_OS_SYS_FUNCTION_UNAVAILABLE (0xF9)` = 目标核未配置跨核 API / X-Signal 未启用
- X-Signal ISR 硬件源：AURIX GPSR，`MCAL364/TC36xA/_Reg/IfxSrc_reg.h`（`SRC_GPSR00` @ `0xF0038990`，`SRC_GPSR10` @ `0xF00389B0`）
- Os HAL SRC 基址：`OS_HAL_INT_SRC_BASE = 0xF0038000`（`Os_Hal_Derivative_TC36xInt.h` + `Os_Hal_InterruptController_AurixTC3xx_IRInt.h`）
- RTE 多核启动顺序：**ESCAN00078832**（`BrsMain.c` `Default_Init_Task` 等待 `Rte_InitState_1`；`Default_Init_Task` 须 **FULL** 抢占）
- SystemTimer1 / TicksPerBase：TC36x STM @ 100MHz，`TicksPerBase=100000` + `SecondsPerTick=0.001` → 1ms OS tick（§15）
- `Default_Init_Task_Core1_Trusted`：仅 `Os_InitialEnableInterruptSources`，**勿**在此 ActivateTask/SetRelAlarm MotorTask（§15.4）
