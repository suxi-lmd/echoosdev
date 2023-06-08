ARMGNU ?= aarch64-linux-gnu
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -Iinclude

OUT_DIR = out
SRC_DIR = src
LINKER_DIR = linker

all: clean mkoutdir echoos.img

mkoutdir:
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.S
	$(ARMGNU)-gcc $(GCCFLAGS) -MMD -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(ARMGNU)-gcc $(GCCFLAGS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(OUT_DIR)/%.o)

echoos.img: $(LINKER_DIR)/linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T $(LINKER_DIR)/linker.ld $(OBJ_FILES) -e _start -o $(OUT_DIR)/echoos.elf
	$(ARMGNU)-objcopy -O binary $(OUT_DIR)/echoos.elf $(OUT_DIR)/echoos.img

run:
	qemu-system-aarch64 -machine raspi4 -nographic -kernel $(OUT_DIR)/echoos.img
debug:
	qemu-system-aarch64 -machine raspi4 -nographic -kernel $(OUT_DIR)/echoos.img -S -s
