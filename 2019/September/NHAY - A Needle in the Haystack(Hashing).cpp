#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

const int p = 31;
const int M = 1e9+9;
//const int MM = 1610612741;

ll h[1000010];
ll h1[1000010];
ll inv[1000010];
ll p_pow[1000010];
char str[1000010];
char str1[1000010];

void pow_calculate()
{
    p_pow[0]=1;
    for(int i=1;i<1000010;i++)
        p_pow[i] = (p_pow[i-1]*p)%M;

    ///inv array is needed for finding substring hash
    inv[0]=1;
    for(int i=1;i<1000010;i++)
        inv[i] = BigMod(p_pow[i],M-2,M);
}

void hashing(int n)
{
    h[0]=0;
    for(int i=0;i<n;i++)
        h[i+1] = (h[i]+((str[i]-'a'+1)*p_pow[i]))%M;
}

void hashing1(int n)
{
    h1[0]=0;
    for(int i=0;i<n;i++)
        h1[i+1] = (h1[i]+((str1[i]-'a'+1)*p_pow[i]))%M;
}

ll substring_hash(int l,int r)
{
    return (( (h[r+1]-h[l]+M) % M) * (inv[l]%M))%M;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    pow_calculate();
    int m,ks=1;
    int cnt = 0;
    while(1==scanf("%d",&m))
    {
        scanf("%s",str1);
        scanf("%s",str);
        int n = strlen(str);
        hashing(n);
        hashing1(m);
        for(int i=0;i<n-m+1;i++)
        {
            if(h1[m]==substring_hash(i,i+m-1))
            {
                if(cnt==0 && ks!=1)
                    printf("\n");
                printf("%d\n",i),cnt++;
            }
        }
        ks++;
        cnt = 0;
    }

    return 0;
}
