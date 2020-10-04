#include<iostream>
#include<vector>
using namespace std;

class Class1{
    static int x;
public:
//    int get(){return ++x;}  //this also works
    static int get(){return ++x;}
};

int Class1 :: x = 5;

class Class2{
public:
    static vector<char>vec;
};

vector<char> Class2 :: vec{'n','a','i','m'};


/// when we need insert random values using loop or etc etc.
class Myclass{
private:
    static vector<int>v;
public:
    class init{
    public:
        init()
        {
            for(int i=1;i<=5;i++)
                v.push_back(i*10);
        }
    };
    void print()
    {
        for(auto it : v)
        cout<<it<<" ";
        cout<<endl<<endl;
    }
    static init initializer;                /// we'll use this static object to ensure the init constructor is called
};

//vector<int> Myclass :: v{1,2,3,4,5};  //it works

vector<int> Myclass :: v;                   /// define our static member variable

Myclass:: init Myclass :: initializer;      ///define our static initializer, which will call the init constructor,
                                            ///which will initialize v vector. Here Myclass:: init use init is a class(works here
                                            ///like other data types) which is under Myclass.(I think)
int main()
{
    Class1 ob1;
    for(int i=0;i<5;i++)
        cout<<ob1.get()<<endl;
    cout<<endl;

    Class2 ob2;
    for(auto it : ob2.vec)
        cout<<it<<" ";
    cout<<endl<<endl;

    Myclass ob;
    ob.print();

    return 0;
}
