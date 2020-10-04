#include<stdio.h>


int main()
{

    float a,b,dif;


    while(true)
    {
        scanf("%f%f",&a,&b);


        if(a<b) /// < > <= >= ==
        {
            printf("<\n");
        }
        else if(a>b){
            printf(">\n");
        }
        else{
            printf("=\n");
        }
    }


    return 0;
}
