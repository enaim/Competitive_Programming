#include<iostream>
using namespace std;


class Class1{
public:
    int a;
    double b;
    char c;
    void print()
    {
        cout<<"Class1"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class2{
    int a;
    double b;
    char c;
public:
    Class2()                ///this is constructor not initialization
    {
        a = 40;
        b = 54.05;
        c = 'c';
    }

    void print()
    {
        cout<<"Class2"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class3{
    int a;
    double b;
    char c;
public:
    Class3(int x,double y,char z)
    {
        a = x;
        b = y;
        c = z;
    }

    void print()
    {
        cout<<"Class3"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class4{
    int a;
    double b;
    char c;
public:
    Class4(int x=0,double y=4.00,char z='X')
    {
        a = x;
        b = y;
        c = z;
    }

    void print()
    {
        cout<<"Class4"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class5{
    int a;
    double b;
    char c;
public:
    Class5(int x=0,double y=4.00,char z='X'):a(x),b(y),c(z)
    {
        a = x;
        b = y;
        c = z;
    }

    void print()
    {
        cout<<"Class5"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class6{
    int a=123;              ///this is initialization
    double b=4.56;
    char c='H';
public:
    class6()
    {
    /// This constructor will use the default values above since they aren't overridden here
    }
    void print()
    {
        cout<<"Class6"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class7{
    int a;
    double b;
    char c;
public:
    Class7()
    {
        a = 82;
        b = 19.25;
        c = 'j';
    }
    Class7(int x)
    {
        a = x;
        b = 19.25;
        c = 'j';
    }
    Class7(char ch)
    {
        a = 82;
        b = 19.25;
        c = ch;
    }
    Class7(int x,double y)
    {
        a = x;
        b = y;
        c = 'j';
    }
    Class7(int x,double y,char z)
    {
        a = x;
        b = y;
        c = z;
    }

/// less than three parameter for this constructor cause of ambiguous
/*  Class7(int x,double y,char z='X')
    {
        a = x;
        b = y;
        c = z;
    }
*/
/// the first constructor and below constructor makes ambiguous cause this constructor has its default initializer
/*  Class7(int x=0,double y=4.00,char z='X')
    {
        a = x;
        b = y;
        c = z;
    }
*/
    void print()
    {
        cout<<"Class7"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

class Class8{
    int a;
    double b;
    char c;
public:
    void Set(int x,double y,char z);
    void print()
    {
        cout<<"Class6"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl<<endl;
    }
};

void Class8 :: Set(int x,double y,char z)
{
    a = x;
    b = y;
    c = z;
}

int main()
{
/// constructor calls when the object is declared. After that an object can't access in a constructor
/// if a constructor exist in class then an object must called a constructor when it declared

    Class1 ob1{1,2.4,'a'};  ///works with public member
    ob1.print();

    Class2 ob2;
    ob2.print();

    Class3 ob3{13,38.4,'B'},ob3_1(72,68.32,'G');    ///for initialization or constructor if number of parameter
    ob3.print();                                    ///doesn't match no one will work.
    ob3_1.print();

    Class4 ob4,ob4_1(12,3.6);   ///if number of parameter doesn't match though it will work
    ob4.print();
    ob4_1.print();

    Class5 ob5(15,48.6,'T');
    ob5.print();

    Class6 ob6;
    ob6.print();

    Class7 ob7,ob7_1(10),ob7_2('R'),ob7_3(39,47.30),ob7_4(5,5.2,'d');
    ob7.print();
    ob7_1.print();
    ob7_2.print();
    ob7_3.print();
    ob7_4.print();

    Class8 ob8;
    ob8.Set(97,64.256,'y');
    ob8.print();

    return 0;
}
