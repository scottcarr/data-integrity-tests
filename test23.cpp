#include <iostream>
using namespace std;

__attribute__((annotate("sensitive"))) char* buf;
const int N = 3;

int main() {
  buf = new char[N];
  for (char* ptr = buf, i = 0; i < N + 1; ++i, ++ptr) {
    char c;
    cin >> c;
    *ptr = c;
  }
  cout << "should never get here\n";
  return 0;
}
