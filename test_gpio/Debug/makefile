################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := test_gpio
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: test_gpio

# Tool invocations
test_gpio: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	aarch64-unknown-linux-gnu-gcc -L/home/user/eclipse-workspace/sysroot/lib/lib -L/home/user/eclipse-workspace/sysroot-glibc-linaro-2.25-2019.12-aarch64-linux-gnu/usr/lib -L/home/user/eclipse-workspace/sysroot/lib/lib/aarch64-linux-gnu -o "test_gpio" $(OBJS) $(USER_OBJS) $(LIBS) -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) test_gpio
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
