#include <iostream>

typedef struct {
  int val;
} Key;


__attribute__((annotate("sensitive"))) Key mykey;
Key *keyPtr;

void foo() {
  std::cout << keyPtr->val << std::endl;
}

int main() {
  int i;
  std::cin >> i;
  mykey.val = i;
  keyPtr = &mykey;
  foo();
  return 0;
}
