#include<stdio.h>


int main()
{
    double d,v,t;

    printf("Enter The Distance & Average Speed :");
    scanf("%lf%lf",&d,&v);

    t = d/v;

    printf("Driving Time -> %.2lf\n",t);

    return 0;
}
