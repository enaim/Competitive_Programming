#include<iostream>
using namespace std;

class A{
public:
    virtual void Print()
    {
        cout<<"Class A\n";
    }
};

class B : public A{
public:
    /*virtual void Print() override final ///this is last/final overridden of this function*/
    virtual void Print() override   ///for confirming that this function is overridden
    {
        cout<<"Class B\n";
    }
};

class C final : public B{
public:
    virtual void Print() override
    {
        cout<<"Class C\n";
    }
};


/*class D : public B{};*/ ///this class make compiler error cause already class C declared final

int main()
{
    B ob;
    ob.Print();

    C ob1;
    ob1.Print();
    ob1.A :: Print();

    return 0;
}
