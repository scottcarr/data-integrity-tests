#include <stdio.h>

static int num;

void foo() {
  num += 1;
}

int main(int argc, char** argv) {
  num = getc(stdin);
  foo();
  num += 5;
  return num;
}
