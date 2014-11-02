#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 3;

typedef struct {
  long int val;
} Key;


__attribute__((annotate("sensitive"))) Key mykey;
__attribute__((annotate("sensitive"))) Key *asdf;
__attribute__((annotate("sensitive"))) long int xzy;
//Key *keyPtr;
Key *keys;

void foo() {
  //cout << "keys value is: " << keys << endl;
  for (int i = 0; i < N; i++) {
    //cout << (*keys)[i].val << endl; 
    int k = keys[i].val;
    cout << k << endl; 
  }
}

int main() {
  Key *k = (Key*)malloc(sizeof(Key)*N);
  //cout << "keys addr is: " << &keys << endl;
  //cout << "k's addr is: " << &k << endl;
  //cout << "k's value is: " << k << endl;
  for (int i = 0; i < N; i++) {
    int j;
    cin >> j;
    k[i].val = j;
  }
  keys = k;
  foo();
  return 0;
}
