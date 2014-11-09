#include <iostream>
#include <string.h>
#include "safe_functions.h"
using namespace std;

// we want to be able to protect structs like this:
struct Circle {
  Circle() {}
  char *name;
  int x;
  int y;
};

__attribute__((annotate("sensitive"))) Circle *c;
__attribute__((annotate("sensitive"))) Circle yz;
__attribute__((annotate("sensitive"))) int z;
__attribute__((annotate("sensitive"))) char* zsdf;
__attribute__((annotate("sensitive"))) char df;


const int N = 100;

void foo(Circle *c) {
  for (int i = 0; i < N; ++i) {
    if (c->name[i] == '\0') { break; }
    char x;
    x = c->name[i];
    cout << x;
  }
  cout << endl;
}

void safe_strcpy(Circle *dst, const char* src){
  for (int i = 0; i < N; ++i) {
    c->name[i] = src[i];
    if (src[i] == '\0') { break; }
  }
}

int main() {
  c = new Circle();
  c->name = new char[N];
  char* c2 = new char[N];
  string s;
  cin >> s;

  safe_strcpy(c, s.c_str());
  
  foo(c);

  cout << c2 << endl;

  return 0;
}
