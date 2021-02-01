#include<bits/stdc++.h>
using namespace std;


int main()
{
    int mx=-1,mn=2000000000,a,ar[100010],i,x,n;
    map<int,int>mp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x<mn)
            mn = x;
        if(mx<x)
            mx = x;
        mp[x]++;
    }
    int ans;
    if(mx==mn)
        ans = n-mp[mn];
    else
        ans = n-mp[mn]-mp[mx];;

    printf("%d\n",ans);

    return 0;
}
