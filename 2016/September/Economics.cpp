#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double i,n=100,collect=0,spend=0,temp;
    for(i=0;i<100;i++)
    {
        temp = n / 10;
        collect+=temp;
        n = n - temp;
        spend+=n;
    }

    printf("Collect:%.2lf\nSpend:%.2lf\n",collect,spend);

    return 0;
}
