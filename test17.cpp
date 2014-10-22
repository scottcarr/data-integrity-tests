#include <iostream>
using namespace std;
// test structs with smaller than 8 byte fields

struct Circle {
  char x;
  char y;
  char z;
};

__attribute__((annotate("sensitive"))) struct Circle* c;
//__attribute__((annotate("sensitive"))) char* c;

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
  //c = new char[3];
  //cin >> i;
  //c[0] = i;
  //cin >> i;
  //c[1] = i;
  //cin >> i;
  //c[2] = i;

  return 0;

}
