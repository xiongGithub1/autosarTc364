<!--
 * @Author: qinXiong
 * @Date: 2026-08-05 11:32:08
 * @LastEditors: xiong&&2307975018@qq.com
 * @LastEditTime: 2026-08-05 18:43:55
 * @Description: 
-->
# DaVinci 逐模块配置文档（TC364 电机工程）

> 本目录把电机工程在 DaVinci Configurator 中用到的每个模块，拆成一份独立的配置文档。
> 每份文档给出：模块在工程中的作用、DaVinci 里的配置路径与参数、与其它模块的引用关系、注意事项。
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
- 文档正文只保留**激活的图片行**（当前为本地路径），不再保留 `<!-- ... -->` 备份注释（2026-08-05 已清理，避免预览时显示注释）。

## 打包分享

把整个 `note` 目录压缩即可，md 里的本地图片相对路径解压后仍然有效：

```powershell
Compress-Archive -Path ..\note\* -DestinationPath ..\DaVinci_Note_Docs_<日期>.zip
```

> 已打好一个示例包：`last364/DaVinci_Note_Docs_20260805.zip`（约 10 MB，192 个文件），可直接解压使用。

- 文档当前使用本地图片（相对路径），压缩整个 `note` 目录即可；在线平台需支持相对路径渲染。

## 推荐配置顺序

1. Mcu → 2. Port → 3. Pwm → 4. Adc → 5. Spi → 6. Dio → 7. ResourceM
→ 8. Irq → 9. Os → 10. EcuM → 11. BswM → 12. Can/CanIf/Com → 13. NvM/Fee/Fls → 14. Rte → 生成与编译。

（详细顺序见 [DaVinci_Motor_Config_Guide copy.md](../DaVinci_Motor_Config_Guide%20copy.md) 第 16 节。）
