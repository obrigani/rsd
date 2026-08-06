// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * stdio.h - Implementation of the standard C header
 * =================================================================================== */

#include <stdio.h>

#define EOF (-1)

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);
