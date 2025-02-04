################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../GI_Program.c \
../LCD_Program.c \
../LED_program.c \
../PIR_program.c \
../Servo_program.c \
../Timer0_Program.c \
../Timer1_program.c \
../UART_Program.c \
../main2.c 

OBJS += \
./DIO_Program.o \
./GI_Program.o \
./LCD_Program.o \
./LED_program.o \
./PIR_program.o \
./Servo_program.o \
./Timer0_Program.o \
./Timer1_program.o \
./UART_Program.o \
./main2.o 

C_DEPS += \
./DIO_Program.d \
./GI_Program.d \
./LCD_Program.d \
./LED_program.d \
./PIR_program.d \
./Servo_program.d \
./Timer0_Program.d \
./Timer1_program.d \
./UART_Program.d \
./main2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


