// Copyright (C) 2026 obrigani team
// SPDX-License-Identifier: GPL-3.0-only

#include <stdio.h>

// #ifdef __is_libk
#include <kernel/tty.h>
// #endif

int putchar(int ic)
{
#ifdef __is_libk
  char c = (char) ic;
  term_write(&c, sizeof(c));
#else
  // TODO
#endif
  return ic;
}
