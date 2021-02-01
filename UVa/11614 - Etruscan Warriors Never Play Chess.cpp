#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define OO 2e9+10

typedef long long ll;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);

ll summation(ll n)
{
    return (n*(n+1))/2;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tks,ks=1;
    ll mid,r,l,x,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        int f=0;
        l=0,r=1500000000;
        while(l<=r)
        {
            mid = (l+r)/2;
            x = summation(mid);
            if(x==n)
            {
                f=1;
                break;
            }
            if(x<n)
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(f)
            printf("%lld\n",mid);
        else
            printf("%lld\n",r);
    }

    return 0;
}
