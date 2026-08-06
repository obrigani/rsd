# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

include config.def.mk
-include config.mk

OUTPUT = kernel.elf
INCLUDE_DIR = include

NASMFLAGS := -f elf32

LDFLAGS := -m elf_i386 \
		   -nostdlib \
		   -T linker.ld \
		   --verbose \
		   -L$(SYSROOT)$(LIBDIR) \
		   -lk 
		   
override SRCFILES := $(shell find -L . -type f 2>/dev/null | LC_ALL=C sort)
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
	mkdir -p "$(dir $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

obj/%.c.o: %.c Makefile
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.asm.o: %.asm Makefile
	mkdir -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

obj/crtbegin.o obj/crtend.o:
	OBJ=`$(CC) $(CFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

obj/crti.o: crti.S Makefile
	mkdir -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

obj/crtn.o: crtn.S Makefile
	mkdir -p "$(dir $@)"
	nasm $(NASMFLAGS) $< -o $@

.PHONY: install
install: install-kernel install-headers

.PHONY: install-kernel
install-kernel: bin/$(OUTPUT)
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp bin/$(OUTPUT) $(DESTDIR)$(BOOTDIR)

.PHONY: install-headers
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

.PHONY: clean
clean:
	rm -fr bin obj
