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
//__attribute__((annotate("sensitive"))) SecretThing mykey;

__attribute__((annotate("sensitive"))) SecretInt keys[3];
__attribute__((annotate("sensitive"))) SecretInt abc;
__attribute__((annotate("sensitive"))) int xyz;

//SecretInt keys[3];

void foo() {
  for (int i = 0; i < 3; i++) {
    int k;
    k = keys[i].val;
    std::cout << k << std::endl;
  }
}

int main() {
  for (int i = 0; i < 3; i++) {
    int k;
    std::cin >> k;
    keys[i].val = k;
  }
  foo();
  return 0;
}
