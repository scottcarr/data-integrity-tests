#include <iostream>
using namespace std;

__attribute__((annotate("sensitive"))) char* buf;
__attribute__((annotate("sensitive"))) char xyz;
//char* buf;
const int N = 5;

void foo() {
  for (int i = 0; i < N; ++i) {
    int j;
    j = buf[i];
    cout << j << "\n";
  }
}

int main() {
  buf = new char[N];
  for (int i = 0; i < N; ++i) {
    int j;
    cin >> j;
    buf[i] = j;
  }
  foo();
  return 0;
}
