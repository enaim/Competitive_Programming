#include <stdio.h>
#include <string.h>
#include <math.h>





int fun(int n)
{
    if(n==0)    return 1;

    return n*fun(n-1);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;

    while(1==scanf("%d",&n))
    {
        n = fun(n);
        printf("Multiplication : %d\n",n);
    }

    return 0;
}
