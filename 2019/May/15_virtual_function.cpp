#include <iostream>
using namespace std;

class A
{
public:
    virtual const char* getName() { return "A"; }
};

class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};

class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};

class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};

int main()
{
    C c;
    A &rBase = c;   ///though rBase is an A reference but we use virtual function
                    ///so the compiler will call the most-derived match between A and C.
    cout << "rBase is a " << rBase.getName() << '\n';
    cout << "rBase is a " << rBase.A :: getName() << '\n';

    return 0;
}
