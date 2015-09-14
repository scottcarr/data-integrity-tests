#include <stdlib.h>
struct vector3 {
  int x, y, z;
};

__attribute__((annotate("sensitive"))) struct vector3 x;

int main(int argc, char** argv) {
  struct vector3* ptr;
  ptr = malloc(sizeof(struct vector3)*10);
  return 0;
}
