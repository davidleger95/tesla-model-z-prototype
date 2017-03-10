################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/utils/hw_interfaces.c \
../Sources/utils/init.c \
../Sources/utils/user_instructions.c \
../Sources/utils/utils.c 

OBJS += \
./Sources/utils/hw_interfaces.o \
./Sources/utils/init.o \
./Sources/utils/user_instructions.o \
./Sources/utils/utils.o 

C_DEPS += \
./Sources/utils/hw_interfaces.d \
./Sources/utils/init.d \
./Sources/utils/user_instructions.d \
./Sources/utils/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/utils/%.o: ../Sources/utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK64FN1M0VMD12" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK64F12/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


