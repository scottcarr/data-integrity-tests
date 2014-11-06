#include <string.h>
#include <iostream>
using namespace std;

struct Protected {
  char *buf;
};

Protected *x;

struct ProtectedVoid {
  void *nothing;
};

__attribute__((annotate("secret"))) Protected *pro;
__attribute__((annotate("secret"))) Protected prox;
__attribute__((annotate("secret"))) char achar;
__attribute__((annotate("secret"))) char *acharptr;
__attribute__((annotate("secret"))) ProtectedVoid *pvptr;
__attribute__((annotate("secret"))) ProtectedVoid pv;

void protect_print(ProtectedVoid *c) {
  for(char *p = (char*) c; *p != '\0'; ++p) {
    cout << *p;
  }
  cout << endl;
}

void protect_strcpy(ProtectedVoid *dst, ProtectedVoid *src) {
  char *srcC = (char*) src;
  char *dstC = (char*) dst;
  for(int i = 0; srcC[i] != '\0'; ++i) {
    dstC[i] = srcC[i];
  }
}

void foo(char *a, char *b) {
  // one or the other (or both or neither)
  // of a and b is in protected memory
  protect_strcpy((ProtectedVoid*) a, (ProtectedVoid*) "sdfdsfdsa");
  protect_strcpy((ProtectedVoid*) b, (ProtectedVoid*) a);
}

// void foo_check(char *a, char *b, bitmap protected) {
//  does the same thing but makes a, b protected depending on the 
//  bit map?
// }

int main() {
  x = new Protected();
  char* b0, *b1, *b2;
  x->buf = new char[100];
  b0 = new char[100];
  
  b1 = x->buf;
  b2 = x->buf;
  //int r; 
  //cin >> r;
  //if (r == 1) {
  //  b1 = b0;
  //  b2 = x->buf;
  //}
  //if (r == 2) { 
  //  b1 = x->buf;
  //  b2 = x->buf;
  //}
  //if (r == 3) { 
  //  b1 = b0;
  //  b2 = b0;
  //}
  //if (r > 3) { 
  //  b1 = x->buf;
  //  b2 = b0;
  //}
  foo(b1, b2); 
  protect_print((ProtectedVoid*) b1);
  protect_print((ProtectedVoid*) b2);
}

//int main_check() {
//  srand(time(NULL));
//  x = new Protected();
//  char* b0, *b1, *b2;
//  x->buf = new char[100];
//  b0 = new char[100];
//  
//  int r = rand();
//  if (r == 1) {
//    b1 = b0;
//    foo_bitmap.b1 = foo_bitmap.b0;
//    b2 = x->buf;
//    foo_bitmap.b2 = 1; // because we know x->buf is protected by its type
//  }
//  if (r == 2) { 
//    b1 = x->buf;
//    foo_bitmap.b1 = 1; 
//    b2 = x->buf;
//    foo_bitmap.b2 = 1; 
//  }
//  if (r == 3) { 
//    b1 = b0;
//    foo_bitmap.b1 = foo_bitmap.b0;
//    b2 = b0;
//    foo_bitmap.b2 = foo_bitmap.b0;
//  }
//  if (r > 3) { 
//    b1 = x->buf;
//    foo_bitmap.b1 = 1; 
//    b2 = b0;
//    foo_bitmap.b2 = foo_bitmap.b0;
//  }
//  if (foo_bitmap.b1 || foo_bitmap.b2) {
//    foo_check(b1, b2, foo_bitmap);
//  } else {
//    foo(b1, b2); 
//  }
//}

