#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
  long int val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key *mykey;
__attribute__((annotate("sensitive"))) Key ykey;
__attribute__((annotate("sensitive"))) long int y;

Key *ptr;

int main() {
  ptr = (Key*)malloc(sizeof(Key)*N);
  int j;
  for(int i = 0; i < N+1; ++i) {
    cin >> j;
    ptr[i].val = j;
  }
  cout << "should never get here\n";
  return 0;
}
