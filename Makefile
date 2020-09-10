#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# 
# Make files creates:
#    c1m2.map - Map file for the full build ( Use the -Map=<FILE> option )
#   *.dep - Dependency Files for each source file (main.dep, memory.dep, etc) 
#    *.o - Individual object files (main.o, memory.o, etc)
#    c1m2.out - Output Executable file
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.o Individual object files
#      %.dep Individual dep files
#      % compile-all: compiles all files but do not link
#      % build: compiles and links to target, creates also c1m2.map, *.dep, *.o, c1m2.out  	
# Platform Overrides:
#      PLATFORM = HOST or PLATFORM=MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# General Flags
CFLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1m2.out
LDFLAGS = -Wl,-Map=c1m2.map
PLATFORM=HOST

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	LD = arm-none-eabi-ld
	CFLAGS  +=-D MSP432 -mthumb -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16
	INCLUDES+=-I../include/msp432 -I../include/CMSIS/ 
	LDFLAGS += -T ../msp432p401r.lds
endif

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS+=-D HOST
endif

# begin targets here
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@

%.i : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -E -o $@

%.asm : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -S -o $@ 

# general rules
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.dep)  # one dependency file for each source

$(DEPS): %.dep: %.c
	$(CC) -M $(CFLAGS) $(INCLUDES) $< -MF $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $(TARGET)

$(OBJS): %.o: %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

# Phony Targets
.PHONY: all
build: all
.PHONY: all
all: $(TARGET)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *.map *.asm *.i *.dep

.PHONY: build
build: $(TARGET) $(DEPS)


