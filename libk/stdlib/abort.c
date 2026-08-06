#include "common.h"
#include <stdlib.h>
#include <stdio.h>

NoReturn void abort(void)
{
#ifdef __is_libk
  printf("kernel panic: abort\n");
  asm volatile("hlt");
#else
  printf("abort\n");
  // TODO: do smth
#endif
  for(;;) { }
  __builtin_unreachable(); 
}
