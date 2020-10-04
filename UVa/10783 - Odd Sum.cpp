#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,r,T,i,sum;

    r=1;
    scanf("%d",&T);
    while(r<=T)
    {
        scanf("%d%d",&a,&b);
        sum=0;
        for(i=a;i<=b;i++)
            if(i%2 != 0)
                sum+=i;
        printf("Case %d: %d\n",r,sum);
        r++;
    }
    return 0;
}

