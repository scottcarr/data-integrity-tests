#include <iostream>
#include <stdlib.h>

using namespace std;

/*
This test a simple over write with local variables
Since it is local also, the value of the pointer was
changed so it seg faults
*/

typedef struct {
  long int val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  int test = 7;
  Key *ptr = (Key*)malloc(sizeof(Key)*N);
  int over_write[N];

  cout << "addr: " << &over_write << "\n";
  cout << "addr: " << &over_write[3] << "\n";
  cout << "addr: " << &test << "\n";
  cout << "addr: " << &ptr << "\n";
  int j;
  
  cout << "value of test before: " << test << "\n";	
  	
  for(int i = 0; i < N+4; ++i) {
    over_write[i] = 5;	
  }
  for(int i = 0; i < N; ++i) {
    cin >> j;
    ptr[i].val = j;
    
  }
  cout << "value of test after: " << test << "\n";	

  cout << "value of ptr[0]: " << ptr[0].val  << "\n";  
  cout << "value of ptr[1]: " << ptr[1].val << "\n";
  cout << "value of ptr[2]: " << ptr[2].val << "\n";
 // cout << "should never get here\n";

  return 0;
}
