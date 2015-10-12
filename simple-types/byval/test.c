#include <stdio.h>

//#define MAX_UNSIGNED unsigned long long
//#define COMPLEX_FLOAT float _Complex
//
//struct quantum_reg_node_struct
//{
//  COMPLEX_FLOAT amplitude; /* alpha_j */
//  MAX_UNSIGNED state;      /* j */
//};
//
//typedef struct quantum_reg_node_struct quantum_reg_node;
//
//struct quantum_reg_struct
//{
//  int width;    /* number of qubits in the qureg */
//  int size;     /* number of non-zero vectors */
//  int hashw;    /* width of the hash array */
//  quantum_reg_node *node;
//  int *hash;
//};

//typedef struct quantum_reg_struct quantum_reg;

struct bar {
  char data[100];
  int x,y,z;
};

char data[100];

struct bar Bar;

//struct bar new_bar() {
//  struct bar b;
//  b.data[42] = 'b';
//  return b;
//}

char baz3(struct bar* d) {
  for (int i = 1; i < 100; i++) {
    d->data[i] *= d->data[i-1];
  }
  return d->data[7];
}

char baz2(struct bar d) {
  for (int i = 1; i < 100; i++) {
    d.data[i] += d.data[i-1];
  }
  return baz3(&d);
}

char baz(struct bar* d) {
  for (int i = 1; i < 100; i++) {
    d->data[i] += d->data[i-1];
  }
  return d->data[7];
}

char foo(char *d) {
  for (int i = 1; i < 100; i++) {
    d[i] += d[i-1];
  }
  return d[7];
}


int main(int argc, char** argv) {
  //quantum_reg reg;
  struct bar X;
  printf("data: %p\n", data);
  printf("&Bar: %p\n", &Bar);
  //printf("&reg: %p\n", &reg);
  printf("&X: %p\n", &X);
  //X = new_bar();
  printf("&X: %p\n", &X);

  for (int i = 0; i < 100; i++) {
    data[i] = i;
    Bar.data[i] = i;
  }

  //return foo(data);
  //return baz2(&Bar);
  char c = baz2(Bar);
}
