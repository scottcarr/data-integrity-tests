#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
  long int val;
} Key;


__attribute__((annotate("sensitive"))) Key mykey;
Key *ptr;

void foo() {
  int j = ptr->val;
  cout << j << endl;
}

int main() {
  ptr = new Key();
  int j;
  cin >> j;
  ptr->val = j;
  foo();
  return 0;
}
