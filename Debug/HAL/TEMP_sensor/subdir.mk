################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/TEMP_sensor/TEMP_sensor_prg.c 

OBJS += \
./HAL/TEMP_sensor/TEMP_sensor_prg.o 

C_DEPS += \
./HAL/TEMP_sensor/TEMP_sensor_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/TEMP_sensor/%.o: ../HAL/TEMP_sensor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


