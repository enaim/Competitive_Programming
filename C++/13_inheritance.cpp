#include<iostream>
using namespace std;

class Person{
public:
    string name;
    Person()
    {
        cout<<"Person\n";
    }
};

class Player : public Person{
public:
    int salary;
    Player()
    {
        cout<<"Player\n";
    }
};

int main()
{
    Player ob;
    cout<<endl;
    ob.name = "Naim Elias";
    ob.salary = 1000;
    cout<<ob.name<<" - > "<<ob.salary<<endl;

    return 0;
}
