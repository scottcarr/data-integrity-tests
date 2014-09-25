#include <iostream>

struct Key {
  int val;
} Key;


__attribute__((annotate("sensitive"))) struct Key mykey;
//struct Key mykey;

void foo() {
  std::cout << mykey.val;
}

int main() {
  int i;
  std::cin >> i;
  mykey.val = i;
  foo();
  return 0;
}
