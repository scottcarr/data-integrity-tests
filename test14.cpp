#include <iostream>
#include "safe_functions.h"
using namespace std;

struct Circle {
  long int x;
  long int y;
  double pi;
};

struct Circle *c;

__attribute__((annotate("sensitive"))) struct Circle s;
__attribute__((annotate("sensitive"))) struct Circle *sptr;
__attribute__((annotate("sensitive"))) double dddd;
__attribute__((annotate("sensitive"))) long int longdddd;

void foo(bool read) {
  if (read) {
    //double d;
    //cin >> d;
    //c->pi = d;
    safe_read_double(&(c->pi));
  } else {
    //double d;
    //d = c->pi;
    safe_write_double(&(c->pi));
    cout << "\n";
  }
}
int main() {
  c = new Circle();
  foo(true);
  foo(false);
  return 0;
}
