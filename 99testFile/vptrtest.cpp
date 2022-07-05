#include <iostream>
#include <string>

using namespace std;

class Base 
{
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

typedef void(*Fun)(void);

int main()
{
	Base bObj;
	Fun pFun = NULL;	
    //指向void* pf(void)类的函数的指针pFun
    int *vptr = (int *)(&bObj);
    int *ffptr = (int *)(*vptr);

    cout << "pointer address：" << vptr << endl;
	cout << "first virtual fun address：" << ffptr << endl;
	//再次取址得到第一个虚函数的地址

	//第一个虚函数
	pFun = (Fun) * ((int*) * (int*)(&bObj));
	pFun();
}

