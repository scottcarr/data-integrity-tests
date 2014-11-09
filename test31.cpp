#include <string.h>
#include <iostream>
#include "safe_functions.h"
using namespace std;

struct Protected {
  char *name;
};

__attribute__((annotate("sensitive"))) Protected *pptr;
__attribute__((annotate("sensitive"))) Protected pro;
__attribute__((annotate("sensitive"))) char *cptr;
__attribute__((annotate("sensitive"))) char achar;

void foo(Protected *p) {
  char *c = p->name;
  while(*c != '\0') {
    safe_putchar(c);
    ++c;
  }
  cout << endl;
}

Protected *p0, *p1;

void copy_name(Protected* dst, Protected *src) {
  strcpy(dst->name, src->name);
}

void read_name(Protected *p) {
  char *buf = p->name;
  for (int i = 0; ; ++i) {
    safe_getchar(buf + i);
    if (*buf == '\0') {
      break;
    }
  } 
}

int main() {
  p0 = new Protected();
  p1 = new Protected();
  p0->name = new char[10];
  p1->name = new char[10];
  char buf[100];
  //char buf2[100];
  read_name(p0);
  foo(p0);
  copy_name(p1, p0);
  foo(p1);
  //strcpy(buf2, p1->name); // this is illegal now
  //cout << buf2 << endl;
}
