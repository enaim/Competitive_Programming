#include<stdio.h>


int main()
{
    int a;
    int b;
    int temp;

    while(2==scanf("%d%d",&a,&b))
    {
        if(a>=b)
        {
            temp=a;
            a=b;
            b=temp;
        }

        while(a<=b)
        {
            if(a%2==0)
            printf("a -> %d\n",a);

            a=a+1;
        }
    }

    return 0;
}
