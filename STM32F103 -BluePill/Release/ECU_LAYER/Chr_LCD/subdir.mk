################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_LAYER/Chr_LCD/chr_lcd.c \
../ECU_LAYER/Chr_LCD/chr_lcd_lcfg.c 

OBJS += \
./ECU_LAYER/Chr_LCD/chr_lcd.o \
./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.o 

C_DEPS += \
./ECU_LAYER/Chr_LCD/chr_lcd.d \
./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_LAYER/Chr_LCD/%.o ECU_LAYER/Chr_LCD/%.su ECU_LAYER/Chr_LCD/%.cyclo: ../ECU_LAYER/Chr_LCD/%.c ECU_LAYER/Chr_LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ECU_LAYER-2f-Chr_LCD

clean-ECU_LAYER-2f-Chr_LCD:
	-$(RM) ./ECU_LAYER/Chr_LCD/chr_lcd.cyclo ./ECU_LAYER/Chr_LCD/chr_lcd.d ./ECU_LAYER/Chr_LCD/chr_lcd.o ./ECU_LAYER/Chr_LCD/chr_lcd.su ./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.cyclo ./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.d ./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.o ./ECU_LAYER/Chr_LCD/chr_lcd_lcfg.su

.PHONY: clean-ECU_LAYER-2f-Chr_LCD

