; Copyright (C) 2026 obrigani team
; SPDX-License-Identifier: GPL-3.0-only

bits 32

; Multiboot header constants
%define ALIGN    (1 << 0)        ; align loaded modules on page boundaries
%define MEMINFO  (1 << 1)        ; provide memory map
%define FLAGS    (ALIGN | MEMINFO)
%define MAGIC    0x1BADB002
%define CHECKSUM (-(MAGIC + FLAGS))

section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

; Stack (BSS)
section .bss
align 16
stack_bottom:
    resb 16384 ; 16 KiB
stack_top:

section .text
global _start
extern kmain

_start:
    mov esp, stack_top

    call kmain

    cli
.hang:
    hlt
    jmp .hang
