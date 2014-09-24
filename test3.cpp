#include <iostream>

using namespace std;

__attribute__((annotate("secret"))) int key;


int main() {
    key = 5;
    cout << key;

}
