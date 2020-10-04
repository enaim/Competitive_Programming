#include<iostream>
using namespace std;

class A{
public:
    virtual const char* get() = 0;
};

const char* A::get()
{
    return "Elias";
}

class B: public A{
public:
    virtual const char* get()
    {
        return "Naim";
    }
};

class C: public A{
public:
    virtual const char* get()
    {
        return A :: get();
    }
};

int main()
{
    B ob1;
    C ob2;
    const char* str;
    str = ob1.get();
    cout<<str<<" "<<ob2.get()<<endl;
    cout<<ob1.get()<<" "<<ob2.get()<<endl;

    return 0;
}
