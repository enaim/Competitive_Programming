#include<stdio.h>
#include<math.h>

int main()
{
    int base,height;
    double area;

    while(2==scanf("%d%d",&base,&height))
    {
        area=(1.0/2)*base*height;

        printf("area : %lf\n",area);
    }
    return 0;
}
