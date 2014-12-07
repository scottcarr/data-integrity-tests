#include <iostream>
#include <stdlib.h>
#include "../../safe_functions.h"


using namespace std;

/*
access unwritten protected memory from protected memory
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
  Key *addr;


  cout << "value of addr before: ";
  safe_write_double(&addr->val);
  cout << "\n";
	
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 5.0;	
  }

  single_key.val = 19.0;
  
  cout << "value of single_key: ";
  safe_write_double(&single_key.val);
  cout << "\n";

//  addr = (Key *)&single_key + 5;
//  addr->val = 73.0;


  cout << "value of addr after: ";
  safe_write_double(&addr->val);
  cout << "\n";


  return 0;
}
