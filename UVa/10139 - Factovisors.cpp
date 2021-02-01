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


int Fact_Divisor(int n,int p)
{
    int sum=0;

    while(n != 0)
    {
        n=n/p;
        sum+=n;
    }

    return sum;
}


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int i,sum,cnt,n,temp,j,m;
    bool x;

    while(2==scanf("%d%d",&n,&m))
    {
        temp = m;
        x = true;
        if(m == 0)
        {
            printf("%d does not divide %d!\n",temp,n);
            continue;
        }

        if((n == 0 && m == 1) || m <= n)
        {
            printf("%d divides %d!\n",temp,n);
            continue;
        }

        else
        {
            for(i=1; prime[i] <= m/prime[i]; i ++)
                if(0 == m%prime[i])
                {
                    sum = Fact_Divisor(n,prime[i]);
                    int cnt=0;
                    while(0 == m%prime[i])
                    {
                        cnt++;
                        m/=prime[i];
                    }
                    if(cnt>sum)
                    {
                        x = false;
                        break;
                    }
                }

                if(x && m != 1)
                {
                    sum = Fact_Divisor(n,m);
                    if(sum == 0)
                    {
                        x= false;
                    }
                }

                if(x ==  false)
                    printf("%d does not divide %d!\n",temp,n);
                else
                    printf("%d divides %d!\n",temp,n);
        }
    }

    return 0;
}
