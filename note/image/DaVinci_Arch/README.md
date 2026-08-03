# DaVinci_Arch 图片目录

本文档目录存放 `DaVinci_Config_Architecture.md`（DaVinci 配置架构文档）中自插的截图。

## 命名规则

```text
NN_模块_内容.png
```

示例：

```text
01_mcu_clock.png        # Mcu 时钟配置截图
02_mcu_gtm_alloc.png    # Mcu GTM 资源分配截图
03_pwm_channels.png     # Pwm 通道配置截图
04_adc_groups.png       # Adc 组/触发配置截图
05_os_dualcore.png      # Os 双核任务/ISR 截图
06_xsignal.png          # X-Signal 配置截图
07_generate_log.png     # Generate/构建日志截图
```

## 插入语法（文档内）

```markdown
![说明文字](image/DaVinci_Arch/01_mcu_clock.png)
```

说明：

1. 图片路径为相对 `last364/note/` 的相对路径，Markdown/GitHub 均可直接渲染。
2. 建议截图尺寸 1280×720 或更高，重点参数圈出/高亮。
3. 文档中的“📷 图片位 N”占位块与编号对应，插入后把占位块删除即可。
4. 图片与文档一起提交版本管理。

