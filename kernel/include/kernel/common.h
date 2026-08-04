// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * common.h - Common macroses (macri?) needed used across the system                   *
 * =================================================================================== */

#pragma once

#ifdef __linux__
#error "Use a cross-compiler, dumbass"
#endif

#ifndef __i386__
#error "Use a 32-bit cross-compiler, dumbass"
#endif
