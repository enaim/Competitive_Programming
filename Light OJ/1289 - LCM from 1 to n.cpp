#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int FLAG_SIZE = 100000100;
const int PRIME_SIZE = 5761500;

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
//    for(i=1;i<10;i++)
//        printf("%d\n",prime[i]);
//    printf("%d\n",ind);
}

long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}

const ll m = 4294967296;
unsigned int dp[PRIME_SIZE];

ll Binary_search(ll n)
{
    long long l=1,r=ind,ans,mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(prime[mid]==n)
            return mid;
        else if(prime[mid]<=n)
        {
            l = mid+1;
            ans = mid;
        }
        else
            r = mid-1;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();

    dp[1]=2;
    for(int i=2;i<=5761461;i++)
        dp[i]=prime[i]*dp[i-1];

    unsigned long long ans,t,x,n;
    int tks,ks=1,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%llu",&n);
        ans=1LL;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            x = prime[i];
            t = x;
            while(x<=n)
                x*=t;
            x/=t;
            x/=t;
            ans = ((ans%m)*(x%m))%m;
        }
        t = Binary_search(n);
        ans = ((ans%m)*(dp[t]%m))%m;

        printf("Case %d: %llu\n",ks++,ans);
    }

    return 0;
}
