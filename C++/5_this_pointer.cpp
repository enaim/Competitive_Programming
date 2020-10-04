#include<iostream>
using namespace std;


class Class
{
    int v;
public:
    Class(int v)
    {
        this -> v = v;
    }
    void print()
    {
        cout<<v<<endl<<endl;
    }
};

class Calc
{
public:
    int m_value;
    Calc() { m_value = 0; }

    Calc& add(int value) { m_value += value; return *this;}
    Calc& sub(int value) { m_value -= value; return *this;}
    Calc& mult(int value) { m_value *= value; return *this;}
};


int main()
{
    Class o(1000);
    o.print();

    Calc ob;
    ob.add(5).sub(3).mult(7);
    cout<<ob.m_value<<endl;

    return 0;
}
