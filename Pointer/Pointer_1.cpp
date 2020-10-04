#include<stdio.h>


int main()
{
    int a = 10;
    int *p;

    p = &a;

    printf("a = %d\n",a);
    printf("p = %d\n",*p);

/// Address
    printf("p = %d\n",p);
    printf("p = %p\n",p);

    *p = 15;

    printf("\na = %d\n",a);
    printf("p = %d\n",*p);

///    *p++;   //not working

    (*p)++;

    printf("\na = %d\n",a);
    printf("p = %d\n",*p);

    int b = 20;
    int *q = &b;

    printf("\nb = %d\n",b);
    printf("q = %d\n",*q);

/// INPUT

    printf("\n");
    int *r;

    r = new int;
    scanf("%d",r);
    printf("r -> %d\n",*r);

    printf("\n");
    scanf("%d",&(*r));
    printf("r -> %d\n",*r);

    return 0;
}
