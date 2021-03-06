#include <iostream>
#include "safe_functions.h"

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
__attribute__((annotate("sensitive"))) SecretInt *abcd;
__attribute__((annotate("sensitive"))) int xyz;

//SecretInt keys[3];

void foo() {
  for (int i = 0; i < 3; i++) {
    //int k;
    //k = keys[i].val;
    //std::cout << k << std::endl;
    safe_putchar((char*) &(keys[i].val));
    std::cout << std::endl;

  }
}

int main() {
  for (int i = 0; i < 3; i++) {
    safe_getchar((char*) &(keys[i].val));
  }
  foo();
  return 0;
}
