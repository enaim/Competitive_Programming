#include<vector>
#include<iostream>
#include<functional>
using namespace std;

class P
{
public:
    void print()
    {
        printf("Naim Elias\n");
    }
};

class Base
{
public:
    int m_value;
    Base(int value): m_value(value)
    {

    }
};

class Derived: public Base
{
public:
    int val;
    Derived(int value): Base(value)
    {
        val = value*value;
    }
};


int main()
{
    Derived d1(5);
    Derived d2(6);

    cout<<"d1.m_value -> "<<d1.m_value<<endl;
    cout<<"d1.val -> "<<d1.val<<endl;
    cout<<endl;
    cout<<"d2.m_value -> "<<d2.m_value<<endl;
    cout<<"d2.val -> "<<d2.val<<endl;
    cout<<endl;

    Base &b = d1;
    b = d2; // this line is problematic
    cout<<"After Base &b = d1 and b = d2\n\n";

    cout<<"d1.m_value -> "<<d1.m_value<<endl;
    cout<<"d1.val -> "<<d1.val<<endl;
    cout<<endl;
    cout<<"d2.m_value -> "<<d2.m_value<<endl;
    cout<<"d2.val -> "<<d2.val<<endl;
    cout<<endl;
    cout<<"b.m_value -> "<<b.m_value<<endl;
    /*cout<<"b.val -> "<<b.val<<endl;*/ ///doesn't compile because Base class has no member function named val.
    ///In this case d1 now has the Base portion of d2 and the Derived portion of d1

    Base base(10);
    Derived derived(20);
    base = derived;        ///only the base portion of derived class will be copied
    cout<<endl<<endl<<"base.m_value - > "<<base.m_value<<endl<<endl;

    /*derived = base;*/ ///doesn't support

    P p;
    P *x = &p;  ///variable to pointer
    x->print();
    P y = *x;   ///pointer to variable
    y.print();
    P *z = x;   ///pointer to pointer
    z->print();
    P &rf = *x; ///pointer to reference
    rf.print();

    return 0;
}

///Note:(My Assumption)
/*
    I think when base class object make a assignment with
    derived class object through assignment or pointer or reference
    all this time base class object deals with the base portion of derived class.
    It never deals with any section of derived class portion
*/
