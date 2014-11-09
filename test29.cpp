#include <iostream>
#include <string.h>
#include "safe_functions.h"
using namespace std;

// we want to be able to protect structs like this:
struct Circle {
  char *name;
  int x;
  int y;
};

__attribute__((annotate("sensitive"))) Circle *c1, *c2;
__attribute__((annotate("sensitive"))) Circle yz;
__attribute__((annotate("sensitive"))) int z;
__attribute__((annotate("sensitive"))) char* zsdf;
__attribute__((annotate("sensitive"))) char df;


const int N = 100;

void foo(Circle *c) {
  for (int i = 0; i < N; ++i) {
    if (c->name[i] == '\0') { break; }
    //char x;
    //x = c->name[i];
    //cout << x;
    safe_putchar(c->name + i);
  }
}


int main() {
  c1 = new Circle();
  c2 = new Circle();
  c1->name = new char[N];
  c2->name = new char[N];

  for (int i = 0; i < N-1; ++i) {
    safe_getchar(c1->name + i);
    if (c1->name[i] == '\n') {
      c1->name[i+1] = '\0';
      break;
    }
  }

  strcpy(c2->name, c1->name);
  
  foo(c2);

  return 0;
}
