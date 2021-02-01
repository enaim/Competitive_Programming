#include<iostream>
using namespace std;

class Class{
private:
    int v;
public:
    int k;

//    Class(int val=0,int k = 0){v = val,this->k=k;}
    Class(int val=0){v = val;}
    friend Class operator - (Class a,Class b);
    friend Class operator + (Class a,int val);
    friend Class operator - (int val,Class a);

    friend Class operator + (Class a,Class b)
    {
        Class temp;

        temp = a.v + b.v;   /// here temp is a object so here the sum create an object then return that object
        /*temp.v = a.v + b.v;*/ /// this also works
        return temp;
    }
    void print()
    {
        cout<<v<<" "<<k<<endl;
    }
};

Class operator - (Class a,Class b)
{
    return Class(a.v - b.v);
}

Class operator + (Class a,int val)
{
    return Class(a.v + val);
}

Class operator - (int val,Class a)
{
    return Class(val-a.v);
}

/// for public member operation we don't need friend function
int operator * (Class a,Class b)
{
    return a.k*b.k;
}


int main()
{
    Class ob1(10),ob2(20),ob,ob3,ob4,ob5;

    ob1.k = 5;
    ob2.k = 4;

    ob = ob1 + ob2;
    ob3 = ob1 - ob2;
    ob4 = ob1 + 50;
    ob5 = 100 - ob2;


    ob1.print();
    ob2.print();
    ob.print();
    ob3.print();
    ob4.print();
    ob5.print();
    cout<<endl;

    Class(ob1+ob2+ob3+10).print();

    cout<<ob1*ob2<<endl;

    return 0;
}
