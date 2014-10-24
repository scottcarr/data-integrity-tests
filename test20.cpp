#include <iostream>
#include <string.h>
using namespace std;
// test memcpy to local var

//__attribute__((annotate("sensitive"))) struct Circle* c;
__attribute__((annotate("sensitive"))) char* c;

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
  // if z is a global variable then this test is fine !?
  char *z = new char[N];
  for (int i = 0; i < N; i++) {
    char j;
    cin >> j;
    z[i] = j;
  }
  memcpy(c, z, N);
  foo();
  return 0;

}
