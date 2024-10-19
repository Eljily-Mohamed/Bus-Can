################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f103xb.s 

OBJS += \
./startup/startup_stm32f103xb.o 

S_DEPS += \
./startup/startup_stm32f103xb.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc/Legacy" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/Utilities/STM32F1xx_Nucleo" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/inc" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/device" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/core" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_stm32f103xb.d ./startup/startup_stm32f103xb.o

.PHONY: clean-startup

