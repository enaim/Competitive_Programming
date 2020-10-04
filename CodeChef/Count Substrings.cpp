#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long tks,ks=1,cnt,i,len,x;
    long long sum;
    char s[100010];
    scanf("%lld",&tks);
    while(tks--)
    {
        cnt=0;
        scanf("%lld",&x);
        scanf("%s",s);
        for(i=0;i<x;i++)
            if(s[i] == '1')
                cnt++;
        sum = (cnt*(cnt+1))/2;
        printf("%lld\n",sum);
    }

    return 0;
}
