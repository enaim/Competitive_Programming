#include<iostream>
using namespace std;

class Base{
public:
    void Print()
    {
        cout<<"I am base class\n";
    }

};

class Derived{
public:
    void Print()
    {
        cout<<"I am derived class\n";
    }
};

class Class:public Base,public Derived{

};

int main()
{
    Class ob;
//    ob.Print();     ///got error cause multiple valid function in same name
    ob.Base::Print();
    ob.Derived::Print();
    return 0;
}
