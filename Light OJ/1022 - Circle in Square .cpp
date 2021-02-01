#include <stdio.h>
#include <string.h>
#include <math.h>


const double pi = 2 * acos (0.0);

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double r,shaded;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf",&r);

        shaded = (4*r*r) - (pi*r*r);

        printf("Case %d: %.2lf\n",ks++,shaded);
    }

    return 0;
}


