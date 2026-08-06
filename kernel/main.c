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

	term_print("rsd v.0.1.0-alpha\n");
	term_print("Copyright (C) 2026 obrigani team\n");
	term_print("This is free software; see the source for copying conditions. There is NO\n");
	term_print("warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
	term_print("================================================================================");
	
	term_print("Timoxa lox!");
	term_print("Timoxa lox!\n");
	term_print("Timoxa lox!");
}
