#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int phi[1000010];
int ar[1000010];

void Euler_totient_function()
{
    int i,j;
    for(i=2;i<=1e6+5;i++)
        phi[i]=i;
    for(i=2;i<=1e6+5;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=1e6+5;j+=i)
                phi[j]=phi[j]/i * (i-1);
        }
    }

    j = 1;
    for(i=2;i<=1e6+3;i++)
    {
        if(phi[i]>=j)
        {
            while(j<=phi[i])
            {
                ar[j]=i;
                j++;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Euler_totient_function();

    int tks,ks=1,i,n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        ll sum = 0LL;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=ar[x];
        }
        printf("Case %d: %lld Xukha\n",ks++,sum);
    }

    return 0;
}
