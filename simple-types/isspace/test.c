#include <ctype.h>
#include <stdio.h>
static int lookahead;
int main(int argc, char** argv) {
  
  do
    lookahead = getchar();
  while (isspace(lookahead));
  
  return 0;
}
