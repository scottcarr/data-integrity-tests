#include <stdlib.h>

void my_free(void (*freefn)(void*), int* ptr) {
  printf("%p\n", ptr);
  //int tot = 0;
  //for (int i = 0; i < 10; i++) {
  //  tot += ptr[i];
  //}
  freefn(ptr);
}

int main(int argc, char** argv) {
  int* arr = malloc(sizeof(int)*10);
  my_free(free, arr);
  return 0;
}

