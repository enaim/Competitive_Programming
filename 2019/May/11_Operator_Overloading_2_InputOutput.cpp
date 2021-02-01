#include<iostream>
using namespace std;

class Class{
private:
    int a,b;
public:
    Class(int x=0,int y=0)
    {
        this->a = x;
        this->b = y;
    }
    friend istream& operator>>(istream& in,Class &ob)
    {
        in>>ob.a;
        in>>ob.b;
        return in;
    }
    /*friend ostream& operator<<(ostream& out,Class ob);*/ /// this also works
    /*friend ostream& operator<<(ostream& out,const Class ob);*/ /// this also works
    friend ostream& operator<<(ostream& out,const Class &ob);   ///safe to use for all kinds of object.(Anonymous also)

};

//istream& operator>>(istream& in,Class &ob)
//{
//    in>>ob.a;
//    in>>ob.b;
//    return in;
//}

ostream& operator<<(ostream& out,const Class &ob)
{
    out<<ob.a<<" < - > "<<ob.b<<endl;
    return out;
}


int main()
{
    Class ob;
    cin>>ob;
    cout<<ob;

    return 0;
}
