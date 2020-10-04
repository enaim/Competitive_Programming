#include<iostream>
using namespace std;

class Base{
public:
    char get()
    {
        return 'B';
    }
};

class Derived : public Base{
public:
    char get()
    {
        return 'D';
    }
};

int main()
{
    Derived ob;
    cout<<ob.get()<<endl<<endl;

    Base &rbase = ob;
    Base *pbase = &ob;

    cout<<rbase.get()<<endl;    ///Both call Base class get function cause these are Base reference and Base pointer.
    cout<<pbase->get()<<endl;

    return 0;
}
