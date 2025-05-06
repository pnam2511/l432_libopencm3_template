REPO_ROOT := $(shell git rev-parse --show-toplevel)

ifdef DEBUG
	NO_ECHO :=
else
	NO_ECHO := @
endif

SRC_DIR = src
INC_DIR = inc
OPENCM3_DIR = ../libopencm3
BUILD_DIR = build
PROJECT = app

LIBNAME = opencm3_stm32l4

# Project sources/includes
SRC_FILES = $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)*/*.c)
INCLUDES  = -I$(INC_DIR)
LD_SCRIPT = $(SRC_DIR)/device/stm32l432kcu3.ld

# Vendor sources
# SRC_FILES += 

# Vendor includes
INCLUDES += -I$(OPENCM3_DIR)/include

# Compiler Flags
CFLAGS = -g -O0 -std=c99
CFLAGS += -Wall -Wundef -Wextra -Wshadow -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
CFLAGS += -fno-common -ffunction-sections -fdata-sections
CFLAGS += -mthumb -mcpu=cortex-m4
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -DSTM32L4
CFLAGS += $(INCLUDES)

# Linker Flags
LDFLAGS = --static -nostartfiles
LDFLAGS += -T$(LD_SCRIPT)
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(PROJECT).map
LDFLAGS += -Wl,--cref
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--print-memory-usage
LDFLAGS += -specs=rdimon.specs
LDFLAGS += -L$(OPENCM3_DIR)/lib

LDLIBS  += -l$(LIBNAME)
LDLIBS  += -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

# Toolchain
PREFIX ?= arm-none-eabi-
CC    := $(PREFIX)gcc
LD    := $(PREFIX)ld
OCPY  := $(PREFIX)objcopy
ODUMP := $(PREFIX)objdump
SZ    := $(PREFIX)size
MKDIR := mkdir

OBJ_DIR = $(BUILD_DIR)/objs
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: clean

all: $(BUILD_DIR)/$(PROJECT).elf

$(BUILD_DIR):
	$(NO_ECHO)$(MKDIR) -p $(BUILD_DIR)

$(OBJ_DIR):
	$(NO_ECHO)$(MKDIR) -p $(OBJ_DIR)

# Compile
$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	@echo "Compiling $<"
	$(NO_ECHO)$(MKDIR) -p $(dir $@)
	$(NO_ECHO)$(CC) -c -o $@ $< $(CFLAGS)

# Link
$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)
	@echo "Linking $@"
	$(NO_ECHO)$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)
