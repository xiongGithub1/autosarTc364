# Boot 共存：vLinkGen / APP 头 / CRC 补丁

> **工程：** `last364`（APP，双核）  
> **配对：** `autosarTc364_Boot (2)`  
> **主题：** APP 让出 Boot 区、去掉 BMHD、镜像头、post-build 写 length/crc  
> **更新日期：** 2026-08-20

Boot 侧刷写 / CANoe 见：  
`autosarTc364_Boot (2)/bootNote/Boot_APP分区与刷写联调总结.md`

**禁止手改** DaVinci 生成的 `vLinkGen_Template.lsl` 作为长期手段；Generate 会冲掉。逻辑组请在 DaVinci 配好。临时 LSL 补丁需在 Generate 后重新加回。

---

## 1. 目标布局（与 Boot 对齐）

| 区域 | 地址 |
|------|------|
| Boot（禁止占用） | `0x80000000`～`0x8001FFFF` |
| APP | `0x80020000`～`0x801FFFFF` |
| BMHD | **仅 Boot**；APP 禁用 |
| `DSPR_Core0` | `0x70000000`，size **159616** |
| `Variables_Shared` | **`0x70026F80`**，size **128** |
| `StartupStack_Shared` | `0x70027000`，size 36864 |
| 握手 | **`0x70026FC0`**，64 B |

---

## 2. 问题与处理一览

| # | 现象 | 根因 | 处理 |
|---|------|------|------|
| 1 | Calculated Start `0x80000000` 灰色改不了 | 只读 = 硬件基址 + **Offset** | 父区域 **Offset=`0x20000`**，Size=`0x1E0000` |
| 2 | 删 FirstExec 后 `ltc E106: _Brs_ExcVect_START` | 异常向量 / Startup 逻辑组被删 | 重建 `Brs_ExcVect`、`Brs_Startup_Code`，Region 挂 **`PFlash0_Cached`**（含 Section） |
| 3 | APP 仍出 BMHD | `BrsHw.c` 的 `bmiField0` | `#if 0` 包住（BMHD 只留 Boot） |
| 4 | post-build：`magic ... is 0xf003624c, expected 0xa5c3b007` | `Appl_BootHeader` **unreferenced 被裁掉**；`0x80020000` 是别的 rodata | `__at(0x80020000)` + `used`/`protect`；确认 `.map` 头在 `0x80020000` |
| 5 | 以为边传边算 CRC 就不用 patch | 下载 CRC ≠ 上电跳转用的头字段 | 见第 5 节 |
| 6 | 空洞填 `0xFF` | TC3xx PFlash 擦除态是 **`0x00`** | `patch_app_header.py` 已用 `ERASE_BYTE=0x00` |

---

## 3. DaVinci vLinkGen 操作要点

### 3.1 PFlash

1. 删除/禁用：`StartupCode_FirstExecInst`、`CoreExceptions_FirstExecInst`、`BMHD0`  
2. 区域 `PFlash0_Cached`：**Offset = `0x20000`**，**Size = `0x1E0000`**  
3. Block 仍 `LOWER` / Position `0` → Calculated Start 应为 **`0x80020000`**  
4. Valid Content Types 需含：`GLOBAL_EXCVEC_CONST`、`STARTUP_CODE` 等  

### 3.2 逻辑组（勿只建空壳）

**`Brs_ExcVect`**

- Content：`GLOBAL_EXCVEC_CONST`  
- Region：`PFlash0_Cached` / `PFlash0_Cached`  
- Section：align 256；`brsExcVect` + `brsExcVectConst`；Flags ORDERED/CONTIGUOUS/FILL/READ/EXECUTE  

**`Brs_Startup_Code`**

- Content：`STARTUP_CODE`  
- Region：同上  
- Sections：`brsStartup`、`brsMainStartup`  

**`App_BootHeader`（推荐在 DaVinci 建，Position 最前）**

- Section：`AppBootHdr`（与源码 `#pragma section farrom "AppBootHdr"` 一致）  
- 或依赖源码 `__at(0x80020000)`（当前实现）  

### 3.3 共享 RAM

与 Boot 表一致：`DSPR_Core0` 159616、`Variables_Shared` @ `0x70026F80` / 128。

Generate 后核对 LSL：`dest_offset = 0x80020000`，无 `0x80000000` FirstExec / BMHD memory。

---

## 4. 源码与工程文件

| 路径 | 说明 |
|------|------|
| `Appl/Include/Boot_Mem.h` | 与 Boot 同约定的分区/头/握手 |
| `Appl/Include/Appl_BootCompat.h` | `Appl_RequestBoot()` / `Appl_BootHeader` |
| `Appl/Source/Appl_BootCompat.c` | 头 `@0x80020000`；握手写 `0x70026FC0` 后复位 |
| `Appl/Source/BrsHw.c` | BMHD `#if 0` |
| `Tools/patch_app_header.py` | 写 length/crc 进 HEX |
| `Tools/patch_app_header.bat` | post-build 入口 |
| `.cproject` | Post-build 调用 bat（IDE 界面可能不显示，可手动粘贴） |

回 Boot（刷写前）：

```c
#include "Appl_BootCompat.h"
Appl_RequestBoot();  /* 写握手 + BrsHwSoftwareResetECU */
```

---

## 5. length / CRC：为何还要 patch

| 机制 | 谁算 | 用途 |
|------|------|------|
| 下载流式 CRC | Boot `TransferData` → `Boot_LastCrc` | 本次 `31 FF02` |
| 镜像头 length/crc32 | 编译后 **patch**（或将来 Boot 收完写 Flash） | **每次上电** `Boot_App_IsImageValid` 跳转 |

CRC 规则（与 Boot 一致）：

- AUTOSAR / IEEE-802.3 CRC32（`binascii.crc32`）  
- 范围 `[0x80020000, +length)`；头内 **crc 字段按 0** 再算  
- **先写入 length，再算 crc**（length 参与 CRC）  
- `length` 向上对齐到 **32**；空洞按擦除态 **`0x00`**

---

## 6. 编译后 patch 读哪里 / 写哪里

**默认原地覆盖。**

| 配置 | 读 / 写 |
|------|---------|
| Debug | `last364\Debug\last364.hex` |
| Release | `last364\Release\last364.hex` |

Post-build 命令（Properties → C/C++ Build → Settings → **Build Steps** → Post-build）：

```text
"${ProjDirPath}/Tools/patch_app_header.bat" "${ProjDirPath}/${ConfigName}/last364.hex"
```

手动：

```bat
Tools\patch_app_header.bat Debug\last364.hex
```

成功示例：

```text
[patch_app_header] last364.hex
  magic  = 0xa5c3b007
  entry  = 0x........
  length = 0x........
  crc32  = 0x........
```

**不需要**再单独做“重组 HEX”；脚本按地址排序写出，并把 length 对齐到 32。链接基址已由 vLinkGen 定在 `0x80020000`。

---

## 7. 刷写前自检

- [ ] `.map`：`Appl_BootHeader` @ **`0x80020000`**，非 `unreferenced`  
- [ ] patch 成功（magic 正确）  
- [ ] 无 BMHD 段进 HEX  
- [ ] 无代码落入 `0x80000000`～`0x8001FFFF`  
- [ ] 用 **已 patch** 的 `Debug\last364.hex` 交给 Boot FlashPanel  

---

## 8. 相关笔记

- `note/FixNote/DualCore_vLinkGen_MemMap_问题总结.md` — 双核 MemMap / vBRS  
- Boot：`bootNote/Boot_APP分区与刷写联调总结.md`
