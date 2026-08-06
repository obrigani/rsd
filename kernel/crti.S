; Copyright (C) 2026 obrigani team
; SPDX-License-Identifier: GPL-3.0-only

.intel_syntax
bits 32

section .init
global _init
_init:
        push ebp
        mov dword ebp, esp

section .fini
global _fini
_fini:
        push ebp
        mov dword ebp, esp
