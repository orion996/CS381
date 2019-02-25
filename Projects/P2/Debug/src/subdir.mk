################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspect.cpp \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/Physics.cpp \
../src/Renderable.cpp \
../src/Rotator.cpp \
../src/TutorialApplication.cpp 

OBJS += \
./src/Aspect.o \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/Physics.o \
./src/Renderable.o \
./src/Rotator.o \
./src/TutorialApplication.o 

CPP_DEPS += \
./src/Aspect.d \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/Physics.d \
./src/Renderable.d \
./src/Rotator.d \
./src/TutorialApplication.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/OGRE -I"/home/orion996/Documents/CS/CS381/Projects/P2/inc" -I/usr/local/include/OGRE/Overlay -I/usr/include/OIS -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


