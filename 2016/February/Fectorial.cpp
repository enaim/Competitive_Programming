#include <stdio.h>
#include <string.h>
#include <math.h>



int dp[50];

int fun(int n)
{
    int val;
    if(n==0)    return 1;
    val = n*fun(n-1);
    printf("%d! = %d\n",n,val);
    return dp[n]=val;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,x,i;

    while(1==scanf("%d",&n))
    {
        x = fun(n);
//        for(i=1;i<=n;i++)
//        {
//            printf("%d! = %d\n",i,dp[i]);
//        }
        printf("Fectorial: %d\n",x);
    }

    return 0;
}

