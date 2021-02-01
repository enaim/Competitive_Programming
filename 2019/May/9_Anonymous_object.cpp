#include<iostream>
using namespace std;


class Class1{
    int value;
public:
    Class1(int x) { value = x; }
    int get(){ return value; }
};

Class1 add(Class1 ob1,Class1 ob2)
{
    cout<<ob1.get()<<" + "<<ob2.get()<<" = ";
    return Class1(ob1.get()+ob2.get());
}

int main()
{
    cout<<Class1(25).get()<<endl;
    cout<<add(Class1(100),Class1(200)).get()<<endl;

    return 0;
}

