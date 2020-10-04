#include<vector>
#include<iostream>
#include<functional>
using namespace std;

class Base
{
protected:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }

    virtual const char* getName() const { return "Derived"; }
};

void printName(const Base base) /// note: base passed by value, not reference
{
    cout << "I am a " << base.getName() << '\n';
}

void writeName(const Base &base) /// note: base now passed by reference
{
    cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived derived(5);
    cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base &ref = derived;
    cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base *ptr = &derived;
    cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';
    cout<<endl;

    Base base = derived;
    cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

    printName(derived);
    writeName(derived);
    cout<<endl;

    vector<Base>vec1;
    vec1.push_back(Base(10));
    vec1.push_back(Derived(20));
    for(int i=0;i<2;i++)
        cout << "I am a " << vec1[i].getName() << " and with value " << vec1[i].getValue() << '\n';
    cout<<endl;

    /*vector<Base&>vec;*/ ///doesn't support

    vector<Base*>vec2;
    vec2.push_back(new Base(10));
    vec2.push_back(new Derived(20));
    for(int i=0;i<2;i++)
        cout << "I am a " << vec2[i]->getName() << " and with value " << vec2[i]->getValue() << '\n';
    cout<<endl;

    Base ob1(10);
    Derived ob2(20);
    vector<reference_wrapper<Base>>vec;

    ///doesn't work
    /*vec.push_back(Base(10));
    vec.push_back(Derived(20));*/

    vec.push_back(ob1);
    vec.push_back(ob2);
    for(int i=0;i<2;i++)
        cout << "I am a " << vec[i].get().getName() << " and with value " << vec[i].get().getValue() << '\n';
    cout<<endl; /// we use .get() to get our element from the wrapper

    return 0;
}
