#include <iostream>

using namespace std;

class Circle {
    public:
        int Code;
        Circle(int code) : Code(code) {}
};

__attribute__((annotate("sensitive"))) Circle *s;

int main() {
    s = new Circle(42);
    cout << s->Code << endl;
    return 0;
}
