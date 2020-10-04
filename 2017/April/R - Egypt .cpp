#include<stdio.h>
#include<math.h>


int main()
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3 && (a || b || c))
    {
        if((a*a) == ((b*b)+(c*c)))
            printf("right\n");
        else if((b*b) == ((a*a)+(c*c)))
            printf("right\n");
        else if((c*c) == ((b*b)+(a*a)))
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}
