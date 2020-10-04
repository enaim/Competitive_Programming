#include<bits/stdc++.h>
using namespace std;


long long pow(long long n,long long p)
{
    long long i,ans = 1;
    for(i=1;i<=p;i++)
        ans = ans * n;
    return ans;
}


int main()
{

//    freopen("in.txt","r",stdin);

    long long tks,ks;
    long long ar[50],i,n,sum,x,j;
    scanf("%lld",&tks);
    while(tks--)
    {
        sum = 0;
        i=0;
        x = 5;
        while(x!=0)
        {
            scanf("%lld",&x);
            if(x!=0)
                ar[i++]=x;
        }
        n = i;

        sort(&ar[0],&ar[n]);

        j=1;
        for(i=n-1;i>=0;i--)
        {
            sum += 2*(pow(ar[i],j));
            j++;
        }
        if(sum > 5000000)
            printf("Too expensive\n");
        else
            printf("%lld\n",sum);
    }

    return 0;
}
