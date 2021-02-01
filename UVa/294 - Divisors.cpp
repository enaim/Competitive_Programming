#include <stdio.h>
#include <string.h>
#include <math.h>



bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void siEve()
{
    int ind=1,i,j,d;

    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++] = i;

            if(i> FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<FLAG_SIZE;j+=d)
                flag[j] = true;
        }
    }
//    printf("Number of Prime : %d\n",ind);
}


int diviSor(int n)
{
    int i,j,k,y,ans=1,cnt,tmp;
    int a[35];
    j=0;
    tmp=n;

    for(i=1;prime[i]<=n/prime[i];i++)
    {
        cnt=0;
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }
        ans*=(cnt+1);
    }
        if(n!=1)
            ans*=2;

    return ans;
}




int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,r,L,n,U,x,mx,temp;
    siEve();
    scanf("%d",&n);
    r=1;
    while(r<=n)
    {
        scanf("%d%d",&L,&U);
        mx=0;
        temp=L;
        for(i=L;i<=U;i++)
        {
            x=diviSor(i);
//            printf("%d :x: %d\n",i,x);
            if(x>mx)
            {
                mx=x;
                temp=i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,temp,mx);
        r++;
    }

    return 0;
}

