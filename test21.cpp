#include <iostream>
#include <string.h>
using namespace std;

__attribute__((annotate("sensitive"))) char *c;
__attribute__((annotate("sensitive"))) char cx;

const int N = 3;


int main() {
  c = new char[N];
  memset(c, 'c', N);
  for (int i = 0; i < N; ++i) {
    char j;
    j = c[i];
    cout << j << endl;
  }
}
