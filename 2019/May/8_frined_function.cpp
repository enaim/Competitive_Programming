#include<iostream>
using namespace std;


class Class2;

class Class1{
    int value;
public:
    Class1(){value = 1;}
    friend void show(Class1 ob);
    friend void print(Class1 ob1,Class2 ob2);
};

void show(Class1 ob)
{
    cout<<ob.value<<endl<<endl;
}

class Class2{
    int val;
public:
    Class2(){val = 2;}
    friend void print(Class1 ob1,Class2 ob2);
};

void print(Class1 ob1,Class2 ob2)
{
    cout<<ob1.value+ob2.val<<endl;
}
int main()
{
    Class1 ob1;
    show(ob1);

    Class2 ob2;
    print(ob1,ob2);


    return 0;
}
