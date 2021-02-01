#include<iostream>
using namespace std;

template<class T>
class A{
public:
    T a;
    T b;
};

template<class t1,class t2>
class B{
public:
    t1 a;
    t2 b;
};

int main()
{
    A<int>ob;           ///this print 10 & 1
    /*A<double>ob;*/    ///this print 10 & 1.21
    ob.a = 10;
    ob.b = 1.21;
    cout<<ob.a<<endl;
    cout<<ob.b<<endl;

    cout<<endl;
    B<int,double>ob1;

    ob1.a = 10;
    ob1.b = 1.21;
    cout<<ob1.a<<endl;
    cout<<ob1.b<<endl;

    return 0;
}
