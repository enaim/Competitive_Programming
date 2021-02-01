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

            if(i > FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
//    printf("Number of Prime : %d\n",ind);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,g,temp,k,x;
    int pf[40];
    sieve();

    while(1==scanf("%d",&g))
    {
        for(i=0;i<40;i++)
            pf[i]=0;

        if(g==0)    break;

        temp = g;
        if(g<0)
            g=g*(-1);

        j=0;
        for(i=1;prime[i]<=g/prime[i];i++)
        {
            while(g%prime[i]==0)
            {
                g=g/prime[i];
                pf[j]=prime[i];
                j++;
            }
        }
         if(temp>-1)
                printf("%d = ",temp);
        else
            printf("%d = -1 x ",temp);


        if(pf[0]==0)
            printf("%d\n",g);
        else if(g != 1)
        {
            for(k=0;k<j-1;k++)
            {
                printf("%d ",pf[k]);
                printf("x ");
            }
            printf("%d ",pf[k]);
            printf("x %d\n",g);
        }
        else
        {
            for(k=0;k<j-1;k++)
            {
                printf("%d ",pf[k]);
                printf("x ");
            }
            printf("%d\n",pf[k]);
        }
    }

    return 0;
}


