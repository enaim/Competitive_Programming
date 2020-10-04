#include<stdio.h>


int main()
{
    int a;
    int b;
    int sum,temp,gls;

    while(2==scanf("%d%d",&a,&b))
    {

        if(a>b)
        {   temp=a;
            a=b;
            b=temp;
        }
        gls = a;
        sum=0;
        while(a<=b)
        {
            if(a%2==0)
                sum=a+sum;

            a++;
        }
        printf("even : %d\n",sum);

        sum=0;
        a=gls;
        while(a<=b)
        {
            if(a%2!=0)
                sum=a+sum;
            a++;
        }
        printf("ODD: %d\n",sum);
    }
    return 0;
}
