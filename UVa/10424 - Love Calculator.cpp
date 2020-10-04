#include <stdio.h>
#include <string.h>
#include <math.h>


char ar[30];

int sum()
{
    int len,i,sum=0;
    len=strlen(ar);

    for(i=0;i<len;i++)
    {
        if(ar[i]>64 && ar[i]<92)
            sum=sum+(ar[i]-64);
        else if(ar[i]>96 && ar[i]<123)
            sum=sum+(ar[i]-96);
    }
    return sum;
}


int digit(int n)
{
    int x,sum=0;
    while(n!=0)
    {
        x=n%10;
        n=n/10;
        sum+=x;
    }

    return sum;
}


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int sum1,sum2,temp;
    double x;

    while(gets(ar))
    {
        sum1=sum();

        gets(ar);
        sum2=sum();

        while(sum1>9)
            sum1 = digit(sum1);
        while(sum2>9)
            sum2 = digit(sum2);

        if(sum1!=0 && sum2!=0)
        {
            if(sum1<sum2)
            {
                temp=sum1;
                sum1=sum2;
                sum2=temp;
            }
            x = (100.0*sum2)/sum1;
            printf("%.2lf %%\n",x);
        }
        else if(sum1==0 && sum2==0)
            printf("\n");
        else
            printf("0.00 %%\n");
    }

    return 0;
}

