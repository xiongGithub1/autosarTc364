# DaVinci RTE 配置与生成教程（怎么配出对应的 `Rte_*`）

> 工程：`last364.dpa`（TC364 + Vector MICROSAR 4.2.2 + Infineon MCAL 20.10.0）
> 目的：教你怎么在 DaVinci 里配置 SW-C 的接口/端口/运行实体/事件，并生成 `Rte_Read_*`、`Rte_Write_*`、`Rte_Call_*`、`Rte_Ev_*` 这些 RTE API。
> 适用：把 MotorControll / MotorCdd / StartApp 之间现在的“直调函数”改成走 RTE 的标准调用。

---

## 1. 你要的 `Rte_*` 是从哪来的

RTE 不是手写的，是 **DaVinci Configurator 根据三部分输入“生成”** 的：

```text
① 组件/接口设计（DaVinci Developer）
   Config/Developer/
   ├── ComponentTypes/  MotorControll.arxml、MotorCdd.arxml、StartApp.arxml …
   ├── PortInterfaces.arxml     # 接口：S/R、C/S、Trigger
   ├── DataTypes.arxml          # 数据类型：MotorMode、MotorSwitch …
   └── ECUProjects/last364.arxml # SW-C 实例 + 端口连接（assembly/delegation）
                │
                ▼
② ECU 配置（DaVinci Configurator）
   Config/System/FlatMap.arxml、FlatExtract.arxml   # 扁平化系统描述
   Config/ECUC/last364_Rte_Rte_ecuc.arxml           # Rte 事件→Os 任务/报警 映射
   Config/ECUC/last364_Os_Os_ecuc.arxml             # Os 报警 Rte_Al_TE_*、任务
                │
                ▼  Build → Generate RTE
③ 生成产物
   Appl/GenData/Components/Rte_MotorControll.h/.c
   Appl/GenData/Components/Rte_MotorCdd.h/.c
   Appl/GenData/Components/Rte_StartApp.h/.c
   Appl/GenData/Rte.c、Rte_Cbk.h …
```

一句话：**接口/端口/事件在 Developer 里画，任务/报警映射在 Configurator 里配，Rte_* 是生成出来的。**

---

## 2. 每种 `Rte_*` 对应哪一步配置（对照表）

| 你要生成的 RTE API | 用途 | 需要配置的内容（Developer） | 需要配置的内容（Configurator） |
| --- | --- | --- | --- |
| `Rte_Write_Pp_<Port>_<Data>(v)` | 写一个 S/R 数据（提供方） | 建 S/R 接口 → 加数据元素 → SW-C 加 **P-PORT** | 生成 RTE |
| `Rte_Read_Pp_<Port>_<Data>(&v)` | 读一个 S/R 数据（使用方） | 同上接口 → SW-C 加 **R-PORT** | 生成 RTE |
| `Rte_Call_Pp_<Port>_<Operation>(args)` | 调用一个 C/S 操作（使用方） | 建 C/S 接口 → 加操作/参数 → SW-C 加 **R-PORT** | 生成 RTE |
| `<Port>_<Operation>(args)` 实现函数 | C/S 操作的服务端实现 | C/S 接口 → SW-C 加 **P-PORT** → 内部行为加 **OperationInvokedEvent** 指向运行实体 | 生成 RTE（函数原型） |
| `Rte_Ev_Run_<Runnable>` | 周期运行实体的 OS 事件 | 内部行为加 **TimingEvent**（周期 0.001 等） | Rte 里映射到 **Os 任务**（`RteActivationOsTaskRef`） |
| `Rte_Al_TE_<Task>_<n>_<周期>` | 周期报警 | TimingEvent（同上） | 自动生成（Os/Rte 联动） |
| `Rte_Ev_Run_<Runnable>_Rp_<Port>_<Trigger>` | 触发类运行实体 | 建 **Trigger 接口** + R-PORT + **ExternalTriggerOccurredEvent** | 映射到 Os 任务/ISR |
| Init 运行实体 | 上电自动调用 | 内部行为加 **InitEvent** | 生成 RTE 启动代码 |
| `Rte_Mode_*` / `Rte_Switch_*` | 模式端口 | 建 Mode 接口（ModeDeclarationGroup） | 生成 RTE |

> 命名规则：`Pp_`=提供端口（Provider）、`Rp_`=要求端口（Requester）、`Ps_/Rs_`=模式端口、`<Operation>`=操作名、`<Data>`=数据元素名。Rte API 名字 = 端口名 + 数据/操作名拼出来的，**改端口名 API 名就变**。

---

## 3. 本工程现在已经有/还没有哪些 `Rte_*`

### 3.1 已经生成的（`Appl/GenData/Components/Rte_MotorControll.h` / `Rte_MotorCdd.h`）

```c
/* MotorControll（使用方） */
Rte_Write_Pp_MotorCtrlCmd_MotorMode(uint8);                 // 写模式 → MotorCdd
Rte_Write_Pp_MotorCurrentRef_Id_Ref(float32);               // 写 Id 参考
Rte_Write_Pp_MotorCurrentRef_Iq_Ref(float32);               // 写 Iq 参考
Rte_Read_Pp_MotorDcBusVoltage_Vbus(&v);                     // 读母线电压（来自 MotorCdd）
Rte_Read_Pp_MotorElectricalAngle_ElectricAngle(&a);         // 读电角度
Rte_Read_Pp_MotorFaultStatus_tle9180_Ov_Fault(&f);          // 读 9180 过压故障

/* MotorCdd（提供方） */
Rte_Write_Pp_MotorDcBusVoltage_Vbus(v);
Rte_Write_Pp_MotorElectricalAngle_ElectricAngle(a);
Rte_Write_Pp_MotorFaultStatus_tle9180_Ov_Fault(f);
Rte_Read_Pp_MotorCtrlCmd_MotorMode(&m);                     // 读模式命令
Rte_Read_Pp_MotorCurrentRef_Id_Ref(&id);                    // 读 Id 参考
Rte_Read_Pp_MotorCurrentRef_Iq_Ref(&iq);

/* MotorCdd 的 C/S 服务端实现（已定义，但还没被 Rte_Call 调用） */
void Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg);
```

### 3.2 端口与连接现状

| 组件 | 端口 | 接口 | 方向 | 已连接 |
| --- | --- | --- | --- | --- |
| MotorControll | `Pp_MotorCtrlCmd` | S/R（MotorMode） | 提供 | ✅ 连 MotorCdd |
| MotorControll | `Pp_MotorCurrentRef` | S/R（Id_Ref/Iq_Ref） | 提供 | ✅ 连 MotorCdd |
| MotorControll | `Pp_MotorElectricalAngle` | S/R（ElectricAngle） | 要求 | ✅ 连 MotorCdd |
| MotorControll | `Pp_MotorDcBusVoltage` | S/R（Vbus） | 要求 | ✅ 连 MotorCdd |
| MotorControll | `Pp_MotorFaultStatus` | S/R（tle9180_Ov_Fault） | 要求 | ✅ 连 MotorCdd |
| MotorControll | `Pp_MotorCdd_EnableInverter` | C/S（EnableInverter） | 要求 | ✅ 连接已存在（FlatExtract 有 assembly），但**应用代码仍直调、生成的 `Rte_Call_*` 未出现**（RTE 未重新生成/头文件过期） |
| MotorCdd | 上述 5 个的提供端 + `Rp_AdcSampleReady`（Trigger） | — | — | ✅/⚠️ 见上 |
| StartApp | 无端口 | — | — | 直接调 Dio/EcuM/ComM（非标准） |

结论：**反馈类数据已经标准化了**，下一步是把“控制/服务类直调”（输出使能、清故障、停 PWM、栅驱状态、零位标定、速度环）也改成 Rte 端口。

---

## 4. 完整配置步骤（把直调函数变成 `Rte_*`）

下面以“把 `MotorControll` 直调的 `Tle9180_Driver_EnableOutput(TRUE)` 改成 RTE 调用”为例子，教完整链路。其他函数照此办理。

### 第 1 步：建接口（DaVinci Developer）

1. 打开 Developer 工程（`Config/Developer/last364.dcf` 或工作区里的 last364 工程）。
2. 左侧树：**Interfaces（端口接口）→ 新建 ClientServerInterface**，命名建议：
   - 接口名：`MotorCdd_OutputControl`（或直接复用现有 `Pp_MotorCdd_EnableInverter`）
   - 操作（Operation）：`EnableOutput`
   - 参数（Argument）：`Enable`，方向 IN，类型 `MotorSwitch`（工程已有，boolean 别名）
3. 若新增 S/R 数据（比如栅驱状态），则建 **SenderReceiverInterface**，加 DataElement：
   - `GateDriverState`（类型 `uint8`）、`AdcOffsetReady`（`boolean`）、`MechanicalRpm`（`float32`）……
4. 保存 → arxml 写回 `Config/Developer/PortInterfaces.arxml`。

### 第 2 步：给 SW-C 加端口

1. 左侧树：**SWC Types → MotorControll** → Ports → 新建 **R-PORT**：
   - 端口名：`Rp_MotorCdd_OutputControl`（Requester）
   - 选择接口：`MotorCdd_OutputControl`
2. **MotorCdd** → Ports → 新建 **P-PORT**：
   - 端口名：`Pp_MotorCdd_OutputControl`（Provider）
   - 选择接口：同上
3. S/R 同理：MotorCdd 加 P-PORT（如 `Pp_MotorGateDriverState`），MotorControll 加 R-PORT。
4. 保存。

### 第 3 步：给服务端加“运行实体 + OperationInvokedEvent”

这是 **Rte_Call 能否生成的关键**：

1. **MotorCdd** → Internal Behavior → **Runnables** → 新建运行实体：
   - 名称（即实现函数名）：`Pp_MotorCdd_OutputControl_EnableOutput`
   - Symbol 设成同名（生成的原型就是它）
2. Internal Behavior → **Events** → 新建 **OperationInvokedEvent**：
   - 名称：`OperationInvokedEvent_Pp_MotorCdd_OutputControl_EnableOutput`
   - `StartOnEvent` 指向运行实体 `Pp_MotorCdd_OutputControl_EnableOutput`
   - `Operation` 指向 `MotorCdd_OutputControl.EnableOutput`
3. 周期函数不用 OperationInvokedEvent：新建 **TimingEvent**（如现有 `TMT_MotorCdd_MainFunction`，周期 0.001 s）→ 它会生成 `Rte_Ev_Run_MotorCdd_MainFunction` 对应事件。
4. 初始化：建 **InitEvent**（如 `MotorCdd_InitEvent`）→ RTE 启动时自动调 `MotorCdd_Init`。

### 第 4 步：ECU 工程里连端口（Assembly/Delegation）

1. 打开 **ECU Projects → last364**（组件实例视图）。
2. 把 MotorControll 的 `Rp_MotorCdd_OutputControl` 拖到 MotorCdd 的 `Pp_MotorCdd_OutputControl`，Developer 自动生成 **AssemblySwConnector**（类似现有：
   `MotorCdd_Pp_MotorDcBusVoltage_MotorControll_Pp_MotorDcBusVoltage`）。
3. 保存，生成/刷新 FlatMap 与 FlatExtract。

> ⚠️ 只建端口不连线，RTE 不会为跨组件通信生成 `Rte_Call`/`Rte_Read`。本工程 `EnableInverter` 端口和连接都已建好，但**生成的 `Rte_MotorControll.h` 里还没有 `Rte_Call_*`**，多半是 RTE 未重新 Generate（生成物过期）。

### 第 5 步：DaVinci Configurator 里映射事件→Os 任务

1. 打开 Configurator 工程 `last364.dpa`，执行 **Build / 导入**（把 Developer 的改动同步进来）。
2. 进入 **Rte 模块**：
   - Rte → RteOsInteraction → 为每个 TimingEvent 确认/新建映射：
     - `TMT_MotorCdd_MainFunction`（1 ms）→ `RteActivationOsTaskRef = MotorTask`、`RteActivationOsAlarmRef = Rte_Al_TE_MotorTask_0_1ms`
     - `TMT_StartApp_Cyclic1ms` → `Default_Appl_Task`（现有配置就是这样的）
   - 操作调用（OperationInvokedEvent）不需要映射任务，由调用端同步执行。
3. 检查 **Os 模块**：报警 `Rte_Al_TE_*` 会自动出现；确保 MotorTask 等任务已配置（见架构文档 §8）。
4. **Validate** 通过后 **Generate**（先生成 Os/Rte，再整体 Build）。

### 第 6 步：检查产物 + 改应用代码

生成后在 `Appl/GenData/Components/Rte_MotorControll.h` 应看到：

```c
/* 要求端 C/S：Rte_Call_<端口>_<操作> */
#define Rte_Call_Pp_MotorCdd_OutputControl_EnableOutput(arg) \
        Pp_MotorCdd_OutputControl_EnableOutput(arg)   /* 直连（同核） */
```

在 `Rte_MotorCdd.h` 应看到服务端原型：

```c
FUNC(void, MotorCdd_CODE) Pp_MotorCdd_OutputControl_EnableOutput(boolean Enable);
```

然后把应用代码里的直调替换掉：

```c
/* 旧（非标准）：MotorControll 直接调 CDD 内部函数 */
// Tle9180_Driver_EnableOutput(TRUE);

/* 新（标准）：走 RTE C/S */
(void)Rte_Call_Pp_MotorCdd_OutputControl_EnableOutput(TRUE);
```

> 同核 RTE C/S 默认是函数直连（无任务切换），所以 1 ms 慢环里调用零额外开销；跨核则由 RTE 生成队列/调用代理。

---

## 5. 实例 A：把现成的 `EnableInverter` 用起来（最小改动教学）

工程里 `Pp_MotorCdd_EnableInverter` 端口、接口和实现函数都已存在，只差“连接”和“调用方”：

| 步骤 | 位置 | 操作 |
| --- | --- | --- |
| 1 | Developer → ECU Projects → last364 | 检查连接：MotorControll.`Pp_MotorCdd_EnableInverter`（R）→ MotorCdd.`Pp_MotorCdd_EnableInverter`（P）。**本工程 FlatExtract 里已有该连接**（`MotorCdd_Pp_MotorCdd_EnableInverter_MotorControll_Pp_MotorCdd_EnableInverter`），新加端口时才需要新建 |
| 2 | Developer | 保存 → 生成 FlatMap/FlatExtract |
| 3 | Configurator | Build → Validate → **Generate RTE（务必重新生成）** |
| 4 | 检查 | `Rte_MotorControll.h` 应出现 `Rte_Call_Pp_MotorCdd_EnableInverter_EnableInverter`（当前 GenData 里没有，说明生成物过期，需重新 Generate） |
| 5 | MotorControll.c | `MotorControll_ApplyOutputGating()` 里的 `Tle9180_Driver_EnableOutput(TRUE/FALSE)` 替换为 `Rte_Call_...(TRUE/FALSE)` |
| 6 | MotorCdd.c | 实现函数 `Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg)` 里已有逻辑（FocPrepareOutputEnable + Tle9180_Driver_EnableOutput），保持不变 |

效果：MotorControll 不再直接 include 栅驱驱动，全部通过 RTE 端口通信。

---

## 6. 实例 B：新增 S/R 数据 `GateDriverState`（状态类直调标准化）

现状：`MotorControll_UpdateGateDriverObservation()` 直接调 `Tle9180_Driver_GetState()`。

| 步骤 | 位置 | 操作 |
| --- | --- | --- |
| 1 | Developer → Interfaces | 新建 SenderReceiverInterface `Pp_MotorGateDriverState`，加 DataElement `GateDriverState`（uint8） |
| 2 | MotorCdd | 加 P-PORT `Pp_MotorGateDriverState` |
| 3 | MotorControll | 加 R-PORT `Pp_MotorGateDriverState` |
| 4 | ECU Projects | 连线 MotorCdd(P) → MotorControll(R) |
| 5 | Configurator | Build → Generate RTE |
| 6 | 检查 | MotorCdd 生成 `Rte_Write_Pp_MotorGateDriverState_GateDriverState(v)`；MotorControll 生成 `Rte_Read_Pp_MotorGateDriverState_GateDriverState(&v)` |
| 7 | 改代码 | MotorCdd 主函数写：`Rte_Write_...(Tle9180_Driver_GetState())`；MotorControll 读：`Rte_Read_...(&st)` |

同理可建：`AdcOffsetReady`、`MechanicalRpm`、`FaultActive`、`Vdc` 等。

---

## 7. 标准化调用映射总表（直调 → 应生成的 `Rte_*`）

| 当前直调（非标准） | 所在组件 | 应配置的接口/端口 | 生成的 RTE API |
| --- | --- | --- | --- |
| `Tle9180_Driver_EnableOutput(bool)` | MotorControll | C/S `EnableOutput`（可复用 EnableInverter） | `Rte_Call_Pp_MotorCdd_EnableInverter_EnableInverter(bool)` |
| `MotorCdd_FocPrepareOutputEnable()` / `MotorCdd_FocStopOutput()` / `MotorCdd_FocClearFault()` | MotorControll | C/S 操作 `PrepareOutput/StopOutput/ClearFault` | `Rte_Call_Pp_MotorCdd_FocControl_StopOutput()` 等 |
| `Tle9180_Driver_GetState()/GetLastInitError()/GetOperationModeRaw()` | MotorControll | S/R `GateDriverState` 等 | `Rte_Read_Pp_MotorGateDriverState_GateDriverState(&v)` |
| `MotorCdd_AdcIsCurrentOffsetReady()` | MotorControll | S/R `AdcOffsetReady` | `Rte_Read_Pp_MotorAdcOffset_AdcOffsetReady(&v)` |
| `MotorCdd_GetAdcPhysical()`（读 Vdc/相电流） | MotorControll | S/R `DcBusVoltage`、`PhaseCurrents` | `Rte_Read_Pp_MotorDcBusVoltage_Vbus(&v)` 等 |
| `Tle5012bd_Driver_GetMechanicalRpm()` | MotorControll | S/R `MechanicalRpm` | `Rte_Read_Pp_MotorSpeed_MechanicalRpm(&v)` |
| `MotorZeroCal_Start/Erase/SaveToFlash/CanStart` | MotorControll | C/S `ZeroCalControl` | `Rte_Call_Pp_MotorCdd_ZeroCal_Start()` 等 |
| `MotorFoc_RunSpeedLoop(&MotorCdd_FocContext, rpm)` | MotorControll | C/S `SpeedLoop(rpm)`（**不要把 context 跨组件传**） | `Rte_Call_Pp_MotorCdd_SpeedLoop_SpeedLoop(rpm)` |
| `Dio_FlipChannel(...)`（StartApp LED） | StartApp | 新建 DioCdd（或复用一个 CDD）C/S `LedControl` | `Rte_Call_Pp_DioCdd_LedControl_Flip(...)` |
| `EcuM_RequestRUN(...)` | StartApp | 建议移入 EcuM/BswM 初始化或 Rte 模式端口 | 由 EcuM 生成逻辑处理 |
| `ComM_CommunicationAllowed/RequestComMode(...)` | StartApp | 建议移入 BswM 规则或 ComM 的 RTE 用户端口 | `Rte_ComM_*` / BswM 动作 |
| `Adc_*` / `Spi_*` / QSPI2 SFR（CDD 内部） | MotorCdd（CDD） | **保持直接访问（CDD 合法）**，仅整理封装 | 不需要 RTE |
| `NvM_*` / `Fee_*`（MotorZeroCal） | MotorCdd（CDD） | 保持直接访问（CDD 合法） | 不需要 RTE |
| `CanIf_Transmit` / `Com_IpduGroupStop` | MotorCdd（CDD） | 保持直接访问（CDD 合法） | 不需要 RTE |

> 规则：**应用 SW-C（MotorControll/StartApp）只能调 Rte_*；CDD（MotorCdd）允许直调 MCAL/BSW，但对其他 SW-C 只暴露 Rte 端口。**

---

## 8. 常见问题（为什么我的 `Rte_*` 没生成）

| 现象 | 原因 | 检查/解决 |
| --- | --- | --- |
| 没有 `Rte_Call_<Port>_<Operation>` | ① 要求端 R-PORT 未建；② **端口没在 ECU 工程里连线**；③ 服务端没有 OperationInvokedEvent | ①②Developer 检查连接；③ MotorCdd 内部行为加 OperationInvokedEvent → 运行实体 |
| 服务端实现函数没生成原型 | OperationInvokedEvent 的 Operation 没指向接口操作 | 事件 → `Operation` 引用指向 `接口.操作` |
| `Rte_Read/Write_<Port>_<Data>` 缺 | 端口类型/接口类型不匹配（S/R 端口却连到 C/S 接口） | 接口与端口类型一致；连线后重新 Build |
| `Rte_Ev_Run_<Runnable>` 没有 | TimingEvent 未建，或未在 Rte 里映射到任务 | Internal Behavior 加 TimingEvent；Rte → RteOsInteraction → `RteActivationOsTaskRef` |
| `Rte_Al_TE_*` 没有 | Os 未重新生成 | 先 Generate Os，再 Generate RTE |
| 生成了但编译报 undefined（如 `Rte_Call_...`） | 应用代码先写了调用、RTE 还没重新生成/没 Build | Configurator 里 Build + Generate RTE 后再编译 |
| 改端口名后 API 全变 | API 名 = 端口名+数据/操作名 | 不要随意改端口名；改完统一替换代码 |
| 跨核 Rte_Call 有开销 | 跨核 C/S 走 RTE 队列/X-Signal | 快速环不放 Rte_Call；慢环同核直连无开销 |
| `Rte_Read_...` 读到旧值 | S/R 显式读写是共享变量语义，写者没更新 | 检查写者运行实体是否周期执行（TimingEvent） |

---

## 9. 相关文件与文档索引

| 文件/文档 | 说明 |
| --- | --- |
| `Config/Developer/ComponentTypes/*.arxml` | SW-C 类型、端口、内部行为（Developer） |
| `Config/Developer/PortInterfaces.arxml` | 接口定义（S/R、C/S、Trigger） |
| `Config/Developer/ECUProjects/last364.arxml` | 端口连接（Assembly/Delegation） |
| `Config/ECUC/last364_Rte_Rte_ecuc.arxml` | Rte 事件→任务/报警映射 |
| `Config/ECUC/last364_Os_Os_ecuc.arxml` | Os 任务、报警（`Rte_Al_TE_*`） |
| `Appl/GenData/Components/Rte_<SWC>.h/.c` | RTE 生成产物（改完配置后自动更新） |
| [DaVinci_Motor_Config_Guide.md](DaVinci_Motor_Config_Guide.md) | 逐模块配置参数 |
| [DaVinci_Config_Architecture.md](DaVinci_Config_Architecture.md) | 配置架构与问题总结 |

---

## 10. 建议截图占位（可自插）

📷 图片位 A：Developer 里“接口编辑器”截图（S/R 或 C/S 接口 + 数据元素/操作）。

<!-- 自插图片：取消注释并放入图片后删除本占位块
![Developer 接口编辑](image/DaVinci_Arch/08_rte_iface.png)
-->

📷 图片位 B：Developer 里“ECU 工程连接”视图截图（Assembly 连线）。

<!-- 自插图片：取消注释并放入图片后删除本占位块
![Developer 端口连接](image/DaVinci_Arch/09_rte_connector.png)
-->

📷 图片位 C：Configurator 里 Rte → RteOsInteraction 事件映射截图。

<!-- 自插图片：取消注释并放入图片后删除本占位块
![Rte 事件映射](image/DaVinci_Arch/10_rte_os_mapping.png)
-->

