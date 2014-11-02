#include <iostream>
using namespace std;
// test arrays with smaller than 8 byte elements

//__attribute__((annotate("sensitive"))) struct Circle* c;
__attribute__((annotate("sensitive"))) char* c;
__attribute__((annotate("sensitive"))) char cx;

const int N = 3;

void foo() {
  for (int i = 0; i < N; i++) {
    char j;
    j =  c[i];
    cout << j << endl;
  }
}

int main() {
  c = new char[N];
  for (int i = 0; i < N; i++) {
    char j;
    cin >> j;
    c[i] = j;
  }
  foo();

  return 0;

}
