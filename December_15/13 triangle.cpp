#include<stdio.h>


int main()
{
    int a,b,c;

    while(true)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);

        if(a==b  && b==c)
            printf("Shomobahu\n");
        else if(a==b||b==c||a==c)
            printf("Shomodibahu\n");
        else if(a+b<=c||b+c<=a||c+a<=b)
            printf("impossible\n");
        else
            printf("Bishomobahu\n");
    }
    return 0;
}
