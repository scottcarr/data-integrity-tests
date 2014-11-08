#include <iostream>
#include "safe_functions.h"

using namespace std;

struct Buffer {
  long int val;
};

Buffer *mybuf;
__attribute__((annotate("secret"))) Buffer s;
__attribute__((annotate("secret"))) Buffer *ps;
__attribute__((annotate("secret"))) long int asdf;

const int N = 5;

int main() {
  mybuf = new Buffer [N];
  for (int i = 0; i < N + 1 /* off by one*/; i++) {
    safe_getchar((char*) &(mybuf[i].val));
  }
  cout << "should never get here\n";
}
