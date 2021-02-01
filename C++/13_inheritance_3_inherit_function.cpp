#include<iostream>
using namespace std;

class Base{
public:
    void Print()
    {
        cout<<"I am base class\n";
    }
    void Print1()
    {
        cout<<"I am only in base class\n";
    }
};

class Derived:public Base{
public:
    void Print()
    {
        cout<<"I am derived class\n";
        Base::Print(); ///we use scope resolution otherwise this function call his own function and this will create infinite loop.
    }
};

int main()
{
    Derived ob;
    ob.Print();
    ob.Print1();

    Base temp;
    temp.Print();
    temp.Print1();

    return 0;
}
