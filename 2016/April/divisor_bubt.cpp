#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n,x,T,cnt=1;
    scanf("%lld",&T);

    while(cnt<=T)
    {
        scanf("%lld",&n);

        x = sqrt(n);
        if((x*x) == n)
            printf("Case %lld: Yes\n",cnt);
        else if(((x+1)*(x+1))==n)
            printf("Case %lld: Yes\n",cnt);
        else
            printf("Case %lld: No\n",cnt);
        cnt++;
    }

    return 0;
}

