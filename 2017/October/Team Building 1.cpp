#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long ar[4],sum1,sum,tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld%lld",&ar[0],&ar[1],&ar[2]);
        sort(&ar[0],&ar[3]);
        sum1 = ar[0]+ar[1]+ar[2];
        sum = ar[0]+ar[1];


        while((sum*3) > sum1)
            sum--;

        printf("%lld\n",sum);
    }

    return 0;
}
