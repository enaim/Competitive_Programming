#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,d,n=0,i;
    while(2==scanf("%d%d",&a,&b))
    {
        if(a>b)
        {
            c=b;
            d=a;
        }
        else
        {
            c=a;
            d=b;
        }
        if(d%c==0)
            printf("%d\n",c);
        else
        {
            while(c!=0)
            {
                n=d%c;
                d=c;
                c=n;
            }
            printf("%d\n",d);
        }
    }
    return 0;
}
