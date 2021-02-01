#include <stdio.h>
#include <string.h>
#include <math.h>


int dp[10000];

int fib(int n)
{
    if(n<=2)    return 1;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n-1)+fib(n-2);
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,l;

    for(i=1;i<=10000;i++)
    {
        dp[i]=-1;
    }

    while(1==scanf("%d",&n))
    {
        printf("%d\n",dp[n]);


        printf("Fibonacci : %d\n",fib(n));
    }

    return 0;
}
