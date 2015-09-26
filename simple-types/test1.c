#include <stdlib.h>
#include <stdio.h>

struct object {
  struct vector3 *position, *velocity;
  int* mass;
};

struct vector3 {
  int x, y, z;
};

__attribute__((annotate("sensitive"))) struct vector3 x;

void foo(struct vector3* x) {
  printf("can it inline printf?\n");
  x->z = x->x;
}

void bar(struct vector3** x, struct vector3 **y) {
  *x = *y;
}

int main(int argc, char** argv) {
  struct vector3* safe_ptr;
  int* unsafe_ptr;
  safe_ptr = malloc(sizeof(struct vector3)*10);
  unsafe_ptr = malloc(30);
  printf("&unsafe_ptr: \t%p\n", &unsafe_ptr);
  printf("&safe_ptr: \t%p\n", &safe_ptr);
  printf("unsafe_ptr: \t%p\n", unsafe_ptr);
  printf("safe_ptr: \t%p\n", safe_ptr);
  //safe_ptr = unsafe_ptr;
  struct object obj;
  obj.position = safe_ptr;
  obj.velocity = safe_ptr + 1;
  //obj.mass = safe_ptr + 2;
  foo(safe_ptr);
  //foo(obj.mass);
  return 0;
}
