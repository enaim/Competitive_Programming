#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t,x,y,p1,p2,no=0;
    cin>>t;
    while(t--)
    {
        p1=p2=0;
        for(int i=1;i<=3;i++)
        {
            cin>>x>>y;
            p1+=x;p2+=y;
        }
        cout<<"Case "<<++no<<": ";
        puts((p1>p2)?"SI":"HM");
    }
    return 0;
}
