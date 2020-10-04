#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int m,n,mx,mn,x,y;

    while(1==scanf("%d",&n))
    {
        x=n/7;
        y=n%7;

        if(y>=2)
            mx=(x*2)+2;
        else if(y>=1)
            mx=(x*2)+1;
        else
            mx=x*2;

        if(y>5)
            mn=(x*2)+1;
        else
            mn=x*2;

        printf("%d %d\n",mn,mx);
    }

    return 0;
}
