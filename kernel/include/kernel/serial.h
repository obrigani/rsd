// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * serial.h - see serial.c                                                             *
 * =================================================================================== */

#pragma once

#include <sys/io.h>

#define COM1 0x3f8

int init_serial(void);

int serial_recieved(void);
char read_serial(void);
int is_trans_empty(void);
void write_serial(char a);

