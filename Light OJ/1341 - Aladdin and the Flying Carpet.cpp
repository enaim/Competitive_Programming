#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int FLAG_SIZE = 1000100;
const int PRIME_SIZE = 80000;

ll flag[FLAG_SIZE/64+10];
int prime[PRIME_SIZE],ind;

void sieve()//1 indexed
{
    long long i,j,k;
    for(i=3;i<FLAG_SIZE;i+=2)
         if(!(flag[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<FLAG_SIZE;j+=2*i)
                    flag[j/64]|=(1LL<<(j%64));
    ind = 1;
    prime[ind++]=2;
    for (int i=3;i<FLAG_SIZE;i+=2)
        if(!(flag[i/64]&(1LL<<(i%64))))
            prime[ind++] = i;
}

ll divisor(ll n)
{
    ll ans=1LL,i,cnt;
    for(i=1;prime[i]<=n/prime[i];i++)
    {
        cnt = 0LL;
        while(n%prime[i]==0LL)
        {
            cnt++;
            n/=prime[i];
        }
        ans *= (cnt+1LL);
    }
    if(n!=1LL)
        ans*=2LL;
    return ans;
}

int main()
{
    sieve();

    ll n,x,d,i;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&x);
        if(x*x>n)
        {
            printf("Case %d: %lld\n",ks++,0);
            continue;
        }

        d = divisor(n);
        d/=2LL;
        for(i=1LL;i<x;i++)
        {
            if(n%i==0LL)
                d--;
        }
        printf("Case %d: %lld\n",ks++,d);
    }

    return 0;
}
