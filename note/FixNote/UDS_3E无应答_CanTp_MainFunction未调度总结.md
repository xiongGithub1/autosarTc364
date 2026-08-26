# UDS 3E 无应答 / 连发进 Det — CanTp_MainFunction 未调度

> **工程：** `last364`（APP，TC364，Vector MICROSAR）  
> **主题：** 物理诊断 `0x74C` 发 `3E` 无 `0x75C` 应答、连发两帧进 Det  
> **根因：** `CanTp_MainFunction()` 未周期运行，CanTp 卡在等 TX 缓冲，应答发不出去  
> **更新日期：** 2026-08-24

诊断 ID / DBC 说明见：`note/Guides/UDS_Diagnostic_DBC_说明.md`  
Boot 侧刷写见：`autosarTc364_Boot (2)/bootNote/Boot_APP分区与刷写联调总结.md`

---

## 1. 现象

| 操作 | 结果 |
|------|------|
| CANoe 发 1 帧 `74C: 02 3E 00 00 00 00 00 00` | 总线**无** `0x75C` 应答，一般**不进** Det |
| 再发第 2 帧（或周期 `3E`） | 进 **Det** → `Det_EndlessLoop()` |
| 先发 `10 01` 再发 `3E` | **不是**必要条件；单发 `3E` 也会复现 |

应用报文（Nm、Com 周期帧）可正常收发，容易误判为「CAN 已通、只是 UDS 配置错」。

---

## 2. 易误判方向（已排除）

| 怀疑点 | 结论 |
|--------|------|
| 必须先 `10 01` 才能 `3E` | **否**。`3E 00` 在 Default Session 即可应答 `7E 00` |
| CAN ID 错（740/748 vs 74C/75C） | APP 配置为 **Req 0x74C / Resp 0x75C**；Trace 已用 74C 仍无应答 |
| ComM / Dcm 未到 FullCom | UDE 见 `ComState=0x03`、`ComM_ActiveComMode=2`，**FullCom 正常** |
| ISO-TP 格式错（缺 PCI） | 已发 `02 3E 00 …`（DLC=8），格式正确 |
| `CANTP_E_INVALID_RX_LENGTH (0x80)` | 早期 raw 发 `3E 80` 无 PCI 会触发；正确 PCI 后不是主因 |

---

## 3. UDE 关键 Watch（发完第 1 帧、未发第 2 帧）

```text
Dcm_SingletonContext.Network.ComMContext[0].ComState          → 0x03 (FullCom)
ComM_ActiveComMode.raw[0]                                       → 2 (FULL)
Dcm_SingletonContext.Network.TransportObject[0].State           → 0x08 (ONTX)
CanTp_TxState[0].ChannelState                                   → 0x41 (WAIT_BUFFER_SF)
CanTp_RxState[0].ChannelState                                   → 0x00 (IDLE)
```

### 状态含义

| 变量 | 值 | 说明 |
|------|-----|------|
| `TransportObject[0].State = 0x08` | `DCM_NET_TOBJ_STATE_ONTX` | Dcm 已处理 `3E`，正在等应答发送完成 |
| `CanTp_TxState[0] = 0x41` | `CANTP_TXSTATE_WAIT_BUFFER_SF` | CanTp 等上层通过 **CopyTxData** 提供 SF 发送缓冲 |
| `CanTp_RxState[0] = 0x00` | `CANTP_RXSTATE_IDLE` | 请求已收完 |

**结论：** RX 路径正常；卡在 **TX 状态机**。因 `CanTp_MainFunction()` 不跑，不会向 Dcm 要 Tx buffer、也不会 `CanIf_Transmit`，故 Trace **看不到 0x75C**。

---

## 4. 第二帧为何进 Det

工程配置：

- `DCM_NET_MAX_NUM_TRANSP_OBJECTS = 1`（仅 1 个 TObj）
- `DCM_NET_MULTI_CLIENT_ENABLED = OFF`

第 1 帧后 TObj 一直 **ONTX** 未释放 → 第 2 帧 `StartOfReception` 失败 → CanTp 报 **`CANTP_E_INVALID_RX_BUFFER (0x60)`**，ApiId 常为 **`0x34` (RXINIT)** → Det 死循环。

---

## 5. 根因

**`CanTp_MainFunction()` 未在 OS 周期任务中实际运行。**

CanTp 发送依赖 MainFunction 轮询：

1. 向 PduR/Dcm 请求 Tx 数据（`CopyTxData`）
2. 组 ISO-TP SF 并调用 `CanIf_Transmit`
3. 等 TxConfirmation 后释放通道

MainFunction 不跑 → 永久停在 `0x41` + TObj `0x08` → 无 `0x75C` → 连发 Det。

---

## 6. 调度位置（GenData 参考）

`Appl/GenData/Rte_SystemApplication_OsCore0.c`，任务 **`Default_BSW_ASync_Task_10ms`**：

| 周期 | 调用 |
|------|------|
| 10 ms | `Dcm_MainFunction()` |
| **5 ms** | **`CanTp_MainFunction()`** |

```c
if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms) != 0)
{
  Dcm_MainFunction();
  /* ... */
}
if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms) != 0)
{
  CanTp_MainFunction();
}
```

**处理要点：** 确认 OS 已 `StartOS()`，`Default_BSW_ASync_Task_10ms` 在跑，且 **5 ms 事件**能触发到 `CanTp_MainFunction`（DaVinci Os/Rte Generate 后检查上述代码仍在）。

---

## 7. 验证步骤

1. UDE 在 `CanTp_MainFunction` 入口下断，发 `3E`，应**周期性命中**（约 5 ms）。
2. Trace 应出现 **`75C: 02 7E 00 …`**（positive response to TesterPresent）。
3. 连发多帧 `3E` 不应再进 Det；`TransportObject[0].State` 应回到 **`0x00` (FREE)**。
4. 可选：同任务内确认 `ComM_MainFunction_0`、`CanSM_MainFunction`、`Can_MainFunction_Write` 也在跑。

---

## 8. 相关文件

| 文件 | 作用 |
|------|------|
| `Appl/GenData/Rte_SystemApplication_OsCore0.c` | BSW 周期任务，含 `CanTp_MainFunction` |
| `Appl/GenData/CanIf_Lcfg.c` | 诊断 Tx **0x75C** |
| `Appl/GenData/CanTp_Lcfg.c` / `CanTp_Cfg.h` | CanTp Rx/Tx 通道 |
| `Appl/GenData/Dcm_Lcfg.c` | 连接 / `3E` 服务 |
| `Appl/Source/StartApp.c` | `RequestComMode(FULL)` |
| `Appl/Source/Dcm_Callout_Stubs.c` | Callout 模板；**3E 应答由 BSW 自动处理**，无需应用拼包 |

---

## 9. 调试备忘

- Det 调试期可先避免 `Det_EndlessLoop` 卡死，便于看超时/状态。
- 若 Det 为 **ApiId=4, ErrorId=0x80**：多为 ISO-TP 长度非法（例如 Write 窗口 raw 发 `3E` 无 PCI）。
- 若 Det 为 **ApiId=0x34, ErrorId=0x60**：多为 TObj 忙 / Dcm 拒收，结合本文查 MainFunction 与 TObj 状态。
