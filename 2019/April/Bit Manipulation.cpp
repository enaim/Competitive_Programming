#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t,x,y,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        y=n^x;
        //cout<<y<<"  ";
        if(y<x||y>n)y=-1;
        cout<<y<<endl;
    }
    return 0;
}
