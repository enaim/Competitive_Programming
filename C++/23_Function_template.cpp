#include<iostream>
using namespace std;


template<typename T>
T maxi(T a,T b)
{
    return a>b ? a : b;
}

template<class T>
T& max(T &a,T &b)   ///conflict with build in max function
{
    cout<<"Test\n";
    return a>b ? a : b;
}

int main()
{
    cout<<maxi(5,6)<<endl;
    cout<<max(5,6)<<endl;

    cout<<maxi(5.110,0.6)<<endl;
    cout<<max(5.110,0.6)<<endl;

    return 0;
}
