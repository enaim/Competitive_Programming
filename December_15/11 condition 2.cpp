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

            if(a>0 && a<100)
            {
                printf("Two Digit\n");
            }
            else if(a>99)
                printf("More Than Two Digit\n");
        }
        else
            printf("Odd\n");
    }

    return 0;
}
