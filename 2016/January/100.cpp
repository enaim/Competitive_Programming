#include<stdio.h>
#include<math.h>
#include<string.h>


int cyCle(int n)
{
    int l;
    l=0;
    l++;
    while(n!=1)
    {
        if(n%2==0)
        {
            l++;
            n=n/2;
        }
        else
        {
            l++;
            n=n*3+1;
        }
    }
    return l;
}


int main()
{   int a,b,i,l,x,temp;
    while(2==scanf("%d%d",&a,&b))
    {
        printf("%d %d ",a,b);
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        x=0;
        for(i=a;i<=b;i++)
        {
            l=cyCle(i);
            if(x<l)
                x=l;
        }
        printf("%d\n",x);
    }
    return 0;
}

