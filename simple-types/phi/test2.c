#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int * arr1 = malloc(100);
  int * arr2 = malloc(200);
  int * arr3 = malloc(300);
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      ptr = arr1;
    }
    if (i == 1) {
      ptr = arr2;
    }
    if (i == 2) {
      ptr = arr3;
    }
    ptr[0] = 42;
  }
  printf("arr1[0]: %d\n", arr1[0]);
  printf("arr2[0]: %d\n", arr2[0]);
  printf("arr3[0]: %d\n", arr3[0]);
  printf("ptr[0]: %d\n", ptr[0]);
  return 0;
}
