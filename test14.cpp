#include <iostream>
using namespace std;

struct Circle {
  long int x;
  long int y;
  double pi;
};

//struct ProtectedInt {
//  long int val;
//};
//
//struct ProtectedDouble {
//  double val;
//};

struct Circle *c;

__attribute__((annotate("secret"))) struct Circle s;

void foo(bool read) {
  if (read) {
    double d;
    cin >> d;
    c->pi = d;
  } else {
    double d;
    d = c->pi;
    cout << d << "\n";
  }
}
int main() {
  c = new Circle();
  foo(true);
  foo(false);
  return 0;
}
