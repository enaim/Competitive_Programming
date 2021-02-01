#include <stdio.h>
#include <string.h>
#include <math.h>

int fun(long long n)
{
    int sum;
    if(n>0)
        sum=n%10;
    else
        return 0;

    return sum+fun(n/10);
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n;
    int sum;
    while(1==scanf("%lld",&n))
    {
        sum = fun(n);
        printf("Digit Sum: %d\n",sum);
    }

    return 0;
}

