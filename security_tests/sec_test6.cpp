#include <iostream>
#include <stdlib.h>

using namespace std;

/*
overwrite boundary info in protected memory
*/

typedef struct {
  long int val;
} Key;

const int N = 3;

__attribute__((annotate("sensitive"))) Key mykey;
//Key *ptr;

int main() {
  Key addr;
  Key *addr1 = (Key*)malloc(sizeof(Key));
  addr.val = 5;
  addr1 = (Key*)&addr + sizeof(long int);
  addr1->val = 18;	



  return 0;
}
