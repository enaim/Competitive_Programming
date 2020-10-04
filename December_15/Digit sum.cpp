#include<stdio.h>
#include<string.h>


int total(int n)
{
    int sum=0,a;

    while( 0 != n )
    {
        a=n%10;

        n/=10;
        sum+=a;
    }

    return sum;
}


int main()
{
    int b,n;

    while(1==scanf("%d",&n))
    {
        b=total(n);
        printf("sum -> %d\n",b);
    }

    return 0;
}
