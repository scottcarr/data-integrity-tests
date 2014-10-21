#include <iostream>
using namespace std;

__attribute__((annotate("sensitive"))) long int* buf;
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
  buf = new long int[N];
  for (int i = 0; i < N; ++i) {
    int j;
    cin >> j;
    buf[i] = j;
  }
  foo();
  return 0;
}
