struct Key {
    int val;
} Key;


__attribute__((annotate("sensitive"))) struct Key mykey;
//struct Key mykey;

int main() {
    mykey.val = 5;
    return 0;
}
