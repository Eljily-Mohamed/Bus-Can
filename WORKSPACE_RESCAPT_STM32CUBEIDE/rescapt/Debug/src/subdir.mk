################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MadgwickAHRS.c \
../src/anemo.c \
../src/drv_can.c \
../src/drv_i2c.c \
../src/drv_spi.c \
../src/drv_uart.c \
../src/dynamixel.c \
../src/hts221.c \
../src/lps22hb.c \
../src/main.c \
../src/mpu9250.c \
../src/stm32f1xx_hal_msp.c \
../src/stm32f1xx_it.c \
../src/syscalls.c \
../src/systemClock.c \
../src/system_stm32f1xx.c \
../src/tickTimer.c \
../src/util.c 

OBJS += \
./src/MadgwickAHRS.o \
./src/anemo.o \
./src/drv_can.o \
./src/drv_i2c.o \
./src/drv_spi.o \
./src/drv_uart.o \
./src/dynamixel.o \
./src/hts221.o \
./src/lps22hb.o \
./src/main.o \
./src/mpu9250.o \
./src/stm32f1xx_hal_msp.o \
./src/stm32f1xx_it.o \
./src/syscalls.o \
./src/systemClock.o \
./src/system_stm32f1xx.o \
./src/tickTimer.o \
./src/util.o 

C_DEPS += \
./src/MadgwickAHRS.d \
./src/anemo.d \
./src/drv_can.d \
./src/drv_i2c.d \
./src/drv_spi.d \
./src/drv_uart.d \
./src/dynamixel.d \
./src/hts221.d \
./src/lps22hb.d \
./src/main.d \
./src/mpu9250.d \
./src/stm32f1xx_hal_msp.d \
./src/stm32f1xx_it.d \
./src/syscalls.d \
./src/systemClock.d \
./src/system_stm32f1xx.d \
./src/tickTimer.d \
./src/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -c -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc/Legacy" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/src/vl6180x" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/Utilities/STM32F1xx_Nucleo" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/inc" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/device" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/CMSIS/core" -I"/home/mohamed/enib/projets/Bus-Can/WORKSPACE_RESCAPT_STM32CUBEIDE/rescapt/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/MadgwickAHRS.cyclo ./src/MadgwickAHRS.d ./src/MadgwickAHRS.o ./src/MadgwickAHRS.su ./src/anemo.cyclo ./src/anemo.d ./src/anemo.o ./src/anemo.su ./src/drv_can.cyclo ./src/drv_can.d ./src/drv_can.o ./src/drv_can.su ./src/drv_i2c.cyclo ./src/drv_i2c.d ./src/drv_i2c.o ./src/drv_i2c.su ./src/drv_spi.cyclo ./src/drv_spi.d ./src/drv_spi.o ./src/drv_spi.su ./src/drv_uart.cyclo ./src/drv_uart.d ./src/drv_uart.o ./src/drv_uart.su ./src/dynamixel.cyclo ./src/dynamixel.d ./src/dynamixel.o ./src/dynamixel.su ./src/hts221.cyclo ./src/hts221.d ./src/hts221.o ./src/hts221.su ./src/lps22hb.cyclo ./src/lps22hb.d ./src/lps22hb.o ./src/lps22hb.su ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su ./src/mpu9250.cyclo ./src/mpu9250.d ./src/mpu9250.o ./src/mpu9250.su ./src/stm32f1xx_hal_msp.cyclo ./src/stm32f1xx_hal_msp.d ./src/stm32f1xx_hal_msp.o ./src/stm32f1xx_hal_msp.su ./src/stm32f1xx_it.cyclo ./src/stm32f1xx_it.d ./src/stm32f1xx_it.o ./src/stm32f1xx_it.su ./src/syscalls.cyclo ./src/syscalls.d ./src/syscalls.o ./src/syscalls.su ./src/systemClock.cyclo ./src/systemClock.d ./src/systemClock.o ./src/systemClock.su ./src/system_stm32f1xx.cyclo ./src/system_stm32f1xx.d ./src/system_stm32f1xx.o ./src/system_stm32f1xx.su ./src/tickTimer.cyclo ./src/tickTimer.d ./src/tickTimer.o ./src/tickTimer.su ./src/util.cyclo ./src/util.d ./src/util.o ./src/util.su

.PHONY: clean-src

