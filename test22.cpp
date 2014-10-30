#include <iostream>
using namespace std;

__attribute__((annotate("sensitive"))) char* buf;
const int N = 3;

void foo() {
  for (char* ptr = buf, i = 0; i < N; ++i, ++ptr) {
    char c = *ptr;
    cout << c << endl;
  }
}

int main() {
  buf = new char[N];
  for (char* ptr = buf, i = 0; i < N; ++i, ++ptr) {
    char c;
    cin >> c;
    *ptr = c;
  }
  foo();
  return 0;
}
