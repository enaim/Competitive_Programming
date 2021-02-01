#include<iostream>
using namespace std;

class A{
public:
    int a;
    A(int x)
    {
        a = x;
        printf("Constructing A\n");
    }
};

class B: virtual public A{
public:
    int b;
    B(int x,int y):A(x)
    {
        b = y;
        printf("Constructing B\n");
    }
};

class C: virtual public A{
public:
    int c;
    C(int x,int z):A(x)
    {
        c = z;
        printf("Constructing C\n");
    }
};

class D: public B,public C{
public:
    D(int x,int y,int z):A(x),B(x,y),C(x,z) ///though we use virtual base class so we should construct class A from this class D
    {                                       ///class D constructor is responsible for creating class A
        printf("Constructing D\n");         ///this is one time when D is allowed to call a non-immediate-parent constructor directly
    }
};

class E: public C{
public:
    E(int x,int z):A(x),C(x,z)
    {
        printf("Constructing E\n");
    }
};

int main()
{
    D ob(1,2,3);
    cout<<endl;
    E ob1(10,20);

    return 0;
}

///output without using virtual base class:
/*
    Constructing A
    Constructing B
    Constructing A
    Constructing C
    Constructing D
*/
