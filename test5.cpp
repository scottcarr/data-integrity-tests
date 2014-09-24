#include <iostream>

struct Key {
  int val;
} Key;


__attribute__((annotate("sensitive"))) struct Key mykey;
//struct Key mykey;

int main() {
  int i;;
  std::cin >> i;
  mykey.val = i;
  std::cout << mykey.val;
  return 0;
}
