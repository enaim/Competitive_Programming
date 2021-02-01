#include<stdio.h>


int main()
{
    int a;

    while(true)
    {
        scanf("%d",&a);

        if(a%400==0)
            printf("Leap Year\n");
        else if(a%100==0)
            printf("Not Leap Year\n");
        else if(a%4==0)
            printf("Leap Year\n");
        else
            printf("Not Leap Year\n");

    }
    return 0;
}

