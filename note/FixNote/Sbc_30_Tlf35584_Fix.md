# Sbc_30_Tlf35584 编译修复记录

## 背景

在 `last364` 工程中加入/启用 `Sbc_30_Tlf35584` 后，执行 Debug 构建时出现编译错误。最初日志表面上停在 `Mcu_17_TimerIp_Cfg.c` 附近，但实际失败目标是 `Sbc_30_Tlf35584_Lcfg.c` 和后续的 `Sbc_30_Tlf35584.c`。

构建命令：

```powershell
cd E:\workFiles\TC367\TC367\workspace\last364\Debug
& 'D:\Program Files (x86)\TASKING\TriCore v6.2r2\ctc\bin\amk.exe' all
```

## 问题一：MemMap section 未映射

现象：

```text
Appl\GenData\MemMap_Common.h #error No MemMap section found
BSW364\_Common\Implementation\MemMap.h #error No MemMap section found
```

相关代码中使用了这些 section：

```c
SBC_30_TLF35584_START_SEC_CODE
SBC_30_TLF35584_STOP_SEC_CODE
SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED
SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
SBC_30_TLF35584_START_SEC_VAR_INIT_8BIT
SBC_30_TLF35584_STOP_SEC_VAR_INIT_8BIT
SBC_30_TLF35584_START_SEC_VAR_NOINIT_SAFE
SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_SAFE
SBC_30_TLF35584_START_SEC_VAR_NOINIT_32BIT
SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_32BIT
SBC_30_TLF35584_START_SEC_VAR_NOINIT_UNSPECIFIED
SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_UNSPECIFIED
SBC_30_TLF35584_START_SEC_VAR_NOINIT_8BIT
SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_8BIT
```

根因：

`BSW364/_Common/Implementation/_MemMap.h` 中只有 `SBC_30_FS6500_*` 的 SBC section 映射，没有 `SBC_30_TLF35584_*` 映射。

修复：

在 `BSW364/_Common/Implementation/_MemMap.h` 的 `SBC START` 区域补充 `SBC_30_TLF35584_*` 到通用 section 的映射，例如：

```c
#ifdef SBC_30_TLF35584_START_SEC_CODE
  #undef SBC_30_TLF35584_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SBC_30_TLF35584_STOP_SEC_CODE
  #undef SBC_30_TLF35584_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif
```

同理补齐 CONST、VAR_INIT、VAR_NOINIT 相关 section。

## 问题二：Compiler memory class 未定义

现象：

```text
Sbc_30_Tlf35584_Cfg.h syntax error near Sbc_30_Tlf35584_DeviceConfiguration
Sbc_30_Tlf35584_Lcfg.c syntax error near Sbc_30_Tlf35584_DeviceConfiguration
```

典型代码：

```c
extern CONST(Sbc_30_Tlf35584_DeviceConfigurationType, SBC_30_TLF35584_CONST)
  Sbc_30_Tlf35584_DeviceConfiguration[1];
```

根因：

`SBC_30_TLF35584_CONST`、`SBC_30_TLF35584_CODE`、`SBC_30_TLF35584_VAR_INIT` 等 memory class 宏没有在 `_Compiler_Cfg.h` 中定义，导致 `CONST(type, memclass)` 这类宏展开异常。

修复：

在 `BSW364/_Common/Implementation/_Compiler_Cfg.h` 的 `SBC START` 区域，参考已有 `SBC_30_FS6500_*`，补充：

```c
#define SBC_30_TLF35584_CODE
#define SBC_30_TLF35584_CODE_FAST
#define SBC_30_TLF35584_CODE_ISR

#define SBC_30_TLF35584_CONST
#define SBC_30_TLF35584_CONST_FAST
#define SBC_30_TLF35584_PBCFG
#define SBC_30_TLF35584_PBCFG_ROOT

#define SBC_30_TLF35584_VAR_PBCFG
#define SBC_30_TLF35584_VAR_INIT
#define SBC_30_TLF35584_VAR_NOINIT
#define SBC_30_TLF35584_VAR_ZERO_INIT
#define SBC_30_TLF35584_VAR_INIT_FAST
#define SBC_30_TLF35584_VAR_NOINIT_FAST
#define SBC_30_TLF35584_VAR_ZERO_INIT_FAST

#define SBC_30_TLF35584_VAR_INIT_NOCACHE
#define SBC_30_TLF35584_VAR_NOINIT_NOCACHE
#define SBC_30_TLF35584_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLF35584_APPL_DATA
```

## 问题三：SPI 数据类型名不匹配

现象：

```text
Sbc_30_Tlf35584.c 905/22 syntax error - token "<identifier>" inserted before ")"
Sbc_30_Tlf35584.c 906/22 syntax error - token "<identifier>" inserted before ")"
```

报错点：

```c
(Sbc_SpiDataType*) &Sbc_Ll_SpiOutBuffer[dId],
(Sbc_SpiDataType*) &Sbc_Ll_SpiInBuffer[dId],
```

根因：

`Sbc_30_Tlf35584.c` 默认兼容宏把 `Sbc_SpiDataType` 映射到 `Spi_DataType`：

```c
#define Sbc_SpiDataType Spi_DataType
```

但当前 Infineon MCAL SPI 头文件中实际使用的是：

```c
typedef uint8 Spi_DataBufferType;
```

也就是当前工程没有 `Spi_DataType`，只有 `Spi_DataBufferType`。

修复：

修改 `BSW364/Sbc_30_Tlf35584/Implementation/Sbc_30_Tlf35584.c`：

```c
#if !defined(Sbc_SpiDataType)
# define Sbc_SpiDataType Spi_DataBufferType
#endif
```

## 修改文件

```text
BSW364/_Common/Implementation/_MemMap.h
BSW364/_Common/Implementation/_Compiler_Cfg.h
BSW364/Sbc_30_Tlf35584/Implementation/Sbc_30_Tlf35584.c
```

## 验证结果

重新执行：

```powershell
cd E:\workFiles\TC367\TC367\workspace\last364\Debug
& 'D:\Program Files (x86)\TASKING\TriCore v6.2r2\ctc\bin\amk.exe' all
```

结果：

```text
Linking to last364.elf
Cleaning up compiler cache
```

编译通过。

剩余 warning：

```text
Sbc_30_Tlf35584.c dead assignment to "result" eliminated
vstdlib.c dead assignment to "errorId" eliminated
```

这两个 warning 不阻断编译，属于已有代码中的无效赋值优化提示。

## 后续注意

如果后续重新用 DaVinci 生成工程，`_MemMap.h`、`_Compiler_Cfg.h` 或 `Sbc_30_Tlf35584.c` 可能被覆盖，需要重新确认上述三类兼容补丁是否还在。

如果后面要把 TLF35584 从“能编译”推进到“能正常初始化和通信”，还需要重点确认：

```text
Sbc_30_Tlf35584_Init 是否被 EcuM/BswM 调用
SpiChannel/SpiSequence 是否和实际硬件 CS、QSPI 通道一致
TLF35584 的唤醒、看门狗、NORMAL/STANDBY 配置是否符合板级电路
```
