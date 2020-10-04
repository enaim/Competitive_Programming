#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    long long ans,n;

    while(1==scanf("%lld",&n) && n >= 0)
    {
        ans = ((n*(n+1))/2)+1;
        printf("%lld\n",ans);
    }

    return 0;
}
