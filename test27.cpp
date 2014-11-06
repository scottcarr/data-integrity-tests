#include <iostream>
#include <string.h>
using namespace std;

// test too big memset

struct Circle {
  char *name;
};

__attribute__((annotate("secret"))) Circle *cptr;
__attribute__((annotate("secret"))) Circle c;
__attribute__((annotate("secret"))) char *ch;
__attribute__((annotate("secret"))) char chx;

const int N = 10;


int main() {
  cptr = new Circle();
  cptr->name = new char[N];
  memset(cptr->name, 'c', N+1);
  cout << "should never get here\n";
  for (int i = 0; i < N+1; ++i) {
    char j;
    j = cptr->name[i];
    cout << j << endl;
  }
}
