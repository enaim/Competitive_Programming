#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,b,n;

    while(3==scanf("%d%d%d",&n,&a,&b))
    {
        printf("%d\n",2*a*b*n);
    }

    return 0;
}
