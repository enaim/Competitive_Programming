#include <stdio.h>
#include <string.h>
#include <math.h>


void prInt(int n)
{
    int val;

    if(n==0)
        return;

    printf("%d\n",n);
    prInt(n-1);

    //printf("%d\n",n);

    return ;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;
    while(1==scanf("%d",&n))
    {
        prInt(n);
    }

    return 0;
}
