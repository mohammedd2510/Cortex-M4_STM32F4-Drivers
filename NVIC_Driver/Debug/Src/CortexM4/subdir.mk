################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CortexM4/CortexM4_Core_NVIC.c \
../Src/CortexM4/CortexM4_Core_SCB.c 

OBJS += \
./Src/CortexM4/CortexM4_Core_NVIC.o \
./Src/CortexM4/CortexM4_Core_SCB.o 

C_DEPS += \
./Src/CortexM4/CortexM4_Core_NVIC.d \
./Src/CortexM4/CortexM4_Core_SCB.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CortexM4/%.o Src/CortexM4/%.su Src/CortexM4/%.cyclo: ../Src/CortexM4/%.c Src/CortexM4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-CortexM4

clean-Src-2f-CortexM4:
	-$(RM) ./Src/CortexM4/CortexM4_Core_NVIC.cyclo ./Src/CortexM4/CortexM4_Core_NVIC.d ./Src/CortexM4/CortexM4_Core_NVIC.o ./Src/CortexM4/CortexM4_Core_NVIC.su ./Src/CortexM4/CortexM4_Core_SCB.cyclo ./Src/CortexM4/CortexM4_Core_SCB.d ./Src/CortexM4/CortexM4_Core_SCB.o ./Src/CortexM4/CortexM4_Core_SCB.su

.PHONY: clean-Src-2f-CortexM4

