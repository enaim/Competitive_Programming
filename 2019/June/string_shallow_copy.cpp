#include<bits/stdc++.h>
using namespace std;

char *b;

void func(char* x)
{
    b = x;
}

int main()
{
    char* a = new char[100];
    cin>>a;
    func(a);
    delete[] a;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
