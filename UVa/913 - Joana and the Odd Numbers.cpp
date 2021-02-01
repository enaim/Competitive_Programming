#include <stdio.h>
#include <string.h>
#include <math.h>

long long Odd(long long N)
{
    long long i,x,srt,sum;
        if(N==1)
            return 1;
        else if(N==3)
            return 15;
        else
        {
            x=2;
            for(i=5;i<=N;i+=2)
            {
                x = x + 4;
                if(i==5)
                    srt = x + 3;
                else
                    srt=srt+x;
            }
            for(i=1;i<N;i++)
                srt = srt + 2;

            sum = (srt*3) - 6;
        }

    return sum;
}






int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    long long N,sum,x;
    while(1==scanf("%lld",&N))
    {
        sum = Odd(N);
        printf("%lld\n",sum);
    }

    return 0;
}

