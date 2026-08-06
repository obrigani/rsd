// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <string.h>
#include <stddef.h>

void* memcpy(void* restrict pdst, const void* restrict psrc, size_t size)
{
  unsigned char* dst = (unsigned char*) pdst;
  const unsigned char* src = (const unsigned char*) psrc;
  for(size_t i = 0; i < size; i++)
    dst[i] = src[i];
  return pdst;
}
