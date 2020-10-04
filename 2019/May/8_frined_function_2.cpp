#include<iostream>
using namespace std;

class Class2;

class Class1{
    int value;
public:
    Class1(){value = 1;}
    void sum(Class2 ob);
};

class Class2{
    int val;
public:
    Class2(){val = 2;}
    friend void Class1 :: sum(Class2 ob);
};

void Class1 :: sum(Class2 ob)
{
    cout<<value<<" + "<<ob.val<<" = "<<value+ob.val<<endl;
}


int main()
{
    Class1 ob1;
    Class2 ob2;
    ob1.sum(ob2);

    return 0;
}
