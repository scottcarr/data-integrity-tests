#include <iostream>
#include "safe_functions.h"
using namespace std;

// test structs with smaller than 8 byte fields

struct Circle {
  char x;
  char y;
  char z;
};

__attribute__((annotate("sensitive"))) struct Circle* c;
__attribute__((annotate("sensitive"))) struct Circle zyx;
__attribute__((annotate("sensitive"))) char xzy;
//__attribute__((annotate("sensitive"))) char* c;

void foo() {
  //char a;
  //a = c->x;
  //cout << a << endl;
  //a = c->y;
  //cout << a << endl;
  //a = c->z;
  //cout << a << endl;
  safe_putchar((char*)&c->x);
  safe_putchar((char*)&c->y);
  safe_putchar((char*)&c->z);
}

int main() {
  c = new Circle();
  safe_getchar((char*)&c->x);
  safe_getchar((char*)&c->y);
  safe_getchar((char*)&c->z);
  //char i;
  //cin >> i;
  //c->x = i;
  //cin >> i;
  //c->y = i;
  //cin >> i;
  //c->z = i;
  foo();
  return 0;

}
