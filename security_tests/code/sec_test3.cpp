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

  //cout << "addr of ptr: " << ptr << "\n";
  //cout << "addr of single_key: " << &single_key << "\n";
  //cout << "addr of i: " << &i << "\n"; 

  for(i = 0; i < 7; i++){
	single_key[i].val = 42;
  }	

  memcpy(ptr, single_key, sizeof(single_key));

  cout << "tried to over write with the value 42\n";

  cout << "value of ptr[0]: ";
  safe_write_double(&ptr[0].val);
  cout << "\n";
  cout << "value of ptr[1]: ";
  safe_write_double(&ptr[1].val);
  cout << "\n";
  cout << "value of ptr[2]: ";
  safe_write_double(&ptr[2].val);
  cout << "\n";
  cout << "value of ptr[3]: ";
  safe_write_double(&ptr[3].val);
  cout << "\n";
  cout << "value of ptr[4]: ";
  safe_write_double(&ptr[4].val);
  cout << "\n";
  cout << "value of ptr[5]: ";
  safe_write_double(&ptr[5].val);
  cout << "\n";
  cout << "value of ptr[6]: ";
  safe_write_double(&ptr[6].val);
  cout << "\n";
  cout << "value of ptr[7]: ";
  safe_write_double(&ptr[7].val);
  cout << "\n";
  return 0;
}
