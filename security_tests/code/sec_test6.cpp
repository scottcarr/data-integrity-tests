#include <iostream>
#include <stdlib.h>
#include "../../safe_functions.h"


using namespace std;

/*
overwrite boundary info in protected memory
*/

typedef struct {
  double val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  Key *addr1 = (Key*)safe_malloc(sizeof(Key));
  addr1->val = 5.0;
  addr1 = (Key*)addr1 + sizeof(long int);
  addr1->val = 18.0;	

  addr1 =  (Key*)addr1 - sizeof(long int);
  cout << "value of addr1 original: ";
  safe_write_double(&addr1->val);
  cout << "\n";

  addr1 =  (Key*)addr1 + sizeof(long int);
  cout << "value of addr1 + long int: ";
  safe_write_double(&addr1->val);
  cout << "\n";

  return 0;
}
