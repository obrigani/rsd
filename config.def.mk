# Copyright (C) 2026 obrigani team
# SPDX-License-Identifier: GPL-3.0-only
# config.def.mk - The default config options for building the OS
# To use custom configs, copy this file and name it config.mk and then run the make command as `make CONFIG=config.mk`

export PREFIX=/usr
export EXEC_PREFIX=$(PREFIX)
export BOOTDIR=/boot
export LIBDIR=$(EXEC_PREFIX)/lib
export INCLUDEDIR=$(PREFIX)/include

export SYSROOT="$(PWD)/sysroot"
