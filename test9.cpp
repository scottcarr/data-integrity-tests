#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "safe_functions.h"

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
    //int k = keys[i].val;
    //cout << k << endl; 
    safe_putchar((char*)&(keys[i].val));
  }
  putchar('\n');
}

Key *k;

int main() {
  k = (Key*)safe_malloc(sizeof(Key)*N);
  //cout << "keys addr is: " << &keys << endl;
  //cout << "k's addr is: " << &k << endl;
  //cout << "k's value is: " << k << endl;
  for (int i = 0; i < N; ++i) {
    safe_getchar((char*)&(k[i].val));
    //k[i].val = getchar();
    //getchar();
    //printf("hello world!\n");
  }
  keys = k;
  foo();
  return 0;
}
