#include <stdio.h>
#include <string.h>
#include <math.h>

double const pi = acos(-1.0);

double angle(double a,double b,double c)
{
    double temp = ((pow(a,2))+(pow(b,2))-(pow(c,2)))/(2*a*b);
    double ang  = acos(temp);

    return ang;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,r;
    double a,b,c,s,x,y,z,r1,r2,r3,A,B,C,M,N,O,tri_area,Gap_area;

    scanf("%d",&n);
    r=0;
    while(r<n)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);

        a = r1+r2;
        b = r2+r3;
        c = r3+r1;

        s = (a+b+c)/2;
        tri_area = sqrt(s*(s-a)*(s-b)*(s-c));

        A = angle(b,c,a);
        B = angle(c,a,b);
        C = angle(a,b,c);
        x = 2*pi/A;
        y = 2*pi/B;
        z = 2*pi/C;

        M = (pi*r3*r3)/x;
        N = (pi*r1*r1)/y;
        O = (pi*r2*r2)/z;

        Gap_area = tri_area - (M+N+O);

        printf("%.6lf\n",Gap_area);
        r++;
    }

    return 0;
}
