# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only

include config.def.mk
-include config.mk

.SUFFIXES:

override IMAGE_NAME := rsd

QEMUFLAGS := -vga virtio

HOST_CC := cc
HOST_CFLAGS := -g -O2 -pipe

.PHONY: all
all: sysroot/boot/kernel.elf
	@echo Kernel built successfully in sysroot/boot/kernel.elf

.PHONY: dist
dist: $(IMAGE_NAME)-i386-limine.iso
	@echo ISO file build successfully in the project root

.PHONY: run
run: $(IMAGE_NAME)-i386-limine.iso
	qemu-system-i386 -cdrom $(IMAGE_NAME)-i386-limine.iso \
							$(QEMUFLAGS) \
							-chardev stdio,id=char0,mux=on,logfile=serial.log,signal=off \
							-serial chardev:char0 -mon chardev=char0

limine-binary/.downloaded:
	curl -L https://github.com/Limine-Bootloader/Limine/releases/latest/download/limine-binary.tar.gz | gunzip | tar -xf -
	touch $@

limine-binary/.built: limine-binary/.downloaded
	make -C limine-binary $(MAKEFLAGS)
	touch $@

sysroot/boot/kernel.elf:
	make DESTDIR="$(SYSROOT)" -I$(PWD) -C kernel install-headers
	make DESTDIR="$(SYSROOT)" -I$(PWD) -C libk install
	make DESTDIR="$(SYSROOT)" -I$(PWD) -C kernel install
	mkdir -p "$(SYSROOT)$(PREFIX)/share/backgrounds"
	cp -v assets/$(BOOTBACKGROUND) "$(SYSROOT)$(PREFIX)/share/backgrounds"
	
$(IMAGE_NAME)-i386-limine.iso: sysroot/boot/kernel.elf limine-binary/.built
	mkdir -p isodir

	mkdir -p isodir/boot
	cp -v sysroot/boot/kernel.elf isodir/boot
	mkdir -p isodir/boot/limine
	cp -v limine.conf limine-binary/limine-bios.sys limine-binary/limine-bios-cd.bin limine-binary/limine-uefi-cd.bin isodir/boot/limine/

	mkdir -p isodir/EFI/BOOT
	cp -v limine-binary/BOOTX64.EFI isodir/EFI/BOOT/
	cp -v limine-binary/BOOTIA32.EFI isodir/EFI/BOOT/

	mkdir -p isodir/usr/share/backgrounds
	cp -v sysroot/usr/share/backgrounds/$(BOOTBACKGROUND) isodir/usr/share/backgrounds

	xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin \
	        -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
	        -apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin \
	        -efi-boot-part --efi-boot-image --protective-msdos-label \
	        isodir -o $(IMAGE_NAME)-i386-limine.iso

	./limine-binary/limine bios-install $(IMAGE_NAME)-i386-limine.iso

	rm -v -fr isodir

.PHONY: clean
clean:
	make -I$(PWD) -C kernel clean
	make -I$(PWD) -C libk clean
	rm -fr $(SYSROOT)

.PHONY: distclean
distclean: 
	rm -v -fr *.iso limine-binary *.xz *.tar
	
.PHONY: bear
bear: clean
	make DESTDIR="$(SYSROOT)" -I$(PWD) -C kernel install-headers
	bear --output libk/compile_commands.json -- make DESTDIR="$(SYSROOT)" -I$(PWD) -C libk install
	bear --output kernel/compile_commands.json -- make DESTDIR="$(SYSROOT)" -I$(PWD) -C kernel 
