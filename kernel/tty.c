// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

/* =================================================================================== * 
 * tty.c - Code used for the basic tty implementation using the VGA buffer             *
 * =================================================================================== */

#include <common.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "vga.h"

size_t term_row;
size_t term_column;
uint8_t term_color;
uint16_t* term_buffer = (uint16_t*)VGA_MEMORY;

// size_t strlen(const char* str) 
// {
// 	size_t len = 0;
// 	while(str[len])
// 		len++;
// 	return len;
// }

void init_term(void) 
{
	term_row = 0;
	term_column = 0;
	term_color = vga_entry_color(VGA_COLOR_LIGHT_BROWN, VGA_COLOR_BLACK);
	
	for(size_t y = 0; y < VGA_HEIGHT; y++) {
		for(size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			term_buffer[index] = vga_entry(' ', term_color);
		}
	}
}

void term_set_color(uint8_t color) 
{
	term_color = color;
}

void term_put_entry_at(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	term_buffer[index] = vga_entry(c, color);
}

void term_put_char(char c) 
{
	switch(c) {
		case '\n':
		case '\r':
			term_column = 0;
			term_row++;
			return;
		default: break;
	}
	term_put_entry_at(c, term_color, term_column, term_row);
	if(++term_column == VGA_WIDTH) {
		term_column = 0;
		if(++term_row == VGA_HEIGHT)
			term_row = 0;
	}
}

void term_write(const char* data, size_t size) 
{
	for(size_t i = 0; i < size; i++)
		term_put_char(data[i]);
}

void term_print(const char* data) 
{
	term_write(data, strlen(data));
}

