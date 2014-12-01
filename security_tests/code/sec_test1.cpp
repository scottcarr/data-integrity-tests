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
  Key *ptr = (Key*)safe_malloc(sizeof(Key)*N);
  double over_write[N];

  int j;
  
  cout << "value of test before: " << test << "\n";	
  	
  for(int i = 0; i < N+4; ++i) {
    over_write[i] = 5.0;	
  }
  for(int i = 0; i < N; ++i) {
    //cin >> j;
    ptr[i].val = 1.0;
    
  }

  cout << "value of test after: " << test << "\n";	

  safe_write_double(&ptr[0].val);
  safe_write_double(&ptr[1].val);
  safe_write_double(&ptr[2].val);

  return 0;
}
