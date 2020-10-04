#include<iostream>
using namespace std;

template<class T,int sz>
class A{
public:
    T ar[sz];   /// size is the non-type parameter
};

int main()
{
    A<int,5>ob;
    for(int i=0;i<5;i++)
        ob.ar[i] = i+10;
    for(int i=0;i<5;i++)
        cout<<ob.ar[i]<<endl;

    return 0;
}
