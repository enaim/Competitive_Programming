#include <stdio.h>
#include <string.h>
#include <math.h>


const double pi = acos(-1);

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double l,r,w,area_G,area_R;

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf",&l);
        w = (6*l)/10;
        r = l/5;

        area_R = pi*r*r;
        area_G = (w*l) - area_R;

        printf("%.2lf %.2lf\n",area_R,area_G);
    }

    return 0;
}

