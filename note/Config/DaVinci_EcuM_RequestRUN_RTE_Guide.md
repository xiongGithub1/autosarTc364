# StartApp 请求 RUN 的 RTE 标准模式配置（EcuM_RequestRUN 标准化）

> 目标：把 `StartApp.c` 里这句直调：
>
> ```c
> (void)EcuM_RequestRUN(EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig);
> ```
>
> 改成走 RTE 的标准方式（模式端口或服务端口），由 DaVinci 配置生成对应的 `Rte_*` API。

---

## 1. 为什么这句不算标准

`StartApp` 是**应用 SW-C**。AUTOSAR 规定应用 SW-C 只能通过 RTE 与外界交互，不能直接 include BSW 头文件调用 `EcuM_RequestRUN`。`EcuM_RequestRUN` 是 EcuM 的 BSW API，应通过 EcuM 服务组件在 RTE 里暴露的端口调用。

而本工程 RTE 其实**已经生成了** EcuM 的标准端口 API（`Appl/GenData/Components/Rte_EcuM.h`），只是 StartApp 还没接：

```c
/* 模式端口（EcuM 提供，模式组 currentMode） */
Rte_Switch_EcuM_currentMode_currentMode(EcuM_StateType nextMode);

/* C/S 服务（EcuM 提供，接口 EcuM_StateRequest）：
   RequestRUN / RequestPOSTRUN / ReleaseRUN / ReleasePOSTRUN / GetStateWrapper */
EcuM_RequestRUN(EcuM_UserType parg0);   // RTE 侧运行实体（服务实现）
```

---

## 2. 两种标准途径（选一）

| 途径 | 用什么 | 生成的调用 | 特点 |
| --- | --- | --- | --- |
| **A. 模式端口（推荐，即“标准模式”配置）** | ModeSwitchInterface `EcuM_CurrentMode`（模式组 `currentMode`） | `Rte_Switch_Rs_EcuM_currentMode_currentMode(RTE_MODE_EcuM_EcuM_Mode_RUN)` | AUTOSAR 模式管理的标准做法；一次调用按请求模式进入 RUN/POST_RUN/SLEEP/SHUTDOWN |
| **B. C/S 服务端口** | ClientServerInterface `EcuM_StateRequest` | `Rte_Call_Rp_EcuM_StateRequest_RequestRUN()` | 与现在的 `EcuM_RequestRUN(用户)` 最接近；UserId 由端口绑定为 `EcuMFixedUserConfig`，调用点不用再传参 |

> 两者都要：Developer 加端口 → ECU 工程连线到 EcuM 服务实例 → Configurator 重新 Generate RTE → 改代码。下面分别给步骤。

---

## 3. 方案 A：模式端口（标准模式配置）

### 第 1 步：StartApp 加“要求模式端口”（DaVinci Developer）

1. 打开 `Config/Developer/last364.dcf`。
2. 左侧 **SWC Types → StartApp → Ports** → 新建 **R-PORT**：
   - 端口名：`Rs_EcuM_currentMode`
   - 接口类型：**ModeSwitchInterface**，选择工程已有的 `EcuM_CurrentMode`
   - 模式组（Mode Group）：`currentMode`（类型 `EcuM_Mode`）
3. 保存（写回 `ComponentTypes/StartApp.arxml`）。

> 不需要加 OperationInvokedEvent：模式请求是同步调用，直接在运行实体里写 `Rte_Switch_...` 即可。

### 第 2 步：ECU 工程连线

1. 打开 **ECU Projects → last364**（组件实例视图）。
2. 连接：StartApp.`Rs_EcuM_currentMode`（R）→ EcuM.`currentMode`（P）。
   - EcuM 服务实例在工程里已存在（`EcuM_EcuSwComposition`），直接拖线即可。
3. 保存 → 刷新 FlatMap / FlatExtract。

### 第 3 步：Configurator 重新生成 RTE

1. DaVinci Configurator 打开 `last364.dpa`，**Build** 导入改动。
2. **Validate** 通过 → **Generate RTE**（必要时先 Generate Os/Rte 一起）。
3. 检查 `Appl/GenData/Components/Rte_StartApp.h` 应出现：

```c
/* 模式请求（要求端） */
Rte_Switch_Rs_EcuM_currentMode_currentMode(EcuM_StateType nextMode);
```

同时 `Rte_SystemApplication_OsCore0.c` 里 `Rte_Switch_EcuM_currentMode_currentMode` 会从“空实现 stub”变成真正转发给 EcuM 的实现。

### 第 4 步：改 StartApp 代码

```c
/* 旧（非标准） */
// (void)EcuM_RequestRUN(EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig);

/* 新（标准模式端口） */
(void)Rte_Switch_Rs_EcuM_currentMode_currentMode(RTE_MODE_EcuM_EcuM_Mode_RUN);
```

模式枚举（来自 `Rte_EcuM_Type.h`）：

| 模式 | 宏 | 值 |
| --- | --- | --- |
| RUN | `RTE_MODE_EcuM_EcuM_Mode_RUN` | 1 |
| POST_RUN | `RTE_MODE_EcuM_EcuM_Mode_POST_RUN` | 0 |
| SHUTDOWN | `RTE_MODE_EcuM_EcuM_Mode_SHUTDOWN` | 2 |
| SLEEP | `RTE_MODE_EcuM_EcuM_Mode_SLEEP` | 3 |
| STARTUP | `RTE_MODE_EcuM_EcuM_Mode_STARTUP` | 4 |
| WAKE_SLEEP | `RTE_MODE_EcuM_EcuM_Mode_WAKE_SLEEP` | 5 |

---

## 4. 方案 B：C/S 服务端口（与现在调用最接近）

### 第 1 步：StartApp 加“要求服务端口”（Developer）

1. **SWC Types → StartApp → Ports** → 新建 **R-PORT**：
   - 端口名：`Rp_EcuM_StateRequest`
   - 接口类型：**ClientServerInterface**，选择 `EcuM_StateRequest`
2. 保存。

### 第 2 步：ECU 工程连线

- StartApp.`Rp_EcuM_StateRequest`（R）→ EcuM.`StateRequest_EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig`（P）。

> 注意：EcuM 该端口名带 `EcuMFixedUserConfig` 后缀，是因为 UserId 是**端口定义参数**（PORT-DEFINED-ARGUMENT-VALUE）——调用点不用传用户 ID，RTE 自动填 `EcuMFixedUserConfig`，与旧代码传参完全等价。

### 第 3 步：Generate RTE

检查 `Rte_StartApp.h` 应出现：

```c
Rte_Call_Rp_EcuM_StateRequest_RequestRUN();   /* 无参，UserId 端口绑定 */
Rte_Call_Rp_EcuM_StateRequest_RequestPOSTRUN();
Rte_Call_Rp_EcuM_StateRequest_ReleaseRUN();
```

### 第 4 步：改代码

```c
/* 新（C/S 服务端口） */
(void)Rte_Call_Rp_EcuM_StateRequest_RequestRUN();
```

---

## 5. 方案对比与建议

| 项 | 方案 A（模式端口） | 方案 B（C/S） |
| --- | --- | --- |
| AUTOSAR 语义 | 模式请求（Mode Switch） | 服务调用（Client/Server） |
| 生成 API | `Rte_Switch_Rs_..._currentMode_currentMode(mode)` | `Rte_Call_Rp_..._RequestRUN()` |
| 是否传用户 ID | 不传（EcuM 内部按模式处理） | 端口绑定 `EcuMFixedUserConfig`，不传 |
| 扩展性 | 可顺带请求 POST_RUN/SLEEP/SHUTDOWN（一个端口管全部模式） | 每类操作一个 Operation |
| 推荐 | **推荐**（“标准模式”就是它） | 想最小改动可选 |

建议：用**方案 A**。EcuM 本来就是 mode manager，模式端口是 AUTOSAR 里 SW-C 请求模式的标准入口；方案 B 只是把 BSW API 包了一层。

---

## 6. 常见问题

| 现象 | 原因/解决 |
| --- | --- |
| `Rte_Switch_Rs_EcuM_currentMode_currentMode` 生成不出来 | ① StartApp 的 R-PORT 没选 ModeSwitchInterface；② 没在 ECU 工程连线到 EcuM.`currentMode`；③ 没重新 Generate |
| 生成的 `Rte_Switch_EcuM_currentMode_currentMode` 是空函数 | 说明**还没有 SW-C 连模式端口**（当前工程就是这种状态）；连线并重新 Generate 后变成真实实现 |
| 模式值不知道填什么 | 用 `RTE_MODE_EcuM_EcuM_Mode_RUN` 等宏（见第 3 节表），不要手写 1 |
| 调用后没进入 RUN | EcuM 有模式仲裁/最小运行时间（`EcuMRunMinimumDuration=5` 等），请求只是“申请”，最终状态看 `Rte_Mode_*`/EcuM 状态 |
| 编译报 `Rte_Call_Rp_EcuM_StateRequest_RequestRUN` undefined | 端口没连线或 RTE 未重新生成；先 Developer 连线 → Configurator Build+Generate |
| 想关掉/重启时用标准方式 | 模式端口请求 `SHUTDOWN`（配 EcuM 关闭目标）或 C/S `EcuM_SelectShutdownTarget`（`EcuM_ShutdownTarget` 接口） |

---

## 7. 相关文件

| 文件 | 说明 |
| --- | --- |
| `Config/Developer/ComponentTypes/StartApp.arxml` | StartApp 组件（改端口在这里） |
| `Config/ServiceComponents/EcuM_swc.arxml` | EcuM 服务组件（`currentMode` 模式端口、`EcuM_StateRequest` C/S 端口） |
| `Config/Developer/PortInterfaces.arxml` | 接口（`EcuM_CurrentMode`、`EcuM_StateRequest`） |
| `Config/Developer/ECUProjects/last364.arxml` | 端口连接 |
| `Config/ECUC/last364_Rte_Rte_ecuc.arxml` | RTE 事件/服务映射 |
| `Appl/GenData/Components/Rte_EcuM.h` | EcuM 已生成的 RTE API（Rte_Switch / EcuM 服务） |
| `Appl/GenData/Components/Rte_StartApp.h` | StartApp 生成的 RTE API（改完配置后出现 Rte_Switch/Rte_Call） |
| `Appl/GenData/Rte_SystemApplication_OsCore0.c` | 模式端口实现（当前是 stub，连线后变真实） |

