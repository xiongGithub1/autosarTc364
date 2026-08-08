# CANFD364 诊断（UDS）报文 DBC 配置说明

> 项目：last364（TC364，AUTOSAR Vector MICROSAR）
> 文件：`Config_Vector/CANFD364.dbc`
> 更新：2026-08-05

## 1. 背景与目的

在整车主通信矩阵 `CANFD364.dbc` 中加入 UDS 诊断报文，用于 ECU 下线/产线/整车诊断：

- **0x74C**：物理寻址诊断请求（CANoe/Tester 发给本 ECU）
- **0x75C**：物理寻址诊断响应（本 ECU 回给 Tester）
- **0x7DF**：功能寻址诊断请求（广播，所有节点响应）

帧格式为 **8 字节经典 CAN 帧**（跑在 CAN FD 总线上，VFrameFormat=StandardCAN），
通过 ISO-TP（传输层）承载 UDS 服务（如 0x10 会话、0x22 读 DID、0x2E 写 DID、0x27 安全访问等）。

## 2. 报文定义

| CAN ID | 十进制 | 报文名 | 方向 | DLC | 用途 |
|---|---|---|---|---|---|
| 0x74C | 1868 | `msg_diag_Request_MyECU` | Tester → MyECU | 8 | 物理寻址诊断请求（Dcm Rx） |
| 0x75C | 1884 | `msg_diag_Response_MyECU` | MyECU → Tester | 8 | 物理寻址诊断响应（Dcm Tx） |
| 0x7DF | 2015 | `msg_diag_RequestGlobal` | Tester → 广播 | 8 | 功能寻址诊断请求（Dcm 功能 Rx） |

每条报文含 1 个 64 位数据信号占位（`Signal_DiagRequestMyECU` / `Signal_DiagResponseMyECU` / `Signal_DiagRequestGlobal`），
实际诊断数据由 Dcm/ISO-TP 填充，DBC 信号仅用于矩阵/工具展示。

## 3. DBC 中的具体配置

### 3.1 BO_ 报文块

```
BO_ 1868 msg_diag_Request_MyECU: 8 Tester
 SG_ Signal_DiagRequestMyECU : 0|64@1+ (1,0) [0|1.8446744074E+019] ""  MyECU

BO_ 1884 msg_diag_Response_MyECU: 8 MyECU
 SG_ Signal_DiagResponseMyECU : 0|64@1+ (1,0) [0|1.8446744074E+019] ""  Tester

BO_ 2015 msg_diag_RequestGlobal: 8 Tester
 SG_ Signal_DiagRequestGlobal : 0|64@1+ (1,0) [0|1.8446744074E+019] ""  MyECU
```

- `BO_ <ID> <名称>: <DLC> <发送节点>`：ID 为十进制（0x74C=1868）；
- `SG_` 信号的接收节点即报文接收方。

### 3.2 BA_ 属性

| 报文 | 属性 | 值 | 含义 |
|---|---|---|---|
| 1868 / 1884 / 2015 | `VFrameFormat` | 0 | StandardCAN（8 字节经典 CAN 帧） |
| 1868 / 1884 / 2015 | `GenMsgILSupport` | 1 | CANdb++/IL 支持 |
| 1868 / 1884 / 2015 | `GenMsgSendType` | 1 | spontanX（事件触发，非周期） |
| 1868 / 1884 / 2015 | `GenMsgCycleTime` | 0 | 无固定周期 |
| 1868 / 1884 / 2015 | `DiagConnection` | 57345 | 诊断连接号（0xE001） |
| 1868 / 2015 | `DiagRequest` | 1 | 标记为诊断请求 |
| 1884 | `DiagResponse` | 1 | 标记为诊断响应 |

### 3.3 新增属性定义

原 `CANFD364.dbc` 没有诊断属性，本次补充：

```
BA_DEF_ BO_  "DiagConnection" INT 0 65535;
BA_DEF_ BO_  "DiagRequest" ENUM  "No","Yes";
BA_DEF_ BO_  "DiagResponse" ENUM  "No","Yes";
BA_DEF_ BO_  "DiagUUDTResponse" ENUM  "No","Yes";

BA_DEF_DEF_  "DiagConnection" 0;
BA_DEF_DEF_  "DiagRequest" "No";
BA_DEF_DEF_  "DiagResponse" "No";
BA_DEF_DEF_  "DiagUUDTResponse" "No";
```

## 4. 关键属性说明

- **VFrameFormat**：0=StandardCAN，14=StandardCAN_FD。当前按经典 CAN 配；
  若整条总线上诊断也要走 CAN FD，改为 14（同时注意 DLC 和速率/数据场设置）。
- **DiagConnection**：诊断连接标识，DaVinci Dcm 导入后对应一个物理/功能寻址连接；
  本工程沿用之前的 57345（0xE001）。如需区分物理与功能连接，可分别用不同值。
- **DiagRequest / DiagResponse / DiagUUDTResponse**：向量工具/DaVinci 用于识别
  请求/响应/周期响应的标记；本工程只用到 Request/Response。

## 5. 诊断寻址说明

- **物理寻址（0x74C / 0x75C）**：Tester 只与本 ECU 一对一通信；
  响应使用 0x75C（= 请求 ID 0x74C + 0x10，符合常规 UDS 物理寻址规则）。
- **功能寻址（0x7DF）**：广播帧，总线上所有支持功能寻址的 ECU 同时响应；
  功能寻址通常只配 **Rx**，不配 Tx。
- 数据经 **ISO-TP（ISO 15765-2）** 分段传输，Dcm 内部完成单帧/连续帧组包。

## 6. DaVinci 配置步骤

1. 用更新后的 `Config_Vector/CANFD364.dbc` 重新导入 DaVinci Configurator；
2. EcuC 中 **Dcm** 模块：
   - 新建诊断连接（DiagConnection），关联 0x74C/0x75C；
   - **物理请求 PDU**：CanIf Rx PDU ← `msg_diag_Request_MyECU`（0x74C）；
   - **物理响应 PDU**：CanIf Tx PDU → `msg_diag_Response_MyECU`（0x75C）；
   - **功能请求 PDU**：CanIf Rx PDU ← `msg_diag_RequestGlobal`（0x7DF），勾选功能寻址；
   - 配置 ISO-TP 参数（STmin、BlockSize、扩展寻址按需）。
3. **CanIf / Can**：确认三帧已生成对应 Rx/Tx HTH（硬件句柄）且方向正确；
4. 生成代码并集成（RTE/Dcm 回调在 EcuM 启动后激活）。

## 7. CANoe 测试

1. CANoe 打开工程，确认 DBC 加载了更新后的 `CANFD364.dbc`；
2. **物理请求**：用 0x74C 发送 UDS 请求（如 10 03 会话控制），
   期望 ECU 在 **0x75C** 回 50 03 正响应；
3. **功能请求**：用 0x7DF 发送（如 3E 00 保持活动/10 02），
   期望本 ECU 在 0x75C（或配置的功能响应 ID）响应；
4. 用 CANoe 的 Diagnostic Console / CAPL 校验 ISO-TP 分段与超时。

## 8. 注意事项

- **FD vs 经典**：当前按经典 CAN 帧（VFrameFormat=0）配置，8 字节 DLC；
  若整矩阵切 FD，需要把诊断帧也改为 14 并确认收发双方一致。
- **功能寻址只收不发**：0x7DF 不要配置为 Tx，否则会污染广播。
- **ID 冲突**：本次新增 ID 与现有报文（512/528/1297/3221225472）无冲突；
  后续新增报文前先 `rg -n "^BO_ " CANFD364.dbc` 检查 ID。
- **备份**：修改前已备份为 `Config_Vector/CANFD364_backup_before_diag.dbc`，
  如需回退直接覆盖回去即可。
- **XCP**：标定/XCP 不在本矩阵（见 `CANFD364_XCP_Dev.dbc`），诊断报文不影响。

## 9. 涉及文件

| 文件 | 说明 |
|---|---|
| `Config_Vector/CANFD364.dbc` | 主通信矩阵（已加 3 帧诊断报文） |
| `Config_Vector/CANFD364_backup_before_diag.dbc` | 修改前备份 |
| `Config_Vector/CANFD364_XCP_Dev.dbc` | XCP 专用矩阵（未改动） |