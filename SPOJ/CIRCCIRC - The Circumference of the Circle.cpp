#include <stdio.h>
#include <string.h>
#include <math.h>


const double pi = acos(-1.0);

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double r1,y1,r2,y2,r3,y3;
    double A,a,b,c,x,R,p;
    while(6==scanf("%lf%lf%lf%lf%lf%lf",&r1,&y1,&r2,&y2,&r3,&y3))
    {
        a = sqrt(pow((r2-r3),2)+pow((y2-y3),2));
        b = sqrt(pow((r1-r3),2)+pow((y1-y3),2));
        c = sqrt(pow((r2-r1),2)+pow((y2-y1),2));

        x = ((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
        A = acos(x);
        R = a/(2.0*(sin(A)));
        p = 2*pi*R;
            printf("%.2lf\n",p);

    }
    return 0;
}
