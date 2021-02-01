#include<stdio.h>


int main()
{
    int a;
    int b;
    int c;
    int temp;

    while(3==scanf("%d%d%d",&a,&b,&c))
    {   if(a>=b)
        {
            temp=a;
            a=b;
            b=temp;
        }

        while(a<=b)
        {
            if(a%c==0)
            printf("a -> %d\n",a);

            a=a+1;
        }
    }

    return 0;
}


