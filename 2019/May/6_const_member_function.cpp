#include<string>
#include<iostream>
using namespace std;

class Class1{
    int x;
public:
    Class1()
    {
        x = 100;
    }
    void print() const
    {
        cout<<"const\n";
        cout<<x<<endl<<endl;;
    }
    void print()
    {
        cout<<x<<endl<<endl;
    }
};

class Class2{
    const int x;
public:
    Class2(int v):x(v)
    {

    }
/// both below constructors are not working
/*
    Class2
    {
        x = 50;
    }
    Class2(int v)
    {
        x = v;
    }
*/
    void print()
    {
        cout<<x<<endl<<endl;
    }
};

class Class3{
public:
    void Print()
    {
        cout<<"Class Three\n\n";
    }
};

class Something
{
public:
    string str;
    Something(const string &str="")
    {
        this -> str = str;
    }

    const string& getValue() const
    {
        return str;     /// getValue() for const objects
    }
    string& getValue()
    {
        return str;     /// getValue() for non-const objects
    }
    void print()
    {
        cout<<" - > "<<str<<endl<<endl;
    }
    void print()const
    {
        cout<<"const - > "<<str<<endl<<endl;
    }
    void print1()const
    {
        cout<<"Naim Elias"<<endl<<endl;
    }
};


int main()
{
    Class1 ob1;
    ob1.print();

    const Class1 ob1_1;
    ob1_1.print();

    Class2 ob2(15);
    ob2.print();

    Class3 ob3;
    ob3.Print();

/// constant object can't call non constant member fucntions
//    const Class3 ob3_1;
//    ob3_1.Print();

/// if two member function definition is same then only constant objects are called constant member functions

    Something something;
	something.getValue() = "Hi"; // calls non-const getValue();
	something.print();
	something.print1();

	const Something something2;
	something2.getValue(); // calls const getValue();
	something2.print();
	something2.print1();

    return 0;
}
