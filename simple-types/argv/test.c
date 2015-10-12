#include <stdio.h>

void parse(char** argv) {
  char* ptr;
  for (int i = 0; ; ++i) {
    ptr = argv[i];
    if (!ptr) { break; }
    printf("%s\n", ptr);
  }
}

int main(int argc, char** argv) {
  parse(argv);
  return 0;
}
