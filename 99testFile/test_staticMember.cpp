#include <iostream>

using namespace std;

class A {
public:
    A() {}
    A(int _a) : a(_a) {}
    virtual void myPrint() { cout << a << endl; }
    int a;
};

class B : public A {
public:
    B() : A(), b(1) {}
    B(int _a, int _b) : A(_a), b(_b) {}
    void myPrint() override { cout << b << endl; }
    int b;
    // 如果是const则需要在外面不带初始化的定义一下，否则引用传递时会出错
    // constexpr则不会
    static const int SSS;
};

const int B::SSS = 2;

void myP(const int s) {
    cout << s << endl;
}

void myPre(const int& s) {
    cout << s << endl;
}

int main() {
    /*cout << "aa" << endl;
    A *a = new B(2, 3);
    B *b = dynamic_cast<B *>(a);
    b->myPrint();
    a->A::myPrint();*/

    int a = 2;
    void *b = &a;
    int *c = static_cast<int *>(b);
    cout << *c << endl;
    cout << B::SSS << endl;
    myP(B::SSS);
    myPre(B::SSS);
    return 0;
}
