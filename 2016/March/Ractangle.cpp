#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double x1,y1,x2,y2,x3,y3,x4,y4,mid1,mid2;
    while(6==scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        x4=(x1+x3)-x2;
        y4=(y1+y3)-y2;
        printf("(x,y) = (%lf,%lf)",x4,y4);
    }

    return 0;
}

