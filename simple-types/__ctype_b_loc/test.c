#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#define __CTYPE_B_LOC_SIZE (384)
//
//const unsigned short ** __dc_ctype_b_loc(void) {
//  static const unsigned short **obj = 0;
//  if (!obj) {
//    obj = malloc(sizeof(unsigned short*));
//    unsigned short* arr = malloc(sizeof(unsigned short)*__CTYPE_B_LOC_SIZE);
//    const unsigned short ** loc = __ctype_b_loc();
//    //memcpy(arr, (*loc)-128, __CTYPE_B_LOC_SIZE);
//    memcpy(arr, &(*loc)[-128], sizeof(unsigned short)* __CTYPE_B_LOC_SIZE);
//    *obj = arr+128;
//    printf("obj: %p\n", obj);
//    printf("arr: %p\n", arr);
//    printf("*obj: %p\n", *obj);
//  }
//  return obj;
//}
//
//
//int main(int argc, char** argv) {
//  const unsigned short ** ptr = __ctype_b_loc();
//  const unsigned short ** ptr2 = __dc_ctype_b_loc();
//  printf("libc: %p\n", ptr);
//  printf("mine: %p\n", ptr2);
//  for (int i = -128; i < 256; i++) {
//    unsigned short mine, theirs;
//    mine = (*ptr2)[i];
//    theirs = (*ptr)[i];
//    //printf("%hu\n", (*ptr)[i]);
//    if (mine != theirs) {
//      printf("mismatch!: %i: %hu != %hu\n", i, theirs, mine);
//    } else {
//      printf("match: %i: %hu != %hu\n", i, theirs, mine);
//    }
//  }
//  //printf("%p\n", &ptr[-128]);
//  //printf("%p\n", ptr-128);
//  //for (int i = -128; i < 256; i++) {
//  //  printf("%i: %i\n", i, ptr[i]);
//  //}
//  return 0;
//}
//
int main(int argc, char** argv) {
  if (argc >= 2) {
    int i = 0;
    printf("%s\n", argv[1]);
    while (!isspace(argv[1][i]) && argv[1][i]) {
      printf("%c", argv[1][i]);
      i++;
    }
    printf("\n");
  }
}
