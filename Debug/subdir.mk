################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2048.cpp \
../heuristics.cpp \
../lookahead.cpp \
../priority.cpp 

OBJS += \
./2048.o \
./heuristics.o \
./lookahead.o \
./priority.o 

CPP_DEPS += \
./2048.d \
./heuristics.d \
./lookahead.d \
./priority.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


