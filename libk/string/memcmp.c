// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string.h>
#include <stddef.h>

int memcpm(const void* psrc1, const void* psrc2, size_t size)
{
  const unsigned char* src1 = (const unsigned char*) psrc1;
  const unsigned char* src2 = (const unsigned char*) psrc2;

  for(size_t i = 0; i < size; i++) {
    if(src1[i] < src2[i])
      return -1;
    else if(src2[i] < src1[i])
      return 1;
  }
  return 0;
}
