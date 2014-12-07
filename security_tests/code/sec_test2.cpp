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
Key *ptr;
Key *ptr1;

int main() {
  int test = 7;
  ptr = (Key*)safe_malloc(sizeof(Key)*N);
  ptr1 = (Key*)safe_malloc(sizeof(Key)*N);

  int j;
  
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 1.0;
    ptr1[i].val = 4.0; 
  }
  ptr1[3].val = 4.0; 
  ptr1[4].val = 4.0; 
  ptr1[5].val = 4.0; 

  cout << "value of ptr[0]: ";
  safe_write_double(&ptr[0].val);
  cout << "\n";
  cout << "value of ptr[1]: ";
  safe_write_double(&ptr[1].val);
  cout << "\n";
  cout << "value of ptr[2]: ";
  safe_write_double(&ptr[2].val);
  cout << "\n";
  cout << "value of ptr1[0]: ";
  safe_write_double(&ptr1[0].val);
  cout << "\n";
  cout << "value of ptr1[1]: ";
  safe_write_double(&ptr1[1].val);
  cout << "\n";
  cout << "value of ptr1[2]: ";
  safe_write_double(&ptr1[2].val);
  cout << "\n";
  cout << "value of ptr1[3] (writing past malloc'd space): ";
  safe_write_double(&ptr1[3].val);
  cout << "\n";
  cout << "value of ptr1[4] (writing past malloc'd space): ";
  safe_write_double(&ptr1[4].val);
  cout << "\n";
  cout << "value of ptr1[5] (writing past malloc'd space): ";
  safe_write_double(&ptr1[5].val);
  cout << "\n";
  
  return 0;
}
