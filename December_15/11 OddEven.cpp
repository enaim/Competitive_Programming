#include<stdio.h>


int main()
{
    int a;

    while(true)
    {
        scanf("%d",&a);

        if(a%2 == 0) /// < > <= >= ==
        {
            printf("Even\n");
        }
        else
            printf("Odd\n");
        }

    return 0;
}
