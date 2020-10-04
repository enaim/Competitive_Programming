#include <stdio.h>
#include <string.h>
#include <math.h>

const double pi=acos(-1.0);
const double r = 5;
const double d =7.87;
const double m=2500;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    double v,temp,dx,x,h;

    v = m/d;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf",&x);
        h = v/((pi*(r+x)*(r+x))-(pi*r*r));
        printf("Case %d: %lf\n",ks++,h);
    }

    return 0;
}

