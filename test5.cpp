#include <iostream>
#include "safe_functions.h"

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
  safe_putchar((char*) &(mykey.val));
  putchar('\n');
}

int main() {
  safe_getchar((char*) &(mykey.val));
  foo();
  return 0;
}
