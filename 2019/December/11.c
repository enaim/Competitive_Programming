#include<stdio.h>

int isPrime(int n)
{
    if(n==1)
        return 0;
    int i;
    int flag = 0;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
        return 0;
    return 1;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    if(isPrime(n))
        printf("Prime\n");
    else
        printf("Not prime\n");

    return 0;
}
