#include<iostream>
#include<cassert>
using namespace std;

class Fraction{
    int numerator,denominator;
public:
    Fraction(int numerator,int denominator):numerator(numerator),denominator(denominator)
    {
        cout<<"Constructor Called\n";
        assert(denominator != 0);
//        this -> numerator = numerator;
//        this -> denominator = denominator;
    }
    Fraction(const Fraction &f):numerator(f.numerator),denominator(f.denominator)
    {
        cout<<"Copy Constructor Called\n";
    }
    friend Fraction makeNegative(Fraction f);
    friend ostream& operator<<(ostream& out,const Fraction &f);
};

ostream& operator<<(ostream& out,const Fraction &f)
{
    out<<f.numerator<<" / "<<f.denominator<<endl;
}

Fraction makeNegative(Fraction f)   ///f called copy constructor
{
    f.numerator = -f.numerator;
    f.denominator = -f.denominator;
    return f;
}

int main()
{
    Fraction fivethirds(5,3);
    Fraction fcopy(fivethirds);
    cout<<fcopy<<endl;

    Fraction F(Fraction(10,20));    ///Create Anonymous object then direct initialize.Out of calling copy constructor.
                                    ///This is called Elision.
    cout<<F<<endl;

    Fraction temp1(15,25);
    cout<<makeNegative(temp1)<<endl;    ///makeNegative called copy constructor when it receives the return object.

    /*Fraction ob(1,0);*/ ///Assertion Failed

    return 0;
}

