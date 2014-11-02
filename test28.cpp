#include <iostream>
#include <string.h>
using namespace std;
// test too big memcpy 
// this should work because the memcpy cant be replaced
// with a single store of 4 bytes

//__attribute__((annotate("sensitive"))) struct Circle* c;
__attribute__((annotate("sensitive"))) char* c;

const int N = 10;

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
  memcpy(c, z, N+1);
  cout << "should never get here\n";
  foo();
  return 0;

}
