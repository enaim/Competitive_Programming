#include <stdio.h>
#include <string.h>
#include <math.h>

const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void sieve()
{
    int ind = 1,i,j;
    double d;

    prime [ ind++ ]  = 2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int n,c,i,x,y,target;
    int cnt,avg,j=0;
    while(scanf("%d%d",&n,&c)==2)
    {
        cnt = 1;
        prime[0]=1;
        for(i=1;i<200;i++)
        {
            if(prime[i]<=n)
                cnt++;
        }

        if(cnt%2 != 0)
        {
            avg = (cnt+1)/2;
            target = (2*c) - 1;
        }
        else
        {
            avg = cnt/2;
            target = 2*c;
        }
        x = avg-(c-1);

        y = x+target-1;

        printf("%d %d:",n,c);
        if(x<1)
            x = 1;
        for(i=x-1;i<y && prime[i] <= n ;i++)
            printf(" %d",prime[i]);
        printf("\n\n");

        j++;
    }

    return 0;
}
