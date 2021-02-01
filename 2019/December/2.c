#include<stdio.h>

double getArea(double r)
{
    return r*r*3.1416;
}

int main()
{
    double r,area;

    printf("Enter the radius of a circle: ");
    scanf("%lf",&r);

    area = getArea(r);

    printf("Area of the circle -> %.3lf\n",area);

    return 0;
}
