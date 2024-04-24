################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PCD8544.c \
../src/test_gpio.c 

C_DEPS += \
./src/PCD8544.d \
./src/test_gpio.d 

OBJS += \
./src/PCD8544.o \
./src/test_gpio.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	aarch64-unknown-linux-gnu-gcc -I/home/user/eclipse-workspace/sysroot/local/wiringPi -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/PCD8544.d ./src/PCD8544.o ./src/test_gpio.d ./src/test_gpio.o

.PHONY: clean-src

