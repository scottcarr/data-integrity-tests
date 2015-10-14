#include <string.h>

int main(int argc, char** argv) {
  char *dup = 0;
  if (argc == 2) {
    dup = strdup(argv[1]);
  }
  return 0;
}
