#include <iostream>

using namespace std;

struct Buffer {
  long int val;
};

Buffer *mybuf;
__attribute__((annotate("secret"))) Buffer s;

const int N = 5;

int main() {
  mybuf = new Buffer [N];
  for (int i = 0; i < N + 1 /* off by one*/; i++) {
    int j;
    cin >> j;
    mybuf[i].val = j;
  }
}
