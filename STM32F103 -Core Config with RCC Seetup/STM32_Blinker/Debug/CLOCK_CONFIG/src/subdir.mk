################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLOCK_CONFIG/src/rcc.c 

OBJS += \
./CLOCK_CONFIG/src/rcc.o 

C_DEPS += \
./CLOCK_CONFIG/src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
CLOCK_CONFIG/src/%.o CLOCK_CONFIG/src/%.su CLOCK_CONFIG/src/%.cyclo: ../CLOCK_CONFIG/src/%.c CLOCK_CONFIG/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I"C:/Users/Ali/Desktop/STM_Blinky/STM32_Blinker/Core/Inc" -I"C:/Users/Ali/Desktop/STM_Blinky/STM32_Blinker/CMISIS/Include" -I"C:/Users/Ali/Desktop/STM_Blinky/STM32_Blinker/CLOCK_CONFIG/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CLOCK_CONFIG-2f-src

clean-CLOCK_CONFIG-2f-src:
	-$(RM) ./CLOCK_CONFIG/src/rcc.cyclo ./CLOCK_CONFIG/src/rcc.d ./CLOCK_CONFIG/src/rcc.o ./CLOCK_CONFIG/src/rcc.su

.PHONY: clean-CLOCK_CONFIG-2f-src

