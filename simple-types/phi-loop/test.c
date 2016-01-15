#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int * arr1 = malloc(100);
  int * arr2 = malloc(200);
  int * arr3 = malloc(300);
  int ** ptr;
  int ** arrs = malloc(sizeof(int*)*4);
  arr1[0] = 9999;
  arr2[0] = 9999;
  arr3[0] = 9999;
  arrs[0] = arr1;
  arrs[1] = arr2;
  arrs[2] = arr3;
  arrs[3] = 0;
  ptr = arrs;
  int sum = 0;
  while (ptr[0]) {
   sum = (*ptr)[0] + 42;
    ++ptr;
  }
  printf("arr1[0]: %d\n", arr1[0]);
  printf("arr2[0]: %d\n", arr2[0]);
  printf("arr3[0]: %d\n", arr3[0]);
  printf("ptr[0]: %d\n", ptr[0]);
  return 0;
}
