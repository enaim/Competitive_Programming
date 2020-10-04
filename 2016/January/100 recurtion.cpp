#include<stdio.h>
#include<math.h>
#include<string.h>

#define SZ 1000000

int dp[SZ];

int cyCle(int n)
{
    int val;
    if(n<SZ && dp[n]!=-1)
        return dp[n];

 //   printf("%d\n",dp[n]);

    else if(n==1)
        return 1;
    else if(n%2==0)
        val =1 + cyCle(n/2);
    else
        val = 1 + cyCle (n*3+1);

    if(n<SZ)
        dp[n] = val;

    return val;
}


int main()
{   int a,b,i,l,x,temp;

    for(i=1;i<SZ;i++)
    {
        dp[i]=-1;
    }

    while(2==scanf("%d%d",&a,&b))
    {
        printf("%d %d ",a,b);

        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        x=0;
        for(i=a;i<=b;i++)
        {
            l=cyCle(i);
            if(x<l)
                x=l;
        }

        printf("%d\n",x);
    }
    return 0;
}

