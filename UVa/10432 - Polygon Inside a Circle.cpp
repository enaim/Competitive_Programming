#include <stdio.h>
#include <string.h>
#include <math.h>

const double pi = acos(-1.0);

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double r,n;
    double x;

    while(2==scanf("%lf%lf",&r,&n))
    {
        x=0.5*r*r*sin(pi*2.0/n)*n;

        printf("%.3lf\n",x);
    }
    return 0;
}

