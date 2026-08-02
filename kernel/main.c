// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000 

size_t term_row;
size_t term_column;
uint8_t term_color;
uint16_t* term_buffer = (uint16_t*)VGA_MEMORY;

#ifdef __linux__
#error "Use a cross-compiler, dumbass"
#endif

#ifndef __i386__
#error "Use a 32-bit cross-compiler, dumbass"
#endif

enum Vga_Color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE,
	VGA_COLOR_GREEN,
	VGA_COLOR_CYAN,
	VGA_COLOR_RED,
	VGA_COLOR_MAGENTA,
	VGA_COLOR_BROWN,
	VGA_COLOR_LIGHT_GREY,
	VGA_COLOR_DARK_GREY,
	VGA_COLOR_LIGHT_BLUE,
	VGA_COLOR_LIGHT_GREEN,
	VGA_COLOR_LIGHT_CYAN,
	VGA_COLOR_LIGHT_RED,
	VGA_COLOR_LIGHT_MAGENTA,
	VGA_COLOR_LIGHT_BROWN,
	VGA_COLOR_WHITE,
};

static inline uint8_t vga_entry_color(enum Vga_Color fg, enum Vga_Color bg) 
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str) 
{
	size_t len = 0;
	while(str[len])
		len++;
	return len;
}

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
	if(c == '\n' || c == '\r') {
		term_column = 0;
		term_row++;
		return;
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

void kmain(void) 
{
	init_term();

	term_print("Sall lox!");
	term_print("Sall lox!\n");
	term_print("Sall lox!");
}
