#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()" << std::endl;
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int length)
    {
        m_array = new int[length];
    }

    virtual ~Derived() // note: virtual
    {
        std::cout << "Calling ~Derived()" << std::endl;
        delete[] m_array;
    }
};

int main()
{
    Derived *derived = new Derived(5);
    Base *base = derived;
    delete base;    ///if we not used virtual then this function will called Base class Destructor.Run and check

    return 0;
}
