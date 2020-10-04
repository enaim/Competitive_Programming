#include <stdio.h>
#include <string.h>
#include <math.h>

double const pi = acos(-1.0);


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,b,c;
    double s,r,angle,A,R,violet,sunflower,violet_area,sunflower_area,rose_area;

    while(3==scanf("%d%d%d",&a,&b,&c))
    {
        s = (a+b+c)/2.0;
        violet = sqrt(s*(s-a)*(s-b)*(s-c));

        r = violet/s;
        rose_area = pi*r*r;

        angle = ((pow(b,2))+(pow(c,2))-(pow(a,2))) / (2.0*b*c);
        A = acos(angle);
        R = (a/sin(A))/2.0;
        sunflower = pi*R*R;

        violet_area = violet - rose_area;
        sunflower_area = sunflower - violet;

        printf("%.4lf %.4lf %.4lf\n",sunflower_area,violet_area,rose_area);
    }

    return 0;
}
