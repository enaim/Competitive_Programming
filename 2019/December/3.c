#include<stdio.h>

int getArea(int h,int w)
{
    return h*w;
}

int main()
{
    int h,w;

    scanf("%d%d",&h,&w);

    printf("Area of rectangle = %d\n",getArea(h,w));

    return 0;
}
