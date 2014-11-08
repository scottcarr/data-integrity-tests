#include <iostream>
#include <string.h>
#include "safe_functions.h"

using namespace std;

// test memcpy to local var
// this test wont compile under the new type system

struct Protected {
  char *buf;
};

__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;
__attribute__((annotate("sensitive"))) Protected *p1, *p2;
__attribute__((annotate("sensitive"))) Protected px;

const int N = 3;

void foo() {
  for (int i = 0; i < N; i++) {
    char j;
    j =  p1->c[i];
    cout << j << endl;
  }
}

int main() {
  p1 = new Protected()
  p1->buf = new char[N];
  char *z = new char[N];
  for (int i = 0; i < N; i++) {
    char j;
    cin >> j;
    z[i] = j;
  }
  memcpy(p1->buf, z, N);
  foo();
  return 0;

}
