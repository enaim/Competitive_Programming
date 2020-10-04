#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    long long tks,ks=1,n,v;
    scanf("%lld",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        v=n*3;
        if(v%2==0)
            printf("Case #%lld: %lld %lld %lld\n",ks++,v,v-1,v-2);
        else
            printf("Case #%lld: %lld %lld %lld\n",ks++,v-2,v-1,v);

    }


    return 0;
}
