#include<stdio.h>
#include<math.h>


int main()
{
    int a,b,c;

    double s,area;

    while(3==scanf("%d%d%d",&a,&b,&c))
    {
//        s=(a+b+c)/2.0;

        s=(double)(a+b+c)/2;

        area  = sqrt(s*(s-a)*(s-b)*(s-c));

        printf("area : %lf\n",area);
    }

    return 0;
}
