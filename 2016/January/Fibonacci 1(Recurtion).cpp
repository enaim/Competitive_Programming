#include <stdio.h>
#include <string.h>
#include <math.h>

int fib(int n)
{
    int x,i;
    if(n<=10)    return n;

    x=0;
    for(i=1;i<=5;i++)
    {
       x=x+fib(n-i);
    }

    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    while(1==scanf("%d",&n))
    {
        n=fib(n);
        printf("Fibonacci : %d\n",n);
    }

    return 0;
}
