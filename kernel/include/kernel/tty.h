// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * tty.h - see tty.c                                                                   *
 * =================================================================================== */

#pragma once

#include <stdint.h>
#include <stddef.h>

size_t strlen(const char* str);
void init_term(void);
void term_write(const char* data, size_t size);
void term_print(const char* data);
