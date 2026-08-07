# Dem / MemMap 编译与集成问题修复记录

> 本文档记录 Dem 模块集成过程中遇到的 MemMap 编译错误、DaVinci 配置、TASKING 编译及上电运行问题。

日期：2026-08-06
影响范围：`last364` 工程（TC367 / AUTOSAR MICROSAR / TASKING TriCore v6.2r2）

## 1. 问题现象

编译 `Appl\GenData` 下的生成配置时批量报错，`make` 停止：

```text
ctc E201: ["...\Appl\GenData\MemMap_Common.h" 4602/1] #error No MemMap section found in MemMap_Common.h. Check your section define for validity.
ctc E201: ["...\BSW364\_Common\Implementation\MemMap.h" 15/1] #error "No MemMap section found. Check your section define for validity."
amk E452: target 'Appl\GenData\Dem_PBcfg.o' returned exit code 1
amk E452: target 'Appl\GenData\Dcm_PBcfg.o' returned exit code 1
amk E452: target 'Appl\GenData\Dcm_Lcfg.o' returned exit code 1
amk E452: target 'Appl\GenData\Dem_Lcfg.o' returned exit code 1
amk E452: target 'Appl\GenData\BswM_Lcfg.o' returned exit code 1
amk E451: make stopped
```

## 2. 根因分析

1. 2026-08-05 使用 DaVinci Configurator 重新生成配置后，Dem 生成代码中为 OsApplication “0” 的卫星数据缓冲引入了新的 section：

   ```c
   /* Dem_Lcfg.h / Dem_Lcfg.c */
   #define DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
   #include "MemMap.h"
   extern VAR(Dem_Cfg_SatelliteInfoType0, DEM_VAR_ZERO_INIT) Dem_Cfg_SatelliteInfo0;
   #define DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
   #include "MemMap.h"
   ```

2. 新生成的代码走的是中心 MemMap 链：`MemMap.h` → `_MemMap.h` → `MemMap_Compatibility.h` → `MemMap_Common.h`。该链中没有任何一处处理 `DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED` / `DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED`，于是 `MEMMAP_ERROR` 未被清除，触发 `MemMap_Common.h` 4602 行和 `MemMap.h` 15 行的 `#error`。

3. 这个映射其实只存在于旧的模块化模板 `Appl\Include\Dem_MemMap.h` 中，而新生成代码不再包含它。

4. 其余报错文件（Dcm_PBcfg / Dcm_Lcfg / Dem_PBcfg / BswM_Lcfg）并非自身 section 有缺失，而是它们的头文件包含链都会经过 `Dem.h` → `Dem_Lcfg.h`，连带触发了同一个未匹配 section。

## 3. 修复内容

文件：`last364\BSW364\_Common\Implementation\_MemMap.h`

在 DEM 段的 START/STOP 映射区各新增一组映射，与现有 DEM 条目及 `Dem_MemMap.h` 模板写法保持一致：

```c
#if defined (DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED)
# undef DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED)
# undef DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
```

说明：

- `START_SEC_VAR_ZERO_INIT_UNSPECIFIED` 与 `STOP_SEC_VAR` 在 `MemMap_Common.h` 中均已实现，配对关系与 `Dem_MemMap.h` 模板一致。
- `_MemMap.h` 是手工维护的公共映射模板，不是 DaVinci 生成文件，重新生成工程不会被覆盖。

## 4. 验证结果

使用 TASKING `cctc`（`D:\Program Files (x86)\TASKING\TriCore v6.2r2\ctc`）按各目标的 `.opt` 参数逐个复现并复测：

| 目标文件 | 修复前 | 修复后 |
| --- | --- | --- |
| `Os_Barrier_Lcfg.o` | 实际可编译通过 | 0 errors |
| `Dem_PBcfg.o` | 4 errors | 0 errors |
| `Dcm_PBcfg.o` | 4 errors | 0 errors |
| `Dcm_Lcfg.o` | 4 errors | 0 errors |
| `Dem_Lcfg.o` | 8 errors | 0 errors（1 个既有 W542 警告，与 MemMap 无关） |
| `BswM_Lcfg.o` | 4 errors | 0 errors |

## 5. 后续注意事项

- 若以后配置中新增其它 OsApplication（例如 “1”），需要按同样模式补充对应的 `DEM_START_SEC_<应用名>_VAR_ZERO_INIT_UNSPECIFIED` 映射。
- 长期建议：确认 DaVinci 的 MemMap 模块配置/生成器是否应自动输出该映射，避免每次重新生成后都要手工补丁。

## 6. 附：修复后出现的编译警告说明

修复后 Dem 相关代码继续编译，输出一批警告（非错误，不影响构建），全部来自 Vector 生成的 Dem BSW 代码：

| 警告 | 含义 | 影响 |
| --- | --- | --- |
| W542 missing braces around initializer | 结构体/联合用 `{ 0 }` 初始化，TASKING 要求按嵌套层次加花括号 | 无，仍全部清零 |
| W515 side effects of 'sizeof' operand are ignored | `sizeof(函数调用式表达式)`，sizeof 不求值操作数 | 无 |
| W536 / W537 unused static function / variable | 配置中未启用的功能对应的生成代码未被引用 | 无 |
| W588 dead assignment eliminated | 优化器删除从未被读取的赋值 | 无 |
| W549 condition is always true/false | 条件在给定配置下为编译期常量 | 无 |

如需抑制噪音，可在 TASKING 编译器选项中加 `-w`（全部关闭）或按编号关闭，例如：`-w542,515,536,537,588,549`。

---

## 7. Dem 启用后的配置与编译/运行问题总结

> 日期：2026-08-06  
> 背景：在 MemMap 修复后继续集成 Dem / Dcm / CanTp 诊断栈，记录 DaVinci 配置、编译与上电运行中的典型问题。

### 7.1 Dem NvRam 块与 NvM 块对应关系（不是 UDS 服务 1:1）

`DemNvRamBlockIds` 与 DCM 服务表 **不是一一对应**。Dem NvRam 块负责 **DTC 持久化存储**；DCM 服务是诊断仪可调用的 UDS 命令。

本工程 `DemMaxNumberEventEntryPrimary = 8`，共需 **10 个专用 NvM 块**：

| Dem 条目 | Type | Index | 应对应 NvM 块 | 用途 |
| --- | --- | --- | --- | --- |
| `DemNvRamBlockId` | `ADMIN` | 0 | `NvMBlock_DemAdmin` | Dem 管理数据 |
| `DemNvRamBlockId_001` | `PRIMARY` | 1 | `NvMBlock_DemPrimary1` | DTC 事件槽 1 |
| `_002` ~ `_007` | `PRIMARY` | 2~7 | `NvMBlock_DemPrimary2` ~ `7` | DTC 事件槽 2~7 |
| `_008` | `PRIMARY` | 0 | `NvMBlock_DemPrimary0` | DTC 事件槽 0（第 8 槽） |
| `_009` | `STATUS` | 0 | `NvMBlock_DemStatus` | Event 状态位 |

注意：

- **不要**选 `NvMBlock_MotorZeroCal` / `NvMConfigBlock`，Dem 必须用专用块。
- `_009` 的 Index 必须是 **0**（不是 1）。
- 每个 Type 内 Index 独立编号；`ADMIN` / `STATUS` 各只有 1 个，Index 均为 0。

与 Dem/NvM 直接相关的 UDS 服务只有 3 个（共用上述 10 块，非每服务一块）：

| 服务 | SID | 说明 |
| --- | --- | --- |
| ClearDiagInfo | 0x14 | 清 DTC，Dem 写 NvM |
| ReadDtcInfo | 0x19 | 读 DTC |
| ControlDtcSetting | 0x85 | DTC 设置控制 |

### 7.2 新建 Dem 专用 NvM（DaVinci 操作顺序）

**顺序：Fee → NvM → 挂回 Dem Ref**

#### Fee（DFlash 底层）

`Fee` → `FeeBlockConfiguration` → Add，例如 `FeeBlock_DemAdmin`：

| 参数 | 建议值 |
| --- | --- |
| FeeBlockNumber | 33 起（未占用即可，依次 34、35…） |
| FeeBlockSize | ≥ NvM 长度 + CRC（先填 64，Validate 后再调） |
| FeeDeviceIndex | 指向 `FlsGeneral` |

10 个 Dem 块 → 10 个 Fee 块（块号 33~42）。

#### NvM

`NvM` → Add `NvMBlockDescriptor`，参数参考 `NvMBlock_MotorZeroCal`，关键差异：

| 参数 | Dem 专用块建议 |
| --- | --- |
| NvMBlockManagementType | `NVM_BLOCK_NATIVE` |
| NvMBlockUseCrc | true，`NVM_CRC16` |
| NvMSelectBlockForReadAll | **true** |
| NvMSelectBlockForWriteAll | **true** |
| NvMRamBlockDataAddress | `NULL_PTR` |
| NvMTargetBlockReference → NvMFeeRef | 指向对应 Fee 块 |

#### Dem

`Dem` → `DemGeneral` → `DemNvRamBlockIds` → 每条 `NvRam BlockId Ref` 选对应 NvM 块。

### 7.3 PduR 报错 PDUR07000 / PDUR07010（0x7DF 功能寻址）

**现象：**

```text
PDUR07000: PduRDestPdu direction cannot be determined (msg_diag_RequestGlobal...)
PDUR07010: Routing type cannot be determined, PduRDestPduDirection = UNDEFINED
```

**根因：** 0x7DF 功能寻址 PDU 未挂到 Dcm，PduR 目标方向无法判定。

**已修改文件（arxml）：**

| 文件 | 修改 |
| --- | --- |
| `Config/ECUC/last364_Dcm_Dcm_ecuc.arxml` | 新增功能寻址 `DcmDslProtocolRx`（`DCM_FUNCTIONAL_TYPE`，Ref → `msg_diag_RequestGlobal_oCAN00_25be229e_Rx`，PduId=1） |
| `Config/ECUC/last364_PduR_PduR_ecuc.arxml` | DestPdu 补 `PduRDestPduPduRBswModulesRef` → `Dcm` |
| `Config/ECUC/last364_CanTp_CanTp_ecuc.arxml` | 0x7DF 通道 `CanTpRxTaType` → `CANTP_FUNCTIONAL`（0x74C 物理通道保持 `CANTP_PHYSICAL`） |

**DaVinci 手工改法：**

1. **Dcm**：`DcmDslMainConnection` 下 Add `DcmDslProtocolRx`，Type=`DCM_FUNCTIONAL_TYPE`，PduRef=`msg_diag_RequestGlobal`，PduId=1。
2. **PduR**：`msg_diag_RequestGlobal` 路由 DestPdu 的 `PduRDestPduPduRBswModulesRef` → **Dcm**（对照物理 0x74C 那条抄）。
3. **CanTp**：RequestGlobal 的 RxNSdu → `CANTP_FUNCTIONAL`。

修好后链路：

```text
CanIf (0x7DF Rx) → CanTp (FUNCTIONAL) → PduR (CanTp→Dcm) → Dcm (DCM_FUNCTIONAL_TYPE)
```

### 7.4 Dem.c 编译：大量 W549 与 S900（不是“几百个错误”）

**现象：** 编译 `Dem.c` 时刷屏 `W536/W537/W549/W588`，最后：

```text
ctc S900: internal consistency check failed - please report
amk E452: Dem.o returned exit code 1
```

**说明：**

- 前面全是 **Warning**，来自 Vector Dem 生成代码在 `-O2` 下对未启用功能的死代码分析，**不是配置错误**。
- 真正导致失败的是 **`ctc S900`**（TASKING 编译器内部错误），常见于 **Dem.c 超大翻译单元 + O2 优化**。

**处理建议（按优先级）：**

1. 仅对 `BSW364/Dem/Implementation/Dem.c` 降优化：Properties → Optimization → **`-O1`** 或 **`-O0`**。
2. **Project → Clean** 后重编；必要时关并行编译再试。
3. 警告可忽略，或用 `-w542,515,536,537,588,549` 抑制（不能解决 S900）。

当前 `Dem.c` 编译参数（`Debug/BSW364/Dem/Implementation/subdir.mk`）：`-O2 --tradeoff=4`。

### 7.5 上电 DET 报错：DCM_E_UNINIT（ModuleId=53）

**现象（调试器）：**

| 字段 | 值 | 含义 |
| --- | --- | --- |
| ModuleId | 53 (0x35) | **Dcm**（不是 Dem） |
| ApiId | 0x25 | `Dcm_MainFunction()` |
| ErrorId | 0x05 | `DCM_E_UNINIT`（未 Init 就调 API） |

**栈：** `Default_BSW_ASync_Task_10ms` → `Dcm_MainFunction()` → `Det_ReportError`。

**根因：**

- RTE 10 ms 任务已调用 `Dcm_MainFunction()`（`Rte_SystemApplication_OsCore0.c`）。
- BswM `INIT_AL_Initialize` 只有 Det/Can/CanIf/Com/PduR/CanSM/NvM/ComM，**缺少 `CanTp_Init` 和 `Dcm_Init`**。
- 全工程无 `Dcm_Init()` 调用；`Dem_Init()` 由 EcuM 单独调用，故 Dem 不一定报 UNINIT。

**DaVinci 修复：**

| Init 函数 | InitPhase | 添加位置 |
| --- | --- | --- |
| `CanTp_Init(CanTp_Config_Ptr)` | `INIT_TWO_TP` | BswM Action List，**PduR_Init 之后** |
| `Dcm_Init(NULL_PTR)` | `INIT_TWO_POST_NVMREADALL` | BswM Action List，**NvM ReadAll 完成之后** |

Generate 后在 `Appl/GenData/BswM_Lcfg.c` 中应能看到上述 Init 调用。

**关于 `Os_TrapTaskMissingTerminateTask`：** `Default_BSW_ASync_Task_10ms` 为 Extended Task（`IsExtended=TRUE`），正常 `for(;;)+WaitEvent`，无需 `TerminateTask()`。该 Trap 多为 DET 报错连带或调试停住时的栈干扰，**先修 Dcm_Init 缺失**后再观察。

### 7.6 DCM 服务 0x2A 校验错误 DCM03996（可选）

若服务表含 `ReadDataByPeriodicId`（SID 0x2A）且报：

```text
DCM03996: missing DcmDslPeriodicTransmission
```

本工程电机诊断一般 **不需要周期读 DID**，推荐直接删除 `DcmDsdServiceTable` 中的 `ReadDataByPeriodicId`。若必须保留，需在 `DcmDslProtocolRow` 下新建 `DcmDslPeriodicTransmission` 并配 UUDT Tx PDU。

---

## 8. 问题排查速查表

| 现象 | 层级 | 首要检查 |
| --- | --- | --- |
| MemMap `#error No MemMap section found` | 编译 | `_MemMap.h` 是否补 `DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED` |
| PDUR07000/07010 | DaVinci Validate | Dcm 功能 Rx + PduR Dest→Dcm + CanTp FUNCTIONAL |
| Dem.c 大量 W549 + S900 | 编译 | Dem.c 降优化 O1/O0，Clean 重编 |
| DET 53/0x25/0x05 | 运行 | BswM 是否调用 `Dcm_Init` / `CanTp_Init` |
| Dem NvRam 红叉 | DaVinci Validate | 10 个 NvM Ref 是否补全，Index/Type 是否正确 |
