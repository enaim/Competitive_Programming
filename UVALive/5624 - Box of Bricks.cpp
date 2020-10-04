#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,b,c,sum,x,r=0;
    int a[100];

    while(1==scanf("%d",&n))
    {
        if(n==0)
            break;

        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        x=sum/n;

        b=0;
        c=0;
        for(i=0;i<n;i++)
        {
            if(x<a[i])
            {
                b=a[i]-x;
                c+=b;
            }
        }
        printf("Set #%d\n",++r);
        printf("The minimum number of moves is %d.\n",c);
        printf("\n");
    }

    return 0;
}

