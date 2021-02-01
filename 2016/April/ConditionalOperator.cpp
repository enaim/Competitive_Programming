#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,maximum;

    while(2==scanf("%d%d",&a,&b))
    {
        maximum = a>b ? a : b;
        int absVal = a>b? a-b : b-a;

        printf("Max:%d\nAbs:%d\n",maximum, absVal);
    }



    return 0;
}
