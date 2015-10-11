#include <stdio.h>

int sum(int n, ...) {
  va_list ap;
  va_start(ap, n);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += va_arg(ap, int);
  }
  va_end(ap);
  return tot;
}

int main(int argc, char** argv) {
  return sum(1,2,3,4,5);
}
