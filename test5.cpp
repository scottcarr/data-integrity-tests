#include <iostream>

struct Key {
  int val;
} Key;

// !! THIS ISNT ACTUALLY A GOOD TEST
// EVERYTIME ITS INLINING FOO
// SO ITS NOT ACTUALLY PROTECTING THE VALUE

__attribute__((annotate("sensitive"))) struct Key mykey;
__attribute__((annotate("sensitive"))) int xyz;
//struct Key mykey;

void foo() {
  int j;
  j = mykey.val;
  std::cout << j << std::endl;
}

int main() {
  int i;
  std::cin >> i;
  mykey.val = i;
  foo();
  return 0;
}
