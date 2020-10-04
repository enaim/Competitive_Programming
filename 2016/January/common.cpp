#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,i;
    while(2==scanf("%d%d",&a,&b))
    {
        if(a>b)
            c=a;
        else
            c=b;
        i=0;
        for(i=2;i<c/2;i++)
        {
            if(a%i==0 && b%i==0)
            {
                printf("%d ",i);
            }
        }
    }
    return 0;
}
