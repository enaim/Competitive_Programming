#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

ll check(ll a, ll b, ll c,ll d, ll val)
{
    return abs(val-a) + abs(val-b) + abs(val-c) + abs(val-d);
}

ll func(ll a, ll b, ll c,ll d)
{
    ll left = min(a,min(b,min(c,d)));
    ll right = max(a,max(b,max(c,d)));
    ll mid;
    ll mn = 1e18,x,y,temp1,temp2;
    while(left<=right)
    {
        mid = (left+right)/2LL;
        mn = min(mn,check(a,b,c,d,mid));
        x = (left + mid - 1)/2LL;
        x = max(x,1LL);
        y = (right + mid + 1)/2LL;
        y = max(y,1LL);
        temp1 = check(a,b,c,d,x);
        temp2 = check(a,b,c,d,y);
        mn = min(mn,min(temp1,temp2));
        if(temp1<=temp2)
            right = mid - 1LL;
        else
            left = mid + 1LL;
    }
    return mn;
}

ll ar[110][110];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n,m,i,j,a,b,c,d,sum=0LL;
        sl2(n,m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                sl(ar[i][j]);
        for(i=0;i<(n+1)/2;i++)
        {
            for(j=0;j<(m+1)/2;j++)
            {
                a = ar[i][j];
                b = ar[n-i-1][j];
                c = ar[i][m-j-1];
                d = ar[n-i-1][m-j-1];
                if(a==b && b==c && c==d)
                    sum += 0;
                else if(i==n-i-1 || j==m-j-1)
                    sum += func(a,b,c,d)/2LL;
                else
                    sum += func(a,b,c,d);
            }
        }
        pl(sum);
    }

    return 0;
}
