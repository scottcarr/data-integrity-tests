#include <iostream>
using namespace std;
// test structs with smaller than 8 byte fields

struct Circle {
  char x;
  char y;
  char z;
};

__attribute__((annotate("sensitive"))) struct Circle* c;

void foo() {
  cout << c->x << endl;
  cout << c->y << endl;
  cout << c->z << endl;
}

int main() {
  c = new Circle();
  char i;
  cin >> i;
  c->x = i;
  cin >> i;
  c->y = i;
  cin >> i;
  c->z = i;
  foo();
  return 0;

}
