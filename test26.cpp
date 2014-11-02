#include <iostream>
using namespace std;

__attribute__((annotate("secret"))) char *buf;
__attribute__((annotate("secret"))) char bufx;
//char *buf;
const int N = 3;

void foo(char *b) {
  char j;
  for (int i = 0; i < N; ++i) {
    j = b[i];
    cout << j << endl;
  }

}

int main() {
  buf = new char[N];
  char j;
  for (int i = 0; i < N; ++i) {
    cin >> j;
    buf[i] = j;
  }
  foo(buf);
  return 0;
}
