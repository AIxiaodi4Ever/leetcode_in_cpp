#include <iostream>

using namespace std;

class B {
public:
    const int a = 1;
    static const int b = 2;
    inline static const int c = 3;
    static int d;
    inline static int e = 5;
};

int B::d = 4;
const int B::b;

void pt(const int &a) {
    cout << "pt : " << a << endl;
}

int main() {
    B b;
    cout << b.a << endl;
    cout << b.b << endl;
    cout << b.c << endl;
    cout << b.d << endl;
    cout << b.e << endl;
    pt(b.e);
    return 0;
}