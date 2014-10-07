#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
  int val;
} Key;


__attribute__((annotate("sensitive"))) Key mykey;
//Key *keyPtr;
Key *keys;

void foo() {
  cout << "keys value is: " << keys << endl;
  for (int i = 0; i < 3; i++) {
    //cout << (*keys)[i].val << endl; 
    int k = keys[i].val;
    cout << k << endl; 
  }
}

int main() {
  Key *k = (Key*)malloc(sizeof(Key)*3);
  cout << "k's value is: " << k << endl;
  for (int i = 0; i < 3; i++) {
    int j;
    cin >> j;
    k[i].val = j;
  }
  keys = k;
  foo();
  return 0;
}
