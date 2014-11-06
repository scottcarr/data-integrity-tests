#include <iostream>
#include <stdlib.h>
using namespace std;

struct Circle {
  char *c;
};

__attribute__((annotate("sensitive"))) struct Circle* cptr;
__attribute__((annotate("sensitive"))) struct Circle circle;
__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;


const int N = 3;

int main() {
  cptr = new Circle();
  cptr->c = new char[N];
  for (char* ptr = cptr->c, i = 0; i < N + 1; ++i, ++ptr) {
    char c;
    cin >> c;
    *ptr = c;
  }
  cout << "should never get here\n";
  return 0;
}
