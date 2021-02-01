#include<iostream>
using namespace std;

class Class{
    int val;
public:
    Class(int val)
    {
        this -> val = val;
    }

    Class& operator++(); ///prefix
    Class& operator--(); ///prefix

    Class operator++(int);  ///postfix
    Class operator--(int);  ///postfix

    friend ostream& operator << (ostream& out,Class ob);
    /*friend ostream& operator << (ostream& out,Class &ob);*/     ///doesn't work.Anonymous object reference doesn't found.(I Think)
//    friend ostream& operator << (ostream& out,const Class ob);    ///also works
    /*friend ostream& operator << (ostream& out,const Class &ob);*/ ///It works.Probably it isn't possible to change constant
                                                                    ///reference(object) that's why it work.(I think)
};

Class& Class:: operator++()
{
    val++;  ///same to ++val
    return *this;
}

Class Class:: operator++(int)
{
    Class temp(val);
    ++(*this);
    return temp;
}

Class& Class:: operator--()
{
    --val;  ///same to val--
    return *this;
}
Class Class:: operator--(int)
{
    Class temp(val);
    --(*this);
    return temp;
}

ostream& operator << (ostream& out,Class ob)
{
    cout<<ob.val<<endl;
    return out;
}

int main()
{
    Class ob(5);
    cout<<ob<<endl;
    cout<<++ob<<endl;
    cout<<ob++<<endl;;
    cout<<ob<<endl;

    cout<<--ob<<endl;
    cout<<ob--<<endl;;
    cout<<ob<<endl;

    return 0;
}
