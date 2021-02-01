#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int d,m,n,x,y;

    while(1==scanf("%d",&n))
    {
        y = n / 365;
        x = n % 365;
        m = x / 30;
        d = x % 30;

        printf("year  : %d\nmonth : %d\nday   : %d\n",y,m,d);
    }

    return 0;
}

