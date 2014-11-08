#include <stdlib.h>
#include <stdio.h>

__attribute__((noinline)) 
void safe_getchar(char* addr) {
  int x = getchar();
  *addr = (char) x;
}

__attribute__((noinline)) 
void* safe_malloc(size_t n) {
  return malloc(n); 
}

__attribute__((noinline)) 
void safe_putchar(char* adr) {
  putchar(*adr);
}


