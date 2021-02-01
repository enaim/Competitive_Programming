#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    long long ans,n,x1,x2,y1,y2,a,b,i;

    while(1==scanf("%lld",&n))
    {
        ans = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            a = (x2-x1)+1;
            b = (y2-y1)+1;
            ans+=(a*b);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
