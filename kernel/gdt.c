// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <kernel/gdt.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

GDT_Entry gdt[GDT_SIZE];

GDT_Ptr pgdt;

TSS tss;

extern void flush_tss(void);

uint8_t kernel_stack[8192] __attribute__((aligned(16)));

void init_tss()
{
  tss.prev_task_link = 0;
  tss.esp0 = (uint32_t)(&kernel_stack[8192 - sizeof(uint32_t)]); // Pointer to the stack
  tss.ss0 = 0x10;
  tss.esp1 = 0;
  tss.ss1 = 0;
  tss.esp2 = 0;
  tss.ss2 = 0;
  tss.cr3 = 0; // Page dir pointer
  tss.eip = 0;
  tss.eflags = 0x0;
  // General-purpose registers for assembly n shit
  tss.eax = 0;
  tss.ecx = 0;
  tss.edx = 0;
  tss.ebx = 0;
  tss.esp = 0;
  tss.ebp = 0;
  tss.esi = 0;
  tss.edi = 0;
  // Segment selectors for the current task
  tss.es = 0x10; // Kern data
  tss.cs = 0x08; // Kern code
  tss.ss = 0x10; // Kern data
  tss.ds = 0x10; // Kern data
  tss.fs = 0x10; // Kern data
  tss.gs = 0x10; // Kern data
  tss.ldt = 0; // No LDT
  tss.trap = 0;
  tss.iobase = 0xFFFF; // I/O base address
}

void gdt_set_entry(int num, uint32_t base, uint32_t limit, uint8_t access,
                   uint8_t granular)
{
  gdt[num].limit_low = (limit & 0xFFFF);
  gdt[num].base_low = (base & 0xFFFF);
  gdt[num].base_middle = (base >> 16) & 0xFF;
  gdt[num].access = access;
  gdt[num].granular = (granular & 0xF0) | ((limit >> 16) & 0x0F);
  gdt[num].base_high = (base >> 24) & 0xFF;
}

void init_gdt()
{
  printf("[LOG] GDT Setup... ");

  gdt_set_entry(0, 0, 0, 0, 0);

  gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

  gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

  gdt_set_entry(3, 0x0C800000, USERSPACE_LIMIT, 0xFA, 0xCF);

  gdt_set_entry(4, 0x0C800000, USERSPACE_LIMIT, 0xF2, 0xCF);

  memset(&tss, 0, sizeof(TSS));
  init_tss();
  gdt_set_entry(5, (uint32_t)&tss, sizeof(TSS), 0x89, 0x40);
  puts("OK");

  pgdt.limit = (sizeof(gdt) - 1);
  pgdt.location = (uint32_t)&gdt;
  printf("[LOG] Loading GDT...");

  // Load the GDT using inline assembly
  asm volatile(
    "cli\n"
    "lgdt (%0)\n"
    "mov $0x10, %%ax\n"
    "mov %%ax, %%ds\n"
    "mov %%ax, %%es\n"
    "mov %%ax, %%fs\n"
    "mov %%ax, %%gs\n"
    "mov %%ax, %%ss\n"
    "mov $0x08, %%ax\n"
    "jmp $0x08, $1f\n"
    "1:\n"
    :
    : "r" (&pgdt)
    : "memory"
  );
  flush_tss();
  puts("OK");

}
