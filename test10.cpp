#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
  long int val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) long int z;
__attribute__((annotate("sensitive"))) Key *y;

//Key *keyPtr;
Key *keys;

//void foo() {
//  //cout << "keys value is: " << keys << endl;
//  for (int i = 0; i < N+1; i++) {
//    //cout << (*keys)[i].val << endl; 
//    long int k = keys[i].val;
//    cout << k << endl; 
//  }
//  cout << "should never get here\n";
//}

int main() {
  Key *k = (Key*)malloc(sizeof(Key)*N);
  //cout << "k's addr is: " << &k << endl;
  //cout << "k's value is: " << v << endl;
  for (int i = 0; i < N+1; i++) {
    long int j;
    cin >> j;
    k[i].val = j;
  }
  keys = k;
//  foo();
  return 0;
}
