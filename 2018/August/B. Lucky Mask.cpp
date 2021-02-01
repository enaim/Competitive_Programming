#include<stdio.h>

int mask(int n)
{
    int x = 0,z;
    while(n!=0)
    {
        z = n%10;
        if(z==4 || z==7)
            x = x*10 + z;
        n/=10;
    }
    z = 0;
    while(x!=0)
    {
        n = x%10;
        z = z*10 + n;
        x/=10;
    }
    return z;
}


int main()
{
    int a,b,i;
    while(scanf("%d%d",&a,&b)==2)
    {
        for(i=a+1;;i++)
        {
            if(mask(i)==b)
                break;
        }
        printf("%d\n",i);
    }

    return 0;
}
