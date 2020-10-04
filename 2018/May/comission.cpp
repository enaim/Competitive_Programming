#include<stdio.h>


int main()
{
    int amount,commission;

    scanf("%d",&amount);

    if(amount>=200000)
    {
        commission = (amount/100)*7;
    }
    else if(amount>=150000)
    {
        commission = (amount/100)*5;
    }
    else if(amount>=100000)
    {
        commission = (amount/100)*2;
    }
    else
    {
        commission = (amount/100)*1;
    }

    printf("Commission is = %d\n",commission);

    return 0;
}
