#include <iostream>
#include <string.h>
using namespace std;

// test too big memset

__attribute__((annotate("sensitive"))) char *c;
__attribute__((annotate("sensitive"))) char cx;

const int N = 3;


int main() {
  c = new char[N];
  memset(c, 'c', N+1);
  cout << "should never get here\n";
  //for (int i = 0; i < N+1; ++i) {
  //  char j;
  //  j = c[i];
  //  cout << j << endl;
  //}
}
