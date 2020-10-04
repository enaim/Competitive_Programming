#include<iostream>
using namespace std;

class Class{
private:
    int x,y;
public:
    Class(int x=0,int y=0)
    {
        this->x = x;
        this->y = y;
    }
    Class& operator+=(Class ob);
    void operator=(Class ob);
    Class operator*(Class ob);
    bool operator==(Class ob);
    bool operator>(Class ob);
//    friend bool operator>(Class ob1,Class ob2);//also works;
    Class operator-();
//    friend Class operator-(Class ob);//also works

    void print()
    {
        cout<<x<<" "<<y<<endl;
    }
};

Class& Class::operator+=(Class ob)
{
    x = x+ob.x;
    y = y+ob.y;
    return *this;
}

void Class:: operator=(Class ob)
{
    x = ob.x;
    y = ob.y;
}

Class Class::operator*(Class ob)
{
    return Class(x*ob.x,y*ob.y);
}

bool Class:: operator==(Class ob)
{
    return (x==ob.x && y==ob.y);
}

bool Class:: operator>(Class ob)
{
    return (x+y>ob.x+ob.y);
}

//bool operator>(Class ob1,Class ob2)
//{
//    return (ob1.x+ob1.y>ob2.x+ob2.y);
//}

Class Class::operator-()
{
    return Class(-x,-y);
}

//Class operator-(Class ob)
//{
//    return Class(-ob.x,-ob.y);
//}


int main()
{
    Class ob1(10,20),ob2(30,40),ob3;
    ob3 = ob1*ob2;
    ob1+=ob2;

    ob1.print();
    ob3.print();

    ob1 = -ob1;
    ob1.print();

    ob2 = ob1;

    if(ob1==ob2)
        printf("Equal\n");
    else
        printf("Not Equal\n");

    if(ob1>ob3)
        cout<<"First one is greater\n";
    else
        cout<<"First one is not greater\n";

    return 0;
}
