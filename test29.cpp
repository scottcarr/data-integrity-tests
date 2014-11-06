#include <iostream>
#include <string.h>
using namespace std;

// we want to be able to protect structs like this:
struct Circle {
  Circle() {}
  char *name;
  int x;
  int y;
};

__attribute__((annotate("secret"))) Circle *c;
__attribute__((annotate("secret"))) Circle yz;
__attribute__((annotate("secret"))) int z;
__attribute__((annotate("secret"))) char* zsdf;
__attribute__((annotate("secret"))) char df;


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
  
  // this should be a regular strcpy
  strcpy(c2, s.c_str());

  foo(c);

  cout << c2 << endl;

  return 0;
}
