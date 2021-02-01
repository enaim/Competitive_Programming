#include<iostream>
using namespace std;

/// interface class all members are virtual

class A{
public:
    virtual void write(int x) = 0;
    virtual ~A() {}
};

class B : public A{
public:
    virtual void write(int x)
    {
        printf("B - > %d\n\n",x);
    }
};

class C : public A{
public:
    virtual void write(int x)
    {
        printf("C - > %d\n\n",x);
    }
};


int main()
{
    B ob1;
    A &ob = ob1;
    ob.write(100);

    C ob2;
    A &ob3 = ob2;
    ob3.write(300);

    return 0;
}
