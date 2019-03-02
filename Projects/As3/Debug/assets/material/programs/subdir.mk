################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../assets/material/programs/Example_FresnelPS.asm \
../assets/material/programs/OffsetMapping_specular.asm 

OBJS += \
./assets/material/programs/Example_FresnelPS.o \
./assets/material/programs/OffsetMapping_specular.o 


# Each subdirectory must supply rules for building sources it contributes
assets/material/programs/%.o: ../assets/material/programs/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


