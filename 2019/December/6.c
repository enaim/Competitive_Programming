#include<stdio.h>

int Reverse(int n)
{
    int rev = 0;

    while(n!=0)
    {
        rev = (rev * 10) + (n%10);
        n = n / 10;
    }

    return rev;
}

int main()
{
    int n;
    scanf("%d",&n);

    printf("Reverse = %d\n",Reverse(n));

    return 0;
}
