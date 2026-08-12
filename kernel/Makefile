# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

include config.def.mk
-include config.mk

OUTPUT = kernel.elf
INCLUDE_DIR = include

CPPFLAGS:= $(CPPFLAGS) -I../common

NASMFLAGS := -f elf32

LDFLAGS := -m elf_i386 \
		   -nostdlib \
		   -T linker.ld \
		   --verbose \
		   -L$(SYSROOT)$(LIBDIR) \
		   -lk 
		   
override SRCFILES := $(shell find -L ./ -type f 2>/dev/null | LC_ALL=C sort)
override CFILES := $(filter %.c,$(SRCFILES))
override NASMFILES := $(filter %.asm,$(SRCFILES))
OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(NASMFILES:.asm=.asm.o))
OBJ := obj/crti.o \
	   obj/crtbegin.o \
	   $(OBJ) \
	   obj/crtend.o \
	   obj/crtn.o

.PHONY: all
all: bin/$(OUTPUT)

bin/$(OUTPUT): Makefile linker.ld $(OBJ)
	mkdir -v -p "$(dir $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

obj/%.c.o: %.c Makefile
	mkdir -v -p "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.asm.o: %.asm Makefile
	mkdir -v -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

obj/crtbegin.o obj/crtend.o:
	OBJ=`$(CC) $(CFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

obj/crti.o: gcc-compat/crti.S Makefile
	mkdir -v -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

obj/crtn.o: gcc-compat/crtn.S Makefile
	mkdir -v -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

.PHONY: install
install: install-kernel install-headers

.PHONY: install-kernel
install-kernel: bin/$(OUTPUT)
	mkdir -v -p $(DESTDIR)$(BOOTDIR)
	cp -v bin/$(OUTPUT) $(DESTDIR)$(BOOTDIR)

.PHONY: install-headers
install-headers:
	mkdir -v -p $(DESTDIR)$(INCLUDEDIR)
	cp -v -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

.PHONY: clean
clean:
	rm -v -fr bin obj
