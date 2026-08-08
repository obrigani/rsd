; Copyright (C) 2026 obrigani team
; SPDX-License-Identifier: GPL-3.0-only

global flush_tss
flush_tss:
        mov ax, 0x28
        ltr ax
        ret
