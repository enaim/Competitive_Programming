#include<bits/stdc++.h>
using namespace std;

template <class T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
    {
         m_value = value;
    }

    ~Storage()
    {
        cout<<"Normal Destructor\n";
    }

    void print()
    {
        cout << m_value << '\n';
    }
};

template <>
void Storage<double>::print()
{
    cout << scientific << m_value << '\n';
}

template <>
Storage<char*>::Storage(char* value)
{
    int length=0;
    while (value[length] != '\0')
        ++length;

    ++length;

    m_value = new char[length];
    for(int count=0; count < length; ++count)
        m_value[count] = value[count];
}

template <>
Storage<char*>::~Storage()
{
    cout<<"String Destructor\n";
    delete[] m_value;
}

int main()
{
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    char *str = new char[40];

    cout << "Enter your name: ";
    cin >> str;

    Storage<char*> storage(str);

    delete[] str;
    cout<<str<<endl;

    storage.print(); /// This will print garbage unless we use Storage<char*>::Storage(char* value)
    cout<<endl;
}
