#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long ar[100010],n,k,x,ans,r;
    int tks,ks=1,i,j;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&k);
        x = n/k;
        r = n%k;
        for(i=1;i<=k;i++)
        {
            if(i<=r)
                ar[i] = x+1;
            else
                ar[i] = x;
        }

        ans = 0;
        int m=n;
        for(i=1;i<=k-1;i++)
        {
            ans = ans + (ar[i]*(n-ar[i]));
            n = n-ar[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
