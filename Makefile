UNAME := $(shell uname)

OUT_DIR = out
SRC_DIR = src
LINKER_DIR = linker

all: clean mkoutdir echoos.img

mkoutdir:
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(OUT_DIR)/%.o)

ifeq ($(UNAME), Linux)
ARMGNU = aarch64-linux-gnu
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -Iinclude

$(OUT_DIR)/%.o: $(SRC_DIR)/%.S
	$(ARMGNU)-gcc $(GCCFLAGS) -MMD -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(ARMGNU)-gcc $(GCCFLAGS) -MMD -c $< -o $@

echoos.img: $(LINKER_DIR)/linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T $(LINKER_DIR)/linker.ld $(OBJ_FILES) -e _start -o $(OUT_DIR)/echoos.elf
	$(ARMGNU)-objcopy -O binary $(OUT_DIR)/echoos.elf $(OUT_DIR)/echoos.img
endif

ifeq ($(UNAME), Darwin)
LLVMPATH = /opt/homebrew/opt/llvm/bin
CLANGFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -mcpu=cortex-a72+nosimd -Iinclude

$(OUT_DIR)/%.o: $(SRC_DIR)/%.S
	$(LLVMPATH)/clang --target=aarch64-elf $(CLANGFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(LLVMPATH)/clang --target=aarch64-elf $(CLANGFLAGS) -c $< -o $@

echoos.img: $(LINKER_DIR)/linker.ld $(OBJ_FILES)
	$(LLVMPATH)/ld.lld -T $(LINKER_DIR)/linker.ld -m aarch64elf -nostdlib $(OBJ_FILES) -e _start -o $(OUT_DIR)/echoos.elf
	$(LLVMPATH)/llvm-objcopy -O binary $(OUT_DIR)/echoos.elf $(OUT_DIR)/echoos.img
endif
