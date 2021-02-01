#include<stdio.h>
#include<string.h>

bool isPrime(int n)
{
    if(n==1)    return false;
    if(n==2)    return true;
    if(n%2==0)    return false;

    for(int i=3;i<n;i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


int allPrime2(int l,int r)
{
    int tota=0;
    for(int i=l;i<=r;i++)
        if(isPrime(i))
            tota++;

    return tota;
}

int allPrime(int a,int b)
{
    int i,j,total,flag;

    total=0;
    for(i=a;i<=b;i++)
    {
        flag=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }

        if(flag)
        {
            printf("%d\n",i);
            total++;
        }
    }

    return total;
}


int main()
{
    int a,b,x;

    while(2==scanf("%d%d",&a,&b))
    {
        x=allPrime2(a,b);

        printf("\nTOTAL : %d\n\n",x);
    }

    return 0;
}

