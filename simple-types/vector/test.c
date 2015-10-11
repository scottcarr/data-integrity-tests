void* __dc_mask2(void* ptr) {
  return ptr;
}

int main(int argc, char** argv) {
  char arr[32];
  printf("arr: %p\n", arr);
  for (int i = 0; i < 32; ++i) {
    //printf("%i\n", i);
    arr[i] = 0;
  }
  for (int i = 1; i < 32; ++i) {
    //printf("%i\n", i);
    arr[i] = arr[i-1] + 1;
  }
  
  return arr[11];
}
