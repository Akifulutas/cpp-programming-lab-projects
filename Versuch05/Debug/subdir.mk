################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Liste.cpp \
../ListenElement.cpp \
../Student.cpp \
../main.cpp 

CPP_DEPS += \
./Liste.d \
./ListenElement.d \
./Student.d \
./main.d 

OBJS += \
./Liste.o \
./ListenElement.o \
./Student.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Liste.d ./Liste.o ./ListenElement.d ./ListenElement.o ./Student.d ./Student.o ./main.d ./main.o

.PHONY: clean--2e-

