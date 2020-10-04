#include<stdio.h>

int main()
{
    int a,b,c,d;

    a=3;
    b=5;
    c=a*(a%b);
    d=++c;

    printf("%d\n%d\n%d\n%d",++a,b++,c,d);
}
