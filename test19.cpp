#include <iostream>
#include <string.h>
#include "safe_functions.h"
using namespace std;

// test memcpy

struct Protected {
  char *buf;
};

__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;
__attribute__((annotate("sensitive"))) Protected *p1, *p2;
__attribute__((annotate("sensitive"))) Protected px;

char *z;

const int N = 3;

void foo() {
  for (int i = 0; i < N; i++) {
    //char j;
    //j =  c[i];
    //cout << j << endl;
    safe_putchar(p1->buf + 1);
  }
}

int main() {
  p1 = new Protected();
  p2 = new Protected();
  p1->buf = new char[N];
  p2->buf = new char[N];
  for (int i = 0; i < N; i++) {
    safe_getchar(p2->buf + i);
  }
  memcpy(c, z, N);
  foo();
  return 0;
}
