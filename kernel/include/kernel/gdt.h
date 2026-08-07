// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <stdint.h>

#define GDT_SIZE 6
#define USERSPACE_SIZE  0xF0000000
#define USERSPACE_LIMIT ((USERSPACE_SIZE -1) >> 12)

typedef struct {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t  base_middle;
  uint8_t  access;
  uint8_t  granular;
  uint8_t  base_high;
} __attribute__((packed)) GDT_Entry;

typedef struct {
  uint16_t limit;
  uint32_t location;
} __attribute__((packed)) GDT_Ptr; 

typedef struct {
  uint32_t prev_task_link;
  uint32_t esp0;
  uint32_t ss0;
  uint32_t esp1;
  uint32_t ss1;
  uint32_t esp2;
  uint32_t ss2;
  uint32_t cr3;
  uint32_t eip;
  uint32_t eflags;
  uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi;
  uint32_t es, cs, ss, ds, fs, gs;
  uint32_t ldt;
  uint16_t trap;
  uint16_t iobase;
} __attribute__((packed)) TSS; 

void init_gdt(void);
void init_tss(void);
uint16_t add_tss_to_gdt(TSS* tss);
