#include<stdio.h>

/*
    A prime number is a number which is greater than 1 and divisible only by itself and 1.
    Ex: 2,3,5,7,11 etc.
*/

int main()
{
    int n,i,flag = 0;

    printf("Enter a number: ");
    scanf("%d",&n);

    for(i=2;i<=n/2;i++)     ///we iterate this loop from 2 to n/2 because it is impossible to find
    {                       ///any divisor of a number which is greater than half of that number.
        if(n%i==0)
        {
            flag = 1;
            break;
        }
    }

    if(flag==0 && n!=1)
    {
        printf("%d is a prime number\n",n);
    }
    else
    {
        printf("%d is not a prime number\n",n);
    }

    return 0;
}
