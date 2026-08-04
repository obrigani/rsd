// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * main.c - The kernel entrypoint for debug and initializing procedures                *
 * =================================================================================== */

#include <kernel/common.h>
#include <kernel/tty.h>

void kmain(void) 
{
	init_term();

	term_print("Timoxa lox!");
	term_print("Timoxa lox!\n");
	term_print("Timoxa lox!");
}
