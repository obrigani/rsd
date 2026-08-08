# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only
# To use custom configs, make the config.mk file in root directory and change the values that you need.

CC := i686-elf-gcc
AR := i686-elf-ar
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

PREFIX      = /usr
EXEC_PREFIX = $(PREFIX)
BOOTDIR     = /boot
LIBDIR      = $(EXEC_PREFIX)/lib
INCLUDEDIR  = $(PREFIX)/include

SYSROOT     = "$(PWD)/sysroot"

CC +=  --sysroot=$(SYSROOT)
CC +=  -isystem=$(INCLUDEDIR)

LD +=  --sysroot=$(SYSROOT)

BOOTBACKGROUND = rsd-banner.png
