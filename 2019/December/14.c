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

void printAllPrimes(int left,int right)
{
    if(left>right)
    {
        int temp = left;
        left = right;
        right = temp;
    }

    int cnt = 0;
    for(int i=left;i<=right;i++)
    {
        if(isPrime(i))
        {
            cnt++;
            printf("%d\n",i);
        }
    }
    printf("Number of primes between left to right - > %d\n",cnt);
    return;
}

int main()
{
    int l,r;
    printf("Enter left and right values: ");

    scanf("%d%d",&l,&r);

    printAllPrimes(l,r);

    return 0;
}
