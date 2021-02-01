#include<iostream>
using namespace std;

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}


int main()
{
    int x = 5,y = 10;

    /// Early Binding
    cout<<add(x,y)<<endl;

    /// Late Binding

    int (*fn)(int,int) = add;
    cout<<fn(x,y)<<endl;

    int (*pfn)(int,int) = nullptr;
    pfn=sub;
    cout<<pfn(y,x)<<endl;
    pfn=add;
    cout<<pfn(x,y)<<endl;

    return 0;
}
