<!--
 * @Author: qinXiong
 * @Date: 2026-08-05 11:32:08
 * @LastEditors: xiong&&2307975018@qq.com
 * @LastEditTime: 2026-08-05 17:04:23
 * @Description: 
-->
# DaVinci 逐模块配置文档（TC364 电机工程）

> 本目录把电机工程在 DaVinci Configurator 中用到的每个模块，拆成一份独立的配置文档。
> 每份文档给出：模块在工程中的作用、DaVinci 里的配置路径与参数、与其它模块的引用关系、注意事项，以及预留的“截图位”（用户自插操作截图）。
>
> 总览与架构：[DaVinci_Config_Architecture.md](../DaVinci_Config_Architecture.md)
> 模块参数总指南：[DaVinci_Motor_Config_Guide copy.md](../DaVinci_Motor_Config_Guide%20copy.md)

---

## 模块清单（点击打开对应配置文档）

| # | 模块 | 详细配置文档 | 在电机工程中的作用 |
| --- | --- | --- | --- |
| 1 | Mcu | [DaVinci_Mcu.md](DaVinci_Mcu.md) | 时钟/PLL、GTM 通道、ADC 触发、硬件资源分配 |
| 2 | Port | [DaVinci_Port.md](DaVinci_Port.md) | 引脚复用模式、方向、初始电平 |
| 3 | Pwm | [DaVinci_Pwm.md](DaVinci_Pwm.md) | ATOM0 CH1/2/3 周期/中心对齐初始化（10 kHz） |
| 4 | Adc | [DaVinci_Adc.md](DaVinci_Adc.md) | EVADC G0/G2/G3 同步采样、GTM 硬件触发、通知 |
| 5 | Spi | [DaVinci_Spi.md](DaVinci_Spi.md) | QSPI1（SBC）/ QSPI2（TLE5012）/ QSPI3（TLE9180） |
| 6 | Dio | [DaVinci_Dio.md](DaVinci_Dio.md) | 9183 控制脚、CAN 收发器、LED/测试点 |
| 7 | Irq | [DaVinci_Irq.md](DaVinci_Irq.md) | 中断源/类别/优先级/核归属 |
| 8 | Os | [DaVinci_Os.md](DaVinci_Os.md) | 双核任务、报警、ISR、X-Signal |
| 9 | EcuM | [DaVinci_EcuM.md](DaVinci_EcuM.md) | 启动序列、驱动初始化列表、多核 callout |
| 10 | BswM | [DaVinci_BswM.md](DaVinci_BswM.md) | 初始化动作表、CAN PDU 组规则 |
| 11 | Can | [DaVinci_Can.md](DaVinci_Can.md) | MCAN0 波特率/FD、收发中断 |
| 12 | CanIf | [DaVinci_CanIf.md](DaVinci_CanIf.md) | CAN PDU（0x511/0x200/0x210）、Tx 缓冲 |
| 13 | Com | [DaVinci_Com.md](DaVinci_Com.md) | 信号/IPdu 组、0x511 映射、周期发送 |
| 14 | NvM | [DaVinci_NvM.md](DaVinci_NvM.md) | NvM 块（MotorZeroCal）与读写队列 |
| 15 | Fee | [DaVinci_Fee.md](DaVinci_Fee.md) | Fee 块/页/扇区映射 |
| 16 | Fls | [DaVinci_Fls.md](DaVinci_Fls.md) | DFlash 基址/容量/模式 |
| 17 | ResourceM | [DaVinci_ResourceM.md](DaVinci_ResourceM.md) | MCAL 资源 → Core0/Core1 归属 |
| 18 | Sbc | [DaVinci_Sbc.md](DaVinci_Sbc.md) | TLF35584（QSPI1）通道引用与 ERR 监控 |
| 19 | Rte | [DaVinci_Rte.md](DaVinci_Rte.md) | SW-C 映射、事件/数据一致性、生成 |

---

## 截图放置约定

- 每份模块文档的截图放在它旁边的 `image/DaVinci_<模块名>/` 目录，例如 `DaVinci_Modules/image/DaVinci_Mcu/1785902033896.png`。
- 每个截图位保留两行，供“图床 / 本地”一键切换：
![本地文件名](image/DaVinci_Mcu/本地文件名.png)
<!-- ![图床文件名](https://cdn.jsdelivr.net/gh/xiongGithub1/picGoUpload/image/图床文件名.png) -->
- 两行成对出现即可被切换脚本识别；本地文件名与图床文件名可以不同。

## 图床 / 本地快速切换

切换脚本：[toggle_image_source.ps1](../toggle_image_source.ps1)（位于 `note/` 下，自动扫描全部 md）。

### 怎么运行（两种方式）

**方式一：双击快捷文件（推荐，最简单）**

在 `last364/note/` 目录下直接双击：

| 文件 | 作用 |
| --- | --- |
| [switch_to_cdn.bat](../switch_to_cdn.bat) | 一键切到图床（CDN） |
| [switch_to_local.bat](../switch_to_local.bat) | 一键切到本地图片 |

双击后会弹出黑色窗口，跑完显示 `toggled N pair(s) -> mode=cdn`（或 `local`），按任意键关闭。

**方式二：PowerShell 命令行**

1. 打开 PowerShell：`Win + R` 输入 `powershell` 回车；或在文件管理器空白处 `Shift + 右键` → “在此处打开 PowerShell 窗口”；
2. 进入 note 目录：

```powershell
cd E:\workFiles\TC367\TC367\workspace\last364\note
```

3. 运行（`-ExecutionPolicy Bypass` 用于绕过系统脚本策略，否则可能报“禁止运行脚本”）：

```powershell
# 切到图床（当前默认）
powershell -ExecutionPolicy Bypass -File ..\toggle_image_source.ps1 -Mode cdn

# 切到本地图片
powershell -ExecutionPolicy Bypass -File ..\toggle_image_source.ps1 -Mode local

# 只预览会改哪些文件，不写盘
powershell -ExecutionPolicy Bypass -File ..\toggle_image_source.ps1 -DryRun
```

### 输出怎么看

- 每个文件一行：`[DaVinci_Mcu.md] toggled 10 pair(s) -> mode=cdn`，表示该文件翻了 10 对图；
- 末尾 `Total pairs processed: N` 是本次一共切换的对数；
- 末尾 `Unpaired image lines` 列出的行只有一种来源（只有本地或只有图床），脚本不会改动它们，需要补上另一行才能参与切换。

### 常见问题

| 现象 | 处理 |
| --- | --- |
| 提示“无法加载，因为在此系统上禁止运行脚本” | 命令里保留 `-ExecutionPolicy Bypass`；或在 PowerShell 里先执行 `Set-ExecutionPolicy -Scope Process Bypass` |
| 双击 bat 后窗口一闪而过 | 正常会停在 `pause` 等按键；若仍一闪而过说明 bat 被改动，改用命令行方式 |
| 只有部分文件被切换 | 其余是未配对的图片行，按输出的 `Unpaired image lines` 提示补行即可 |

### 脚本做了什么

- 脚本自动把每一对“本地行 / 图床行”翻转为指定模式：本地模式激活本地路径、图床模式激活 CDN 链接，另一行保留为注释备份。
- 未配对的图片行（只有一种来源，例如架构文档占位、MotorConfig 老笔记）会被列出来，但不会改动。
- 已在工程中验证：来回切换后所有 md 文件字节级一致，可放心反复切换。

## 打包分享

把整个 `note` 目录压缩即可，md 里的本地图片相对路径解压后仍然有效：

```powershell
Compress-Archive -Path ..\note\* -DestinationPath ..\DaVinci_Note_Docs_<日期>.zip
```

> 已打好一个示例包：`last364/DaVinci_Note_Docs_20260805.zip`（约 10 MB，192 个文件），可直接解压使用。

- 给别人在线看：用图床模式，md 直接渲染 CDN 图片，不用带图片目录；
- 给别人离线包：先切本地模式，再压缩整个 `note` 目录（含 `DaVinci_Modules/image/`）。

## 推荐配置顺序

1. Mcu → 2. Port → 3. Pwm → 4. Adc → 5. Spi → 6. Dio → 7. ResourceM
→ 8. Irq → 9. Os → 10. EcuM → 11. BswM → 12. Can/CanIf/Com → 13. NvM/Fee/Fls → 14. Rte → 生成与编译。

（详细顺序见 [DaVinci_Motor_Config_Guide copy.md](../DaVinci_Motor_Config_Guide%20copy.md) 第 16 节。）
