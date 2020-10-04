#include<stdio.h>
#include<math.h>


int main()
{
    int Tks,ks=1;
    double pi = acos(-1.0);
    double r,area;

    scanf("%d",&Tks);
    while(ks<=Tks)
    {
        scanf("%lf",&r);
        area = pi*r*r;
        printf("Case %d: %.4lf\n",ks,area);

        ks++;
    }

    return 0;
}
