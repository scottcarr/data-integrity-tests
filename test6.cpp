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
__attribute__((annotate("sensitive"))) SecretDouble d;
__attribute__((annotate("sensitive"))) SecretInt i;

void foo() {
  std::cout << mykey.b.val << std::endl;
}

int main() {
  double i;
  std::cin >> i;
  mykey.b.val = i;
  foo();
  return 0;
}
