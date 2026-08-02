# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

OUTPUT = kernel.elf
INCLUDE_DIR = include

CC := i686-elf-gcc
LD := i686-elf-ld

CFLAGS := -g \
		  -O2 \
		  -pipe \
		  -Wall \
		  -Wextra \
		  -std=gnu23 \
		  -ffreestanding

CPPFLAGS := -Iinclude \
			-MMD \
			-MP

NASMFLAGS := -f elf32

LDFLAGS := -m elf_i386 \
		   -nostdlib \
		   -T linker.ld

override SRCFILES := $(shell find -L . -type f 2>/dev/null | LC_ALL=C sort)
override CFILES := $(filter %.c,$(SRCFILES))
override NASMFILES := $(filter %.asm,$(SRCFILES))
override OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(NASMFILES:.asm=.asm.o))

.PHONY: all
all: bin/$(OUTPUT)

bin/$(OUTPUT): Makefile linker.ld $(OBJ)
	mkdir -p "$(dir $@)"
	$(LD) $(LDFLAGS) $(OBJ) -o $@

obj/%.c.o: %.c Makefile
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.asm.o: %.asm Makefile
	mkdir -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

.PHONY: install
install: install-kernel

.PHONY: install-kernel
install-kernel: bin/$(OUTPUT)
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp bin/$(OUTPUT) $(DESTDIR)$(BOOTDIR)

.PHONY: clean
clean:
	rm -fr bin obj
