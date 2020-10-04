#include<stdio.h>


int main()
{
    int a;
    int b;
    int sum,temp,gls,oddSum,evenSum;

    while(2==scanf("%d%d",&a,&b))
    {
        if(a>b)
        {   temp=a;
            a=b;
            b=temp;
        }

        oddSum=evenSum=0;

        while(a<=b)
        {
            if(a%2==0)
                evenSum=a+evenSum;
            else
                oddSum+=a;         ///oddSum = oddSum+a;

            a++;
        }

        printf("Even Sum:%d\n Odd Sum:%d\n",evenSum,oddSum);
    }
    return 0;
}
