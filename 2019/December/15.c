#include<stdio.h>

int NthFib(int n)
{
    if(n==1)
        return 0;
    if (n==2)
        return 1;

    int a = 0;
    int b = 1;
    int sum;
    for(int i=3;i<=n;i++)
    {
        sum = a+b;
        a = b;
        b = sum;
    }
    return b;
}

int main()
{
    int n;

    scanf("%d",&n);

    printf("Nth Fibonacci is - > %d\n",NthFib(n));

    return 0;
}
