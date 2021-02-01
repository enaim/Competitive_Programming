#include <stdio.h>
#include <string.h>
#include <math.h>

int a[]={1,5,10,25,50};

long long memo[100];

long long dp(int n)
{
    long long ret=0;

    if(n<0) return 0;
    if(n<5) return 1;

    for(int i=0;i<5;i++)
    {
        if(n>a[i])
            ret+=dp(n-a[i]);

    }
    return ret;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n;
    long long l;

    while(1==scanf("%d",&n))
    {
        l=dp(n);
        printf("%lld\n",l);
        printf("%I64d\n",l);
    }

    return 0;
}

