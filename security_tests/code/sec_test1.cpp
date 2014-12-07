#include <iostream>
#include <stdlib.h>
#include "../../safe_functions.h"

using namespace std;

/*
This test a simple over write with local variables
Since it is local also, the value of the pointer was
changed so it seg faults
*/

typedef struct {
  double val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  double test = 7.0;
  //Key *ptr = (Key*)safe_malloc(sizeof(Key)*N);
  Key ptr[N];
  double over_write[N];

  int j;

  cout << "address of test" << &test << "\n";
  cout << "address of over_write: " << &over_write << "\n";	
  	
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 1.0;
  }
  for(int i = 0; i < N+12; ++i) {
    over_write[i] = 5.0;	
  }

  cout << "value of test after(should be 7): " << test << "\n";	

  cout << "value of ptr[0].val: ";
  safe_write_double(&ptr[0].val);
  cout << "\n";
  cout << "value of ptr[1].val: ";
  safe_write_double(&ptr[1].val);
  cout << "\n";
  cout << "value of ptr[2].val: ";
  safe_write_double(&ptr[2].val);
  cout << "\n";

  return 0;
}
