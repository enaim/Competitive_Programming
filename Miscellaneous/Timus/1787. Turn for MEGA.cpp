#include<stdio.h>


int main()
{
    long long i,nomber,sum=0;
    scanf("%lld",&nomber);
    while(nomber!=1)
    {
        if(nomber>1)
        {
            sum=sum+nomber;
            nomber--;
        }

        else if(nomber<1)
        {
            sum=sum+nomber;
            nomber++;
        }
    }

    printf("%lld",sum+1);

    return 0;
}
