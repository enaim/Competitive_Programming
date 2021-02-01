#include<stdio.h>


void func(int *p)
{
    printf("*p = %d\n",*p);
}

void func1(int &r)
{
    printf("r = %d\n",r);
    r =  50;
}

void func2(int &r)
{
    int *p = &r;
    printf("*p = %d\n",*p);
}

int func3(int n)
{
    int *p;
    p = &n;
    printf("*p = %d\n",*p);
    *p= 100;
    return *p;
}

int main()
{
    int a=20;

    func(&a);
    func1(a);
    func2(a);
    a = func3(a);
    printf("a = %d\n",a);

    return 0;
}
