#include <time.h>
#include <stdio.h>

int main(int argc, char** argv) {
  time_t tt;
  tt = time(0);
  struct tm* lt =  localtime(&tt);
  printf("%d\n", lt->tm_sec);
  struct tm* gt = gmtime(&tt);
  printf("%d\n", gt->tm_sec);
  return 0;
}
