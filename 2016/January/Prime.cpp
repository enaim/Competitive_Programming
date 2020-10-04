#include<stdio.h>
#include<string.h>


bool isPrime(int n)
{
    int i;
    bool ba=true,bb=false;
    for(i=2;i<n;i++)
        if(n%i==0)
            return bb;

    return true;
}


bool fun(int a)
{
    return isPrime(a);
}


int main()
{
    int n;bool x;

    while(1==scanf("%d",&n))
    {
        x=isPrime(n);

        if(x==1)
            printf("%d IS PRIME\n",n);
        else
            printf("%d IS NOT PRIME\n",n);
    }

    return 0;
}
