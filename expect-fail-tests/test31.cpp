#include <string.h>
#include <iostream>
using namespace std;

struct Protected {
  char *name;
};

__attribute__((annotate("secret"))) Protected *pptr;
__attribute__((annotate("secret"))) Protected pro;
__attribute__((annotate("secret"))) char *cptr;
__attribute__((annotate("secret"))) char achar;

void foo(Protected *p) {
  char *c = p->name;
  while(*c != '\0') {
    cout << *c;
    ++c;
  }
  cout << endl;
}

Protected *p0, *p1;

void copy_name(Protected* dst, Protected *src) {
  strcpy(dst->name, src->name);
}

int main() {
  p0 = new Protected();
  p1 = new Protected();
  p0->name = new char[10];
  p1->name = new char[10];
  char buf[100];
  char buf2[100];
  cin >> buf;
  strcpy(p0->name, buf);
  foo(p0);
  copy_name(p1, p0);
  foo(p1);
  strcpy(buf2, p1->name);
  cout << buf2 << endl;
}
