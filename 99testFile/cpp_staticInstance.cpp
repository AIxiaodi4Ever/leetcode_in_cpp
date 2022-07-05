#include <iostream>

using namespace std;

class A {
public:
    static A *getInstance() { return static_cast<A *>(pa); }

    static void *pa;
    inline static const int a = 5;

    int x;
};

void* A::pa = new A;
// 或者类内定义是加inline或者在外部不带inline的定义一下
//const int A::a;

void ppp(const int x) {
    cout << x << endl;
}

// 如果不在外部不带初始值的定义一下a，则出错
void pppp(const int& x) {
    cout << x << endl;
}

int main() {
    cout << sizeof(A) << endl;
    cout << A::a << endl;
    ppp(A::a);
    pppp(A::a);
    return 0;
}