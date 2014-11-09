#include <iostream>
#include "safe_functions.h"

using namespace std;

struct Buffer {
  long int val;
};

Buffer *mybuf;
__attribute__((annotate("sensitive"))) Buffer s;
__attribute__((annotate("sensitive"))) Buffer *ps;
__attribute__((annotate("sensitive"))) long int asdf;

const int N = 5;

int main() {
  mybuf = new Buffer [N];
  for (int i = 0; i < N + 1 /* off by one*/; i++) {
    safe_getchar((char*) &(mybuf[i].val));
  }
  cout << "should never get here\n";
}
