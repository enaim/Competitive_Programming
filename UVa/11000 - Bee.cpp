#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int N;
    long long m,r,f,t;
    while(1==scanf("%d",&N))
    {
        if(N == -1)
            break;
        if(N == 0)
        {
            m=0;
            t=1;
        }
        r=1;
        while(r <= N)
        {
            if(r==1)
            {
                m=1;
                f=1;
                t=2;
            }
            else
            {
                f=m+1;
                m=t;
                t=m+f;
            }
            r++;
        }
        printf("%lld %lld\n",m,t);
    }

    return 0;
}
