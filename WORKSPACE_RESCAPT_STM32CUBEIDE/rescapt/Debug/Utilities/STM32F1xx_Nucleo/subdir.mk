################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.c 

OBJS += \
./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F1xx_Nucleo/%.o Utilities/STM32F1xx_Nucleo/%.su Utilities/STM32F1xx_Nucleo/%.cyclo: ../Utilities/STM32F1xx_Nucleo/%.c Utilities/STM32F1xx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -c -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc/Legacy" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/src/vl6180x" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/Utilities/STM32F1xx_Nucleo" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/inc" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/device" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/core" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Utilities-2f-STM32F1xx_Nucleo

clean-Utilities-2f-STM32F1xx_Nucleo:
	-$(RM) ./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.cyclo ./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.d ./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.o ./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.su

.PHONY: clean-Utilities-2f-STM32F1xx_Nucleo

