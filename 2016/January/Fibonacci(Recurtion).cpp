#include <stdio.h>
#include <string.h>
#include <math.h>

int fib(int n)
{
    if(n<=2)    return 1;

    return fib(n-1)+fib(n-2);
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
