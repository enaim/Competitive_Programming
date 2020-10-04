#include <stdio.h>
#include <string.h>
#include <math.h>


const int Flag_Size  = 1000000;
const int Prime_Size = 80000;

bool flag[Flag_Size];
int prime[Prime_Size];


void sieve()
{
    int i,j,ind =1,d;

    prime[ind++]=2;

    for(i=3;i<=Flag_Size;i+=2)
    {
        if(flag[i]==false)
        {
            prime[ind++]=i;

            if(i>Flag_Size/i)
                continue;

            for(j=i*i,d=i+i;j<=Flag_Size;j+=d)
                flag[j]=true;
        }
    }
//    printf("Total prime : %d\n",ind);
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve();

    int n,a,x,i;

    while(1==scanf("%d",&n) && n)
    {
        a=0;

        for(i=1;i<78498;i++)
        {
            x = n - prime[i];

            if(x%2==0)
                continue;
            if(flag[x] == false)
            {
                a=1;
                break;
            }
        }

        if(a==1)
            printf("%d = %d + %d\n",n,prime[i],x);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}

