#include<stdio.h>

int countEvenDigit(int n)
{
    int cnt = 0,rem;

    while(n!=0)
    {
        rem = n%10;

        if(rem%2==0)
            cnt++;
        n/=10;
    }

    return cnt;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    printf("Number of even digits = %d\n",countEvenDigit(n));

    return 0;
}
