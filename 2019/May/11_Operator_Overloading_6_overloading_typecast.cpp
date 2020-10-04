#include<iostream>
using namespace std;

class Class{
public:
    int val;
    Class(int x){ val = x; }
    operator int()
    {
        return val;
    }
};

class Class1{
    int v;
public:
    Class1(int x){ v = x; }
    operator Class()
    {
        return Class(v*5);
    }
};

void Print(int val)
{
    cout<<val<<endl;
}
void Print1(Class a)
{
    cout<<a.val<<endl;
}

int main()
{
    Class ob(10);
    Print(ob);
    int x = static_cast<int>(ob);
    cout<<x<<endl;
    cout<<endl;

    Class1 ob1(5);
    Print1(ob1);
    Class temp = static_cast<Class>(ob1);
    Print1(temp);

    return 0;
}
