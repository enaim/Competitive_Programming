#include<stdio.h>


int main()
{
    int a,b,sum,n,x;
    while(scanf("%d",&n)==1)
    {
        sum = n;
        while(n>=3)
        {
            a= n/3;
            b= n%3;
            sum+=a;
            n = a+b;
        }
        if(n==2)
            printf("%d\n",sum+1);
        else
            printf("%d\n",sum);
    }

    return 0;
}
