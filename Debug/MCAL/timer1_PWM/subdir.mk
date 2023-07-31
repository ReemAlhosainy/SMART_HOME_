################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/timer1_PWM/timer1_PWM_prg.c 

OBJS += \
./MCAL/timer1_PWM/timer1_PWM_prg.o 

C_DEPS += \
./MCAL/timer1_PWM/timer1_PWM_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/timer1_PWM/%.o: ../MCAL/timer1_PWM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


