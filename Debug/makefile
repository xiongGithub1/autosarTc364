################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJ 	= last364
PRODDIR = D:\Program Files (x86)\TASKING\TriCore v6.2r2\ctc

-include "..\makefile.init"

all :

-include "subdir.mk"
-include "Appl\subdir.mk"
-include "Appl\GenData\subdir.mk"
-include "Appl\GenData\src\subdir.mk"
-include "Appl\Source\subdir.mk"
-include "Appl\Source\CDD\subdir.mk"
-include "Appl\Source\CDD\MotorFoc\subdir.mk"
-include "Appl\Source\CDD\TLE5012\subdir.mk"
-include "Appl\Source\CDD\TLE5012\TLE5012\subdir.mk"
-include "Appl\Source\CDD\TLE9180\subdir.mk"
-include "Appl\Source\TestFiles\subdir.mk"
-include "BSW364\BswM\Implementation\subdir.mk"
-include "BSW364\Can\Implementation\subdir.mk"
-include "BSW364\CanIf\Implementation\subdir.mk"
-include "BSW364\CanSM\Implementation\subdir.mk"
-include "BSW364\Com\Implementation\subdir.mk"
-include "BSW364\ComM\Implementation\subdir.mk"
-include "BSW364\Det\Implementation\subdir.mk"
-include "BSW364\E2EXf\Implementation\subdir.mk"
-include "BSW364\EcuM\Implementation\subdir.mk"
-include "BSW364\Mcal_Tc3xx\Implementation\subdir.mk"
-include "BSW364\Os\Implementation\subdir.mk"
-include "BSW364\PduR\Implementation\subdir.mk"
-include "BSW364\Sbc_30_Tlf35584\Implementation\subdir.mk"
-include "BSW364\VStdLib\Implementation\subdir.mk"
-include "MCAL364\Adc\ssc\src\subdir.mk"
-include "MCAL364\Dio\ssc\src\subdir.mk"
-include "MCAL364\Dma\ssc\src\subdir.mk"
-include "MCAL364\Irq\Adc_Irq\subdir.mk"
-include "MCAL364\Irq\Dma_Irq\subdir.mk"
-include "MCAL364\Irq\Spi_Irq\subdir.mk"
-include "MCAL364\Irq\ssc\src\subdir.mk"
-include "MCAL364\McalLib\ssc\src\subdir.mk"
-include "MCAL364\Mcu\ssc\src\subdir.mk"
-include "MCAL364\Port\ssc\src\subdir.mk"
-include "MCAL364\Pwm_17_GtmCcu6\ssc\src\subdir.mk"
-include "MCAL364\Spi\ssc\src\subdir.mk"
-include "..\makefile.defs"

PCP_FILES :=
EXT_LIBRARIES =

all : "last364.elf"

"last364.elf" : $(OBJ_FILES) $(EXT_LIBRARIES) ".last364.elf.opt"
	@echo Linking to ${@F}
	@"${PRODDIR}\bin\cctc" -f ".last364.elf.opt"

".last364.elf.opt" : .refresh
	@argfile ".last364.elf.opt" -o "last364.elf" $(OBJ_FILES) $(EXT_LIBRARIES) $(PCP_FILES)  -Ctc36x --lsl-core=vtc -t -I"E:\workFiles\TC367\TC367\workspace\last364" -Wl-o"${PROJ}.hex":IHEX:4 --hex-format=s "E:\workFiles\TC367\TC367\workspace\last364\Appl\newTc364.lsl" -Wl-OtxycL -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g --fp-model=3 -Wl--dep-file=".last364.elf.d" -Wl--make-target="last364.elf"
DEPENDENCY_FILES += ".last364.elf.d"
-include $(DEPENDENCY_FILES)

$(EXT_LIBRARIES) : .dummy

GENERATED_FILES += "last364.elf" "last364*.sre" "last364*.hex" "last364.map*" "last364.mdf" ".last364.elf.opt" ".last364.elf.d"
-include "..\makefile.targets"


all : cleanup_cache

cleanup_cache: $(OBJ_FILES)
	@echo Cleaning up compiler cache
	@"${PRODDIR}\bin\expiretc" --days=7 "E:\workFiles\TC367\TC367\workspace\last364\.cache"


clean : ".clean.opt"
	@echo Cleaning
	@rm -f -m ".clean.opt"

".clean.opt" : .refresh
	@argfile ".clean.opt" $(GENERATED_FILES) $(OPTIONAL_FILES)

GENERATED_FILES += ".clean.opt"
OPTIONAL_FILES +=  "*.pre" "*.lst" "*.p.o" "*.p.a"


.PHONY : .dummy .refresh
