#include <stdlib.h>
#include <stdio.h>

char *s;

void foo() {
  fprintf(stderr, "i am error\n");
}

void bar() {
  s = malloc(100);
  printf("i alloced something!\n");
}

int main(int argc, char** argv) {
  printf("%s\n", "hello world");
  printf("stderr: %p\n", &stderr);
  foo();
  bar();
  return 0;
}
