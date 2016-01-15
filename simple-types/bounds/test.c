#include <stdio.h>
#include <stdlib.h>

void* foo(int n) {
  printf("allocating: %i", n);
  char* buf = malloc(n);
  for (int i = 0; i < n; ++i) {
    buf[i] = 42;
  }
  return buf;
}

void bar(char* buf) {
  for (int i = 99; i >= 0; i--) {
    char x = buf[i] + 5;
    putchar(x);
  }
  putchar('\n');

}

int main(int argc, char** argv) {
  char* buf= foo(100);
  printf("buf: %p\n", buf);
  printf("buf+99: %p\n", buf+99);
  for (int i = 0; i < 99; i++) {
    buf[i] = buf[i+1];
  }
  bar(buf);

  return 0;
}
