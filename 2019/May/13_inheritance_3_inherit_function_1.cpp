#include<iostream>
using namespace std;

class Base{
protected:
    void Print()
    {
        cout<<"I am only in base class\n";
    }
public:
    int val = 10;
    int getValue()
    {
        return val;
    }
};

class Derived:public Base{
public:
    using Base :: Print;    ///make this function public for derived class

    int getValue() = delete;  /// mark this function as inaccessible

private:
    using Base :: val;      ///make this variable private for derived class

/// this works
/*public:
//    Derived()
//    {
//        cout<<val<<endl;
//    }
*/
};

int main()
{
    Derived ob;
    ob.Print();

    /*ob.val = 10;*/            /// int Base::val is inaccessible because  it is private in derived class
    /*cout<<ob.getValue()<<endl;*/  /// this function is deleted in derived class thats why it shows compiler error

    Base temp;
    cout<<temp.getValue()<<endl;

    return 0;
}
