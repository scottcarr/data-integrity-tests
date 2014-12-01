#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../../safe_functions.h"


using namespace std;

/*
overwrite protected memory using memcpy
*/

typedef struct {
  double val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  Key *ptr = (Key*)safe_malloc(sizeof(Key)*N);
  Key single_key[7]; 
  int i;

  for(i = 0; i < 7; i++){

	single_key[i].val = 42;
  }	


  memcpy(single_key, ptr, sizeof(single_key));

  return 0;
}
