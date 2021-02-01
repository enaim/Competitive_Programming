#include <stdio.h>
#include <string.h>
#include <math.h>


int a;

int striped_region(double x,double y,int M)
{
    double rad_A,rad_B,rad_C,rad_D;

    rad_A = sqrt((x*x)+(y*y));
    rad_B = sqrt((pow((a-x),2))+(pow((0-y),2)));
    rad_C = sqrt((pow((a-x),2))+(pow((a-y),2)));
    rad_D = sqrt((pow((0-x),2))+(pow((a-y),2)));

    if(rad_A <= a && rad_B <= a && rad_C <= a && rad_D <= a)
        M++;

    return M;
 }


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int N,r,M;
    double x,y,Area;

    while(2==scanf("%d%d",&N,&a) && N)
    {
        M=0;
        r=0;
        while(r<N)
        {
            scanf("%lf%lf",&x,&y);
            M = striped_region(x,y,M);
            r++;
        }

        Area = M*a*a/(double)N;
        printf("%.5lf\n",Area);
    }

    return 0;
}
