#include <iostream>
#include <stdlib.h>
#include "../../safe_functions.h"


using namespace std;

/*
This test a simple over write with local variables
Since it is global no issues at all
*/

typedef struct {
  double val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
Key *ptr;

int main() {
  int test = 7;
  ptr = (Key*)safe_malloc(sizeof(Key)*N);
  int over_write[N];

  //cout << "addr: " << &over_write << "\n";
  cout << "addr of over_write + 3: " << &over_write + 3 << "\n";
  cout << "addr of test: " << &test << "\n";

  
  int j;
  
  cout << "value of test before: " << test << "\n";	
  	
  for(int i = 0; i < N; ++i) {
    ptr[i].val = 1.0;
  }
  for(int i = 0; i < N+12; ++i) {
    over_write[i] = 5.0;	
  }
  cout << "value of test after(should be 7): " << test << "\n";	
  cout << "value of protected struct ptr (should be 1): ";
  safe_write_double(&ptr[0].val);
 // cout << "value of ptr[0]: " << ptr[0].val  << "\n";  
 // cout << "value of ptr[1]: " << ptr[1].val << "\n";
 // cout << "value of ptr[2]: " << ptr[2].val << "\n";
 // cout << "should never get here\n";

  return 0;
}
