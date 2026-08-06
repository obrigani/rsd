// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <string.h>
#include <stddef.h>

void* memmove(void* pdst, const void* psrc, size_t size)
{
  unsigned char* dst = (unsigned char*) pdst;
  const unsigned char* src = (const unsigned char*) psrc;

  if(dst < src) {
    for(size_t i = 0; i < size; i++)
      dst[i] = src[i];
  } else {
    for(size_t i = size; i != 0; i--)
      dst[i-1] = src[i-1];
  }
  return pdst;
}
