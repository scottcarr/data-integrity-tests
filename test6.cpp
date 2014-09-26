#include <iostream>

typedef struct {
  int val;
} SecretInt;

typedef struct {
  double val;
} SecretDouble;

typedef struct {
  SecretInt a;
  SecretDouble b;
} SecretThing;


//__attribute__((annotate("sensitive"))) SecretInt mykey;
__attribute__((annotate("sensitive"))) SecretThing mykey;

void foo() {
  std::cout << mykey.b.val;
}

int main() {
  double i;
  std::cin >> i;
  mykey.b.val = i;
  foo();
  return 0;
}
