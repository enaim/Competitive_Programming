#include<iostream>
#include<cassert>
using namespace std;

class Class{
    int a,b;
public:
    /*explicit Class(int x=0,int y=1)*/ ///got compiler error cause it prevent implicit conversion(constructor conversion).
    Class(int x=0,int y=1)
    {
        a = x;
        b = y;
    }
    friend ostream& operator<<(ostream& out,const Class &ob);
};

ostream& operator<<(ostream& out,const Class &ob)
{
    out<<ob.a<<" "<<ob.b<<endl;
    return out;
}

int main()
{
    /// direct initialization
    int x(10);
    Class ob(1,2);
    cout<<x<<endl;
    cout<<ob<<endl;

    ///uniform initialization

    int y{5};
    Class ob1{3,4};     /// if the member variables are public then this doesn't need constructor.otherwise it needs.
    cout<<y<<endl;
    cout<<ob1<<endl;

    ///copy initialization
    int z = 6;
    Class ob2(ob);
    cout<<z<<endl;
    cout<<ob2<<endl;

    Class temp = 6;
    cout<<temp<<endl;

    return 0;
}
