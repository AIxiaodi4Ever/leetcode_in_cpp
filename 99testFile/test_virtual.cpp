#include <iostream>

using namespace std;

class A {
public:
    A(){}
    virtual ~A(){}
    virtual void foo() { cout << "A::foo()" << endl; }
    virtual void bar() { cout << "A::bar()" << endl; }
    virtual void sss() {}
};

class B : public A {
public:
    B(){}
    ~B(){}
    void foo() { cout << "B::foo()" << endl; }
    void bar() { cout << "B::bar()" << endl; }
};

int main() {
    A *pb = new B;
    A *pa = new A;
    pa->foo();
    pb->foo();
    long *tmp = reinterpret_cast<long *>(pa);
    long *tmp2 = reinterpret_cast<long *>(pb);
    long *vptra = reinterpret_cast<long *>(*tmp);
    long *vptrb = reinterpret_cast<long *>(*tmp2);
    for (int i = 0; i < 4; ++i) {
        printf("A:[%d] : %p\n", i, vptra[i]);
        printf("B:[%d] : %p\n", i, vptrb[i]); 
    }
    return 0;
}