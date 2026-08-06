// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * main.c - The kernel entrypoint for debug and initializing procedures                *
 * =================================================================================== */

#include <common.h>
#include <stdio.h>
#include <kernel/tty.h>

void kmain(void) 
{
	init_term();

	puts("rsd v.0.1.0-alpha");
	puts("Copyright (C) 2026 obrigani team");
	puts("This is free software; see the source for copying conditions. There is NO");
	puts("warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.");
	puts("================================================================================");

	puts("   ___  __| | | | | _____  __");
	puts("/ __|/ _` | | | | |/ _ \\ \\/ / ");
	puts("\\__ | (_| | | | | | (_) >  < ");
	puts("|___/\\__,_|_|_| |_|\\___/_/\\_\\ ");
}
