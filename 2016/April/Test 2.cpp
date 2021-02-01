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
//    printf("Number of Prime : %d\n",ind);
}

int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    int n,i,j;
    while(1==scanf("%d",&n) && n)
    {
        for(i=1;i<78500;i++)
        {
            for(j=i;j<78500;j++)
            {
                if(n == (prime[i]+prime[j]))
                    break;
            }
            if(n == (prime[i]+prime[j]))
                    break;
        }
        if(n == (prime[i]+prime[j]))
            printf("%d = %d + %d\n",n,prime[i],prime[j]);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}

