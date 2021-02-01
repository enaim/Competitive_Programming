#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	virtual void print() const
	{
	    cout << "Base";

    }

	friend ostream& operator<<(ostream &out, const Base &b)
    {
        out << "Base";
        return out;
    }
};

class Derived : public Base
{
public:
	Derived() {}

	virtual void print() const override
	{
	    cout << "Derived";
    }

	friend ostream& operator<<(ostream &out, const Derived &d)
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    cout << b << '\n';

    Derived d;
    cout << d << '\n';

    cout<<"\nProblem :-\n";
    Base &bref = d;     ///this << operator is not virtual and it is impossible to << operator make virtual
    cout << bref << '\n';

    return 0;
}
