
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int sum,a,r,n;

    while(1==scanf("%d",&n))
    {
        printf("binary: %d\n",n);
        sum=0;
        r=0;
        while(0 != n)
        {
            a=n%10;
            n/=10;
            sum+=(a*pow(2,r));
            r++;
        }
        printf("decimal : %d\n",sum);
    }

    return 0;
}
