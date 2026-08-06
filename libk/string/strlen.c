// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string.h>
#include <stddef.h>

size_t strlen(const char* str)
{
  size_t len = 0;
  while(str[len])
    len++;
  return len;
}
