// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include "common.h"
// #include <stdint.h>

AlwaysInline void outb(uint16_t port, uint8_t value)
{
  asm volatile("outb %0, %1" : : "a"(value), "Nd"(port));
} 

AlwaysInline void outw(uint16_t port, uint16_t value)
{
  asm volatile("outw %0, %1" : : "a"(value), "Nd"(port));
} 

AlwaysInline void outl(uint16_t port, uint32_t value)
{
  asm volatile("outl %0, %1" : : "a"(value), "Nd"(port));
} 

AlwaysInline uint8_t inb(uint16_t port)
{
  uint8_t value;
  asm volatile ("inb %1, %0"
  : "=a"(value)
  : "Nd"(port));
  return value;
}

AlwaysInline uint16_t inw(uint16_t port)
{
  uint16_t value;
  asm volatile ("inb %1, %0"
  : "=a"(value)
  : "Nd"(port));
  return value;
}

AlwaysInline uint32_t inl(uint16_t port)
{
  uint32_t value;
  asm volatile ("inb %1, %0"
  : "=a"(value)
  : "Nd"(port));
  return value;
}
