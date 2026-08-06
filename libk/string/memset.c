// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <string.h>
#include <stddef.h>

void* memset(void* pbuf, int value, size_t size)
{
  unsigned char* buf = (unsigned char*) pbuf;
  for(size_t i = 0; i < size; i++)
    buf[i] = (unsigned char) value;
  return pbuf;
}
