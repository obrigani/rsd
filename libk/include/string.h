// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * string.h - Implementation of the standard C header
 * =================================================================================== */

#pragma once

#include <sys/cdefs.h>
#include <stddef.h>

int memcpm(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);
