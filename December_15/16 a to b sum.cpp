#include<stdio.h>


int main()
{
    int a,b,sum,temp;

    while(2 == scanf("%d%d",&a,&b))
    {
        if ( a >= b)
        {
            temp = a ;
            a = b ;
            b = temp ;
        }
        sum = 0;

        while ( a <= b)
        {
            sum = a + sum ;

            a = a + 1 ;
        }
        printf("sum -> %d",sum);
    }

    return 0;
}
