#include <iostream>
#include "safe_functions.h"

using namespace std;
// test arrays with smaller than 8 byte elements

struct Protected {
  char *buf;
};

//__attribute__((annotate("sensitive"))) struct Circle* c;
__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;
__attribute__((annotate("sensitive"))) Protected *p;
__attribute__((annotate("sensitive"))) Protected px;

const int N = 3;

void foo() {
  for (int i = 0; i < N; i++) {
    safe_putchar((char*) p->buf + i);
  }
}



int main() {
  p = new Protected();
  p->buf = new char[N];
  for (int i = 0; i < N; i++) {
    safe_getchar((char*) p->buf + i);
  }
  foo();

  return 0;

}
