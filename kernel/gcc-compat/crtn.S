; Copyright (C) 2026 obrigani team
; SPDX-License-Identifier: GPL-3.0-only

.intel_syntax
bits 32

section .init
	pop dword ebp
	ret

section .fini
	pop dword ebp
	ret
