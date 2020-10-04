#include<stdio.h>


int main()
{

    int a;


    while(true)
    {
        scanf("%d",&a);

        if(a%2 == 0 || a<=0) /// < > <= >= ==
        {
            printf("Good %d\n",a);
        }
        else if( (a>=10 && a<=20) || (a>100 && a<200) || (a>1000 && a<2000))
            printf("Also Good\n");
        else
            printf("Bad\n");
    }


    return 0;
}
