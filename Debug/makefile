################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/timer1_PWM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TEMP_sensor/subdir.mk
-include HAL/SERVO_PWM/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LDR/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TEMP_sensor.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: TEMP_sensor.elf secondary-outputs

# Tool invocations
TEMP_sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TEMP_sensor.map -mmcu=atmega32 -o "TEMP_sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TEMP_sensor.lss: TEMP_sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TEMP_sensor.elf  >"TEMP_sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TEMP_sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TEMP_sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TEMP_sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
