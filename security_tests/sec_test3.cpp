#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
overwrite protected memory using memcpy
*/

typedef struct {
  long int val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  Key *ptr = (Key*)malloc(sizeof(Key)*N);
  Key single_key[7]; 
  int i;

  for(i = 0; i < 7; i++){

	single_key[i].val = i;
  }	


  memcpy(single_key, ptr, sizeof(single_key));

  return 0;
}
