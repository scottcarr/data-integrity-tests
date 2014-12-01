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
  Key *addr = (Key*)safe_malloc(sizeof(Key));
	
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 5.0;	
  }

  single_key.val = 19.0;

  addr = (Key *)&single_key + 37;
  addr->val = 73.0;


  return 0;
}
