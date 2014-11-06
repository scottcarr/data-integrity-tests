#include <iostream>
#include <string.h>
using namespace std;
// test too big memcpy 
// this should work because the memcpy cant be replaced
// with a single store of 4 bytes

struct Circle {
  char *c;
};

__attribute__((annotate("sensitive"))) struct Circle* cptr;
__attribute__((annotate("sensitive"))) struct Circle* zptr;
__attribute__((annotate("sensitive"))) struct Circle circle;
__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;

const int N = 10;

void safe_read(Circle *circle) {
  for (int i = 0; i < N; i++) {
    char j;
    cin >> j;
    circle->c[i] = j;
  }
}

void foo() {
  for (int i = 0; i < N; i++) {
    char j;
    j =  zptr->c[i];
    cout << j << endl;
  }
}

int main() {
  cptr = new Circle();
  zptr = new Circle();
  cptr->c = new char[N];
  zptr->c = new char[N];
  safe_read(zptr);
  //c = new char[N];
  // if z is a global variable then this test is fine !?
  //char *z = new char[N];
  memcpy(cptr->c, zptr->c, N+1);
  cout << "should never get here\n";
  foo();
  return 0;

}
