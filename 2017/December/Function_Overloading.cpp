#include<stdio.h>

int add(int a,int b)
{
    return a+b;
}

double add(double a,double b)
{
    return a+b;
}

//void print(unsigned int a)
//{
//    printf("a = %d\n",a);
//}

void print(int a)
{
    printf("a = %d\n",a);
}


void print(double a)
{
    printf("a = %lf\n",a);
}

int main()
{
    int a=1,b=2;
    double c=3.025,d=53.025447;
    printf("%d\n",add(a,b));
    printf("%lf\n",add(c,d));
    print('a');
    print(0);
    print(3.0145);
    return 0;
}
