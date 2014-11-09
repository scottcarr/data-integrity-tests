#include <stdlib.h>
#include <stdio.h>

__attribute__((noinline)) 
void* safe_malloc(size_t n) {
  return malloc(n); 
}

__attribute__((noinline)) 
void safe_getchar(char* addr) {
  int x = getchar();
  *addr = (char) x;
}

__attribute__((noinline)) 
void safe_putchar(char* adr) {
  putchar(*adr);
}

__attribute__((noinline)) 
void safe_read_double(double* addr) {
  scanf("%lf", addr);
}

__attribute__((noinline)) 
void safe_write_double(double* addr) {
  printf("%lf", *addr);
}




