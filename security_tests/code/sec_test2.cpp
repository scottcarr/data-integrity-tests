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

  /*cout << "addr: " << &ptr1 << "\n";
  cout << "addr: " << &ptr1[1] << "\n";
  cout << "addr: " << &ptr1[2] << "\n";
  cout << "addr: " << &ptr << "\n";
  cout << "addr: " << &ptr[1] << "\n";
  cout << "addr: " << &ptr[2] << "\n";
  cout << "addr: " << ptr[3].val << "\n";
  cout << "addr: " << ptr[4].val << "\n";
  cout << "addr: " << ptr[5].val << "\n";
*/
  int j;
  
  cout << "value of test before: " << test << "\n";	
  	
//  for(int i = 0; i < N+4; ++i) {
//    over_write[i] = 5;	
//  }
  for(int i = 0; i < N; ++i) {
    cin >> j;
    ptr[i].val = 1.0;
    ptr1[i].val = 4.0; 
  }
  ptr1[3].val = 4.0; 
  ptr1[4].val = 4.0; 
  ptr1[5].val = 4.0; 
  cout << "value of test after: " << test << "\n";	

  safe_write_double(&ptr[0].val);
  safe_write_double(&ptr[1].val);
  safe_write_double(&ptr[2].val);
  safe_write_double(&ptr1[0].val);
  safe_write_double(&ptr1[1].val);
  safe_write_double(&ptr1[2].val);
  safe_write_double(&ptr1[3].val);
  safe_write_double(&ptr1[4].val);
  safe_write_double(&ptr1[5].val);
  
 /* cout << "value of ptr[0]: " << ptr[0].val  << "\n";  
  cout << "value of ptr[1]: " << ptr[1].val << "\n";
  cout << "value of ptr[2]: " << ptr[2].val << "\n";
  cout << "value of ptr1[0]: " << ptr1[0].val  << "\n";  
  cout << "value of ptr1[1]: " << ptr1[1].val << "\n";
  cout << "value of ptr1[2]: " << ptr1[2].val << "\n";
  cout << "value of ptr1[2]: " << ptr1[3].val << "\n";
  cout << "value of ptr1[2]: " << ptr1[4].val << "\n";
  cout << "value of ptr1[2]: " << ptr1[5].val << "\n";
*/
  
 // cout << "should never get here\n";

  return 0;
}
