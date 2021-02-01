#include<stdio.h>


int main()
{
    int amount,tax;

    scanf("%d",&amount);

    if(amount>=11500)
    {
        tax = 150;
    }
    else if(amount>=8000)
    {
        tax = 100;
    }
    else
    {
        tax = 0;
    }

    printf("Tax is = %d\n",tax);

    return 0;
}
