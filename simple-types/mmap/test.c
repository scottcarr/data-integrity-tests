#include <sys/mman.h>
#include <stdio.h>

int main(int argc, char** argv) {
  void* addr = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
  printf("addr: %p\n", addr);
  return 0;
}
