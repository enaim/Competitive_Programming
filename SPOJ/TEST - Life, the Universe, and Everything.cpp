#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,n;
    a=0;
    while(1==scanf("%d",&n))
    {
        if(n==42)
            a=1;
        if(a==0)
            printf("%d\n",n);
    }

    return 0;
}
