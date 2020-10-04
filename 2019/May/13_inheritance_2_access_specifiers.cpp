#include<iostream>
using namespace std;

/// Reminder: This code is not compile because of we use many unacceptable move for better understanding

class Base
{
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};

class Pub: public Base /// note: public inheritance
{
    /// Public inheritance means:
    /// Public inherited members stay public (so m_public is treated as public)
    /// Private inherited members stay inaccessible (so m_private is inaccessible)
    /// Protected inherited members stay protected (so m_protected is treated as protected)
public:
    Pub()
    {
        m_public = 1; /// okay: m_public was inherited as public
        m_private = 2; /// not okay: m_private is inaccessible from derived class
        m_protected = 3; /// okay: m_protected was inherited as protected
    }
};

class Pri: private Base /// note: private inheritance
{
    /// Private inheritance means:
    /// Public inherited members become private (so m_public is treated as private)
    /// Private inherited members stay inaccessible (so m_private is inaccessible)
    /// Protected inherited members become private (so m_protected is treated as private)
public:
    Pri()
    {
        m_public = 1; /// okay: m_public is now private in Pri
        m_private = 2; /// not okay: derived classes can't access private members in the base class
        m_protected = 3; /// okay: m_protected is now private in Pri
    }
};

class Pro: protected Base /// note: protected inheritance
{
    /// Protected inheritance means:
    /// Public inherited members become protected (so m_public is treated as protected)
    /// Private inherited members stay inaccessible (so m_private is inaccessible)
    /// Protected inherited members become protected (so m_protected is treated as protected)
public:
    Pro()
    {
        m_public = 1; /// okay: m_public is now private in Pri
        m_private = 2; /// not okay: derived classes can't access private members in the base class
        m_protected = 3; /// okay: m_protected is now private in Pri
    }
};

int main()
{
    /// Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; /// okay: m_public is public in Base
    base.m_private = 2; /// not okay: m_private is private in Base
    base.m_protected = 3; /// not okay: m_protected is protected in Base

    Pub pub;
    pub.m_public = 1; /// okay: m_public is public in Pub
    pub.m_private = 2; /// not okay: m_private is inaccessible in Pub
    pub.m_protected = 3; /// not okay: m_protected is protected in Pub

    Pri pri;
    pri.m_public = 1; /// not okay: m_public is now private in Pri
    pri.m_private = 2; /// not okay: m_private is inaccessible in Pri
    pri.m_protected = 3; /// not okay: m_protected is now private in Pri

    Pro pro;
    pro.m_public = 1; /// not okay: m_public is now protected in Pro
    pro.m_private = 2; /// not okay: m_private is inaccessible in Pro
    pro.m_protected = 3; /// not okay: m_protected is now protected in Pro

    return 0;
}
