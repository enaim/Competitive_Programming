#include<iostream>
using namespace std;


class Class1{
    int value;
public:
    Class1(){value = 1;}
    friend class Class2;
};

class Class2{
    int val;
public:
    Class2(){val = 2;}
    void show(Class1 ob)
    {
        cout<<ob.value<<" + "<<val<<" = "<<ob.value+val<<endl;
    }
};


int main()
{
    Class1 ob1;
    Class2 ob2;
    ob2.show(ob1);

    return 0;
}
