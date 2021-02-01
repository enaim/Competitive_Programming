#include<iostream>
using namespace std;

class Something
{
public:
	// Default constructor
	Something(int n = 0, double d = 1.2) /// allows us to construct a Something(int, double), Something(int), or Something()
	{
	    cout<<"Print 1\n";
	}

	Something(double d)
	{
	    cout<<"Print 2\n\n";
	}
};

class Class{
public:
    Class()
    {
        cout<<"Print 3\n";
    }
    Class(int v):Class()
    {
        cout<<"Print 4\n";
    }
};

int main()
{
	Something s1 { 1, 2.4 }; /// calls Something(int, double)
	Something s2 { 1 };     /// calls Something(int, double)
	Something s3;           /// calls Something(int, double)

	Something s4 { 2.4 };   /// calls Something(double)

    Class ob(10);

	return 0;
}
