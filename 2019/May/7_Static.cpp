#include<iostream>
using namespace std;


int func()
{
    static int val = 1;
    return val++;
}

class Class{
public:
    static const int val = 100;
};


class Class1{
public:
    static int v;
};

int Class1 :: v = 1;    /// static value initializer.its a definition


class Class2{
public:
    static int a;
    int b;
    Class2()
    {
        b = ++a;
    }
};

int Class2 :: a = 10;

int main()
{
    for(int i=0;i<3;i++)
        cout<<func()<<endl;
    cout<<endl;

    Class ob;
    cout<<ob.val<<endl<<endl;

    Class1 ob1,ob1_1;
    cout<<ob1.v<<" "<<ob1_1.v<<endl;
    ob1.v = 2;
    cout<<ob1.v<<" "<<ob1_1.v<<endl;
    cout<<Class1 :: v<<endl<<endl;    /// call without object

    Class2 ob2,ob2_1;
    cout<<ob2.b<<" "<<ob2_1.b<<endl;

    return 0;
}
