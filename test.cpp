#include <iostream>

using namespace std;

typedef int secret;

struct Circle 
{
    public:
    void (*f)(void);
};

void foo() {
    int x = 5;
    x += 6;
    if (x == 11) {
        cout << "hello world!" << endl;
    } else {
        cout << "goodbye!" << endl;
    }
}

__attribute__((annotate("sensitive"))) secret *z;

void baz() {
    secret x = 5 + *z;
    x += 6;
    if (x == 11) {
        cout << "hello world!" << endl;
    } else {
        cout << "goodbye!" << endl;
    }
}

void bar(Circle* c) {
    c->f(); // should be a check here?
}

int main() {
    Circle* c = new Circle();
    c->f = &foo;
    bar(c);
    return 0;
}
