#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    long long i,n,ans,x,m,cnt;
    while(scanf("%lld",&n)==1 && n)
    {
        if(n<0LL)
            n = n*(-1);
        ans = -1;
        cnt = 0;
        m = n;
        for(i=2;i<=sqrt(m) && n>1;i++)
        {
            x = n;
            while(n%i==0LL)
                n/=i;

            if(x!=n)
            {
                cnt++;
                if(cnt>=2)
                    ans = i;
            }
        }
        if(n!=1LL && cnt>=1 && n>ans)
            ans = n;
        printf("%lld\n",ans);
    }

    return 0;
}
