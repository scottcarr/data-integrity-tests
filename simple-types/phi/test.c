#include <stdio.h>
#include <stdlib.h>

void foo() {
  fprintf(stderr, "i am error\n");
}

int main(int argc, char** argv) {
  int * arr1 = malloc(100);
  int * arr2 = malloc(200);
  int * arr3 = malloc(300);
  int * ptr;
  switch (argc) {
    case 1:
      ptr = arr1;
      break;
    case 2:
      ptr = arr2;
      break;
    case 3:
      ptr = arr3;
      break;
  }
  ptr[0] = 42;
  printf("arr1[0]: %d\n", arr1[0]);
  printf("arr2[0]: %d\n", arr2[0]);
  printf("arr3[0]: %d\n", arr3[0]);
  printf("ptr[0]: %d\n", ptr[0]);
  return 0;
}
