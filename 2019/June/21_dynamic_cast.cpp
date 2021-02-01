#include<iostream>
#include<string>
using namespace std;

class Base{
public:
    virtual ~Base() ///this destructor is must important in this example
    {
        printf("\nDestructing\n");
    }
};

class Derived : public Base{
public:
    string name;
    Derived(string name)
    {
        this->name = name;
    }
    const string& get()
    {
        return name;
    }
};

Base* func(bool flag)
{
    if(flag)
        return new Derived("Naim Elias");
    else
        return new Base();
}

int main()
{
    ///Pointer
    Base *b = func(true);
    Derived *d = dynamic_cast<Derived*>(b);
    cout<<d -> get()<<endl;

    /// doesn't support.Cause of runtime crash.
/*
    b = func(false);
    d = dynamic_cast<Derived*>(b);
    cout<<d -> get()<<endl;
*/

    d = static_cast<Derived*>(b);
    cout<<d -> get()<<endl;


    ///Reference
    Derived D = *d;
    Base &B = D;
    Derived &rf = dynamic_cast<Derived&>(B);
    cout<<rf.get()<<endl;

    cout<<endl;
    rf = *d;
    cout<<rf.get()<<endl;

    Base &B1 = *b;
    Derived &rf1 = static_cast<Derived&>(B1);
    cout<<rf1.get()<<endl;

    return 0;
}
