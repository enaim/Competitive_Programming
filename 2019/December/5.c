#include<stdio.h>

int digitSum(int n)
{
    int sum = 0;

    while(n!=0)
    {
        sum = sum + (n%10);
        n = n / 10;
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);

    printf("Digit sum = %d\n",digitSum(n));

    return 0;
}
