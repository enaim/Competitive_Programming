#include<stdio.h>


int main()
{
//    freopen("in.txt","r",stdin);

    long long tks,a1,a2,b1,b2,ks = 1,i,sum1,sum2;
    scanf("%lld",&tks);
    while(tks--)
    {
        sum1 = sum2 = 1;
        printf("Case %lld: ",ks++);
        scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);

        for(i=a2+1;i<=a1;i++)
            sum1*=i;

        for(i=b2+1;i<=b1;i++)
            sum2*=i;

        if(sum1>sum2)
            printf("Part A\n");
        else if(sum1 == sum2)
            printf("Equal\n");
        else
            printf("Part B\n");
    }
    return 0;
}
