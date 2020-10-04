#include<iostream>
using namespace std;


class A{
    int a;
public:
    A(int a):a(a)
    {
        cout<<"A -> "<<a<<endl;
    }
};

class B: public A{
    double b;
public:
    B(int a,double b):A(a),b(b)
    {
        cout<<"B -> "<<b<<endl;
    }
};

class C : public B{
    char c;
public:
    C(int a,double b,char c):B(a,b),c(c)
    {
        cout<<"C -> "<<c<<endl;
    }
};


int main()
{
    C ob(1,2.5,'Z');

    return 0;
}
