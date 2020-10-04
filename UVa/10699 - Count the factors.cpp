#include <stdio.h>
#include <string.h>
#include <math.h>


const int FLAG_SIZE = 1000000;
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
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int n,i,cnt;
    while(1==scanf("%d",&n))
    {

        if(n==0)
            break;
        cnt = 0;
        for(i=1;i<78499;i++)
        {
            if(n%prime[i] == 0)
                cnt++;
        }
            printf("%d : %d\n",n,cnt);
    }

    return 0;
}

