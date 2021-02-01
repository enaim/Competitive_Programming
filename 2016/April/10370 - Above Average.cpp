#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a[1010],i,C,sum,r=0,cnt,N;
    double abv,avg,n;

    scanf("%d",&C);

    while(r < C)
    {
        sum = 0;
        cnt = 0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        n  =  N;

        avg = sum / n;

        for(i=0;i<N;i++)
        {
            if( avg < a[i])
                cnt++;
        }

        abv = (100/n) * cnt;
        printf("%.3lf%%\n",abv);
        r++;
    }

    return 0;
}

