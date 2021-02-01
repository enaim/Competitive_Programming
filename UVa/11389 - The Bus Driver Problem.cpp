#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,d,r,i,j,temp,tk,total,extra;;
    int a[110],b[110];

    while(3==scanf("%d%d%d",&n,&d,&r))
    {
        if(n==0 && d==0 && r==0)
            break;

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);

        sort(&a[0],&a[n]);
        sort(&b[0],&b[n]);

        tk=0;
        for(i=0;i<n;i++)
        {
            if(a[i]+b[n-1-i] > d)
            {
                extra = (a[i] + b[n-1-i]) - d ;
                tk = tk + (extra*r);
            }
        }
        printf("%d\n",tk);
    }

    return 0;
}



