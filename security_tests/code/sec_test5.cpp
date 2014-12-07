#include <iostream>
#include <stdlib.h>
#include "../../safe_functions.h"


using namespace std;

/*
access other memory locations from protected memory
*/

typedef struct {
  double val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  Key *ptr = (Key*)safe_malloc(sizeof(Key)*N);
  Key single_key; 
  Key *addr = (Key*)safe_malloc(sizeof(Key));
	
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 5.0;	
  }

  single_key.val = 19.0;
  
  cout << "value of addr (original): ";
  safe_write_double(&addr->val);
  cout << "\n";
 
//  cout << "single_key.val: ";
//  safe_write_double(&single_key->val);  

  addr = (Key *)&single_key - sizeof(double)*7;
  addr->val = 73.0;

  cout << "value of addr (altered): ";
  safe_write_double(&addr->val);
  cout << "\n";

  return 0;
}
