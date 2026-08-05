# CANape XCP：标定 IdRef / IqRef + 电机模式

> 目标：用 CANape 通过 XCP on CAN 在线写  
> - `MotorControll_IdRefCmd` / `MotorControll_IqRefCmd`  
> - `MotorControll_MotorModeCmd`（电机模式）  
> 观测：`IdRefOut` / `IqRefOut` / 实际模式 / Vbus 等。

应用侧变量**已经存在**，不必为标定再加 Com 命令帧。

量产通信矩阵与标定通道分离（AUTOSAR 常见做法）：

| 文件 | 用途 | 是否导入 DaVinci Com |
|------|------|----------------------|
| `Config_Vector/CANFD364.dbc` | 量产应用矩阵（含 `msg_MotorStatus`） | **是** |
| `Config_Vector/CANFD364_XCP_Dev.dbc` | 开发用 XCP ID 备忘（0x703/0x704） | **否** |

`msg_MotorStatus` 的 `Id_Ref/Iq_Ref/MotorMode` 只作 **TX 观测**；命令通道是 **XCP 写 RAM**（EcuC 手工配 PDU，不经 Com）。

---

## 1. 应用变量（已有，可直接标定）

| 符号 | 类型 | 用途 | A2L 类型 |
|------|------|------|----------|
| `MotorControll_MotorModeCmd` | `MotorMode_Type`(=uint8) | 模式命令 | CHARACTERISTIC |
| `MotorControll_IdRefCmd` | float32 | Id 电流命令 [A] | CHARACTERISTIC |
| `MotorControll_IqRefCmd` | float32 | Iq 电流命令 [A] | CHARACTERISTIC |
| `MotorControll_OpenLoopEnable` | uint8 | 非 0 时强制 OPEN_LOOP（会盖掉 ModeCmd） | CHARACTERISTIC（建议保持 0） |
| `MotorControll_IdRefOut` | float32 | 实际写出的 Id | MEASUREMENT |
| `MotorControll_IqRefOut` | float32 | 实际写出的 Iq | MEASUREMENT |
| `MotorControll_OpenLoopCurrentLimitA` | float32 | 开环电流限幅 | CHARACTERISTIC（可选） |

模式枚举（与 DBC `MotorMode` VAL_ 一致）：

| 值 | 含义 |
|----|------|
| 0 | Idle |
| 1 | Stop |
| 2 | FocSpeed |
| 3 | FocCurrent |
| 4 | OpenLoop |
| 5 | Calibration |
| 6 | CalibrationErase |
| 7 | CalibrationSave |

推荐调试顺序：

1. `OpenLoopEnable = 0`
2. `IdRefCmd = 0`，`IqRefCmd = 0`
3. `MotorModeCmd = 4`（OpenLoop）或 `3`（FocCurrent）
4. 再缓慢加大 `IqRefCmd` / `IdRefCmd`

---

## 2. 当前工程缺口（配置侧）

| 项 | 说明 |
|----|------|
| XCP 拓扑 | **CanIf UL=XCP** 直连；本 SIP **不要** PduR→Xcp |
| EcuC PDU | 手工 `msg_XCP_Request_Rx/Tx`（DLC=8，0x703/0x704） |
| A2L 入口 | 用 `Master.a2l`，不要指望空壳 `McData.a2l` 含应用对象 |
| Appl 符号 | 从 `Debug\last364.elf` 导入 `MotorControll_*` |
| 量产 DBC | 勿把 XCP 写回 `CANFD364.dbc` / 勿导 `*_XCP_Dev.dbc` 进 Com |

`msg_MotorStatus`（0x511）里的 `MotorMode/Id_Ref/Iq_Ref`：**不要改成 RX**，继续作反馈即可。

---

## 2.1 导完新量产 DBC 后（必做一次）

1. Update Communication / 重新导入 `CANFD364.dbc`
2. 若 Com / PduR 里仍残留旧的 `msg_XCP_*`：全部删除
3. 在 EcuC 手工保留/创建 XCP PDU（DLC=8，ID 0x703 Rx / 0x704 Tx）
4. CanIf 挂这两路 PDU，UL=**XCP**（不是 PDUR/Com）
5. Xcp 模块引用这两路 Rx/Tx PDU，`XcpOnCanEnabled=true`

---

## 3. DaVinci Configurator：XCP on CAN 配置清单

### 3.1 Xcp 模块

1. **Xcp → XcpGeneral**
   - `XcpOnCanEnabled = true`
   - `XcpMainFunctionPeriod = 0.005`（已有，与 5 ms 调度一致即可）
2. **Xcp → XcpConfig → XcpPdu**
   - `XcpRxPdu` → EcuC PDU：`msg_XCP_Request_MyECU_oCAN00_*_Rx`（0x703）
   - `XcpTxPdu` → EcuC PDU：`msg_XCP_Response_MyECU_oCAN00_*_Tx`（0x704）
3. 常用开关（调试阶段）：
   - Seed&Key = off
   - Memory protection = off

### 3.2 CanIf（本 SIP：XCP 不走 PduR）

本工程 MICROSAR 校验：`PDUR10006` — **Xcp 不是 PduR 上层模块**，不能配 `CanIf → PduR → Xcp`。

正确拓扑：

```
Tester --0x703--> CanIf Rx (UL=XCP) --> Xcp
Xcp --> CanIf Tx (UL=XCP) --0x704--> Tester
```

- CanIf `msg_XCP_Request_Rx`：`UserRxIndicationUL = XCP`，CAN ID **1795 (0x703)**
- CanIf `msg_XCP_Request_Tx`（实际 Response）：`UserTxConfirmationUL = XCP`，CAN ID **1796 (0x704)**
- **不要** UL=`COM`；**不要**再建 `PduRBswModules/Xcp` 路由
- EcuC 手工 PDU（DLC=8）；**不要**把 `CANFD364_XCP_Dev.dbc` 导入 Com

### 3.3 调度

Rte 里已有 `Xcp_MainFunctionTimingEvent0` / `CanXcp_MainFunctionTimingEvent0`，确认映射到 Core0 周期任务（如 5 ms）。

BswM / EcuM 启动链里确认有 `Xcp_Init()` / `CanXcp_Init`。

### 3.4 Generate

Validate → Generate：**Xcp + CanIf + EcuC + Rte**（本 SIP 不必为 XCP 生成 PduR 路由）。

---

## 4. A2L：给 CANape / ASAP2 Studio 用的对象

### 4.1 各 A2L 文件分工（易混）

| 文件 | 谁生成 | 作用 |
|------|--------|------|
| `Config/McData/Xcp.a2l` | **Xcp** Generate | PROTOCOL_LAYER |
| `XCP_daq.a2l` / `XCP_events.a2l` | **Xcp** Generate | DAQ/Event（未配 Event 时几乎为空） |
| `CanXcp_CT_CAN00_*.a2l` | **Xcp** Generate | XCP on CAN 传输层（ID/波特率） |
| `McData.a2l` | **McDataConverter** | 汇总 BSW MC-Support（多为空 GROUP） |
| `Master.a2l` | 手工维护入口 | `/include` 上述碎片；**给 ASAP2/CANape 打开这个** |

**McDataConverter 不是 BSW 模块**，是 DaVinci 的 Generator Feature（`.dpa` 里 `/MICROSAR/McDataConv`）。  
当前工程为 `false`，所以只 Generate Xcp 时 **`McData.a2l` 时间戳不会更新**——属正常，不是生成失败。

MC Support Data 界面：

- **A2L Master File**：建议指向 `Config/McData/Master.a2l`
- **A2L Generator Additional Parameters**：**留空**即可

即便打开 McDataConv，`McData.a2l` 也不会自动出现 `MotorControll_*`；应用对象仍要 ELF 导入或手写片段。

### 4.2 ASAP2 Studio 加载 `Master.a2l` 踩坑（已踩过）

**现象：** Messages 报 `input file 'Config\McData\XCP.a2l' not found`、`IF_DATA syntax error ... symbol expected`。

**原因与处理：**

1. **路径**  
   - Vector 模板写的是相对工程根：`Config\McData\...`  
   - `Master.a2l` 若放在 `Config\McData\`，再写 `Config\McData\xxx` 会变成双层路径 → 找不到  
   - ASAP2 有时不按 Master 所在目录解析相对路径 → **改用绝对路径**最稳

2. **文件名不一致**  

   | 模板写法 | 实际文件 |
   |----------|----------|
   | `XCP.a2l` | `Xcp.a2l` |
   | `CanXCPAsr.a2l` | `CanXcp_CT_CAN00_9df8a959_1073743619.a2l` |
   | `FrXCPAsr.a2l` / `TcpIpXCPAsr.a2l` | **本工程没有**（只用 CAN）→ 注释掉 |

3. **空 DAQ 导致语法错**  
   未配置 `XcpEventChannels` 时，`XCP_daq.a2l` / `XCP_events.a2l` / `McData_Events.a2l` 几乎只有版权头。  
   放进 `/begin DAQ` … `/end DAQ` 会触发 **IF_DATA syntax error**。  
   → **先不要 include 空 DAQ**；配好 Event 并重新 Generate 后再加回。

4. **Master 放哪都可以**，但 include 必须匹配：  
   - 放 `Config\McData\`：同目录名或绝对路径  
   - 放 `BSW364\Xcp\McData\`：用 `..\..\..\Config\McData\...` 或工程根相对路径

**当前可用的 IF_DATA 末尾写法（摘要）：**

```
/begin IF_DATA XCPplus 0x0104
  /include "E:\workFiles\TC367\TC367\workspace\last364\Config\McData\Xcp.a2l"
  // 空 DAQ 先不要 include
  /include "E:\workFiles\TC367\TC367\workspace\last364\Config\McData\CanXcp_CT_CAN00_9df8a959_1073743619.a2l"
/end IF_DATA
/include "E:\workFiles\TC367\TC367\workspace\last364\Config\McData\McData.a2l"
```

能打开 Master 后：只有协议 + CAN 传输层；**仍无应用标定变量**。

### 4.3 做法 A（推荐）：从 ELF/MAP 导入应用符号

1. 编译出带符号的 `Debug\last364.elf` / `.map`
2. CANape / ASAP2：**Address Update / Import from linker map**
3. 勾选下列符号为 Calibration / Measurement

### 4.4 做法 B：手写/合并 Appl A2L 片段

把下面片段合并进 `Master.a2l`（地址用链接后真实地址替换 `0x0`，或 `ECU_ADDRESS` + Address Update）：

```
/begin CHARACTERISTIC MotorControll_MotorModeCmd
  "Motor mode command"
  VALUE
  0x0
  VECTOR_RL_UBYTE
  0
  NO_COMPU_METHOD
  0 7
/end CHARACTERISTIC

/begin CHARACTERISTIC MotorControll_IdRefCmd
  "Id current reference command [A]"
  VALUE
  0x0
  VECTOR_RL_FLOAT32_IEEE
  0
  NO_COMPU_METHOD
  -50 50
/end CHARACTERISTIC

/begin CHARACTERISTIC MotorControll_IqRefCmd
  "Iq current reference command [A]"
  VALUE
  0x0
  VECTOR_RL_FLOAT32_IEEE
  0
  NO_COMPU_METHOD
  -50 50
/end CHARACTERISTIC

/begin CHARACTERISTIC MotorControll_OpenLoopEnable
  "Force OPEN_LOOP when !=0; keep 0 when using MotorModeCmd"
  VALUE
  0x0
  VECTOR_RL_UBYTE
  0
  NO_COMPU_METHOD
  0 1
/end CHARACTERISTIC

/begin MEASUREMENT MotorControll_IdRefOut
  "Actual Id ref after clamp [A]"
  FLOAT32_IEEE
  VECTOR_RL_FLOAT32_IEEE
  0 0 0 1
  -50 50
  ECU_ADDRESS 0x0
/end MEASUREMENT

/begin MEASUREMENT MotorControll_IqRefOut
  "Actual Iq ref after clamp [A]"
  FLOAT32_IEEE
  VECTOR_RL_FLOAT32_IEEE
  0 0 0 1
  -50 50
  ECU_ADDRESS 0x0
/end MEASUREMENT
```

模式表（CANape 显示用，可选）：

```
/begin COMPU_VTAB MotorMode_VTAB
  TAB_VERB
  0 "Idle"
  1 "Stop"
  2 "FocSpeed"
  3 "FocCurrent"
  4 "OpenLoop"
  5 "Calibration"
  6 "CalibrationErase"
  7 "CalibrationSave"
/end COMPU_VTAB
```

把 `MotorControll_MotorModeCmd` 的 `NO_COMPU_METHOD` 改成 `MotorMode_VTAB`。

---

## 5. CANape 工程设置

| 项 | 值 |
|----|-----|
| Transport | XCP on CAN |
| CAN ID Request | **0x703**（1795） |
| CAN ID Response | **0x704**（1796） |
| 观测 DBC | `CANFD364.dbc` → `msg_MotorStatus` |
| XCP ID 备忘（勿导 Com） | `CANFD364_XCP_Dev.dbc` |
| A2L | `Config/McData/Master.a2l` + ELF 导入 Appl 符号 |

操作面板建议：

1. Calibration：`MotorModeCmd`、`IdRefCmd`、`IqRefCmd`、`OpenLoopEnable`
2. Measurement：`IdRefOut`、`IqRefOut`；或 DBC 信号 `MotorMode/Id_Ref/Iq_Ref/Vbus`

---

## 6. 不需要再加的模块

| 不要加 | 原因 |
|--------|------|
| 把 XCP 写回量产 `CANFD364.dbc` | 再导入会进 Com，破坏量产矩阵 |
| 新的 `msg_MotorCmd` RX DBC | XCP 已能写 RAM |
| 新的 Com Rx Signal → SWC | 与 XCP 双通道易冲突 |
| 改 `msg_MotorStatus` 为 RX | 破坏观测语义 |
| 新的 SW-C / RTE 端口 | 标定变量已在 `MotorControll.c` |

可选增强（非必须）：

- XCP DAQ Event 绑到 1 ms MotorTask，方便曲线采样
- 把 `MotorModeCmd` 等放进独立 CAL 段（`*_CALIB` MemMap），便于页切换；现阶段 `volatile` 全局即可

---

## 7. 验收步骤

1. Configurator：`XcpOnCanEnabled=true`，Tx/Rx PDU 接好，Generate
2. 烧录；CANape CONNECT 成功（不应 TIMEOUT）
3. 读 `MotorControll_MotorModeCmd` 应为 0
4. 写 `MotorModeCmd=4`，再写小的 `IqRefCmd`（如 0.5 A）
5. 确认 `IdRefOut/IqRefOut` 跟随；`OpenLoopEnable` 保持 0
6. 写回 `MotorModeCmd=0`（Idle），电流命令清零

---

## 8. 相关文件

| 文件 | 说明 |
|------|------|
| `Appl/Source/MotorControll.c/.h` | 标定变量定义 |
| `Appl/Source/CDD/MotorFoc/MotorMode.h` | 模式枚举 |
| `Config_Vector/CANFD364.dbc` | 量产应用矩阵（无 XCP；MotorStatus 观测） |
| `Config_Vector/CANFD364_XCP_Dev.dbc` | 开发 XCP ID 备忘；**禁止**导入 Com |
| `Config/ECUC/last364_Xcp_Xcp_ecuc.arxml` | `XcpOnCanEnabled=true`；Rx/Tx PduRef → EcuC |
| `Config/ECUC/last364_CanIf_*` | XCP PDU：`User*UL = XCP`（不经 PduR） |
| `Config/McData/Master.a2l` | ASAP2/CANape 入口；include 用绝对路径 |
| `Config/McData/Xcp.a2l` / `CanXcp_CT_*.a2l` | Xcp Generate 产出 |
| `Config/McData/McData.a2l` | McDataConverter 产出（可空）；≠ 应用标定对象 |
| `last364.dpa` → `/MICROSAR/McDataConv` | `false` 时 `McData.a2l` 不会随 Generate 更新 |
| `Debug/last364.elf` | 导入 `MotorControll_*` 地址 |
