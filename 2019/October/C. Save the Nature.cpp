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

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

ll ar[200010];
ll sum[200010];
priority_queue<ll>pq;
ll i,n,a,b,x,y,ans,k,cnt1,cnt2,cnt3,temp1,temp2,temp3,sum1;

bool compare(ll a,ll b)
{
    return a>b;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            ar[i]=x;
        }
        scanf("%lld%lld",&x,&a);
        scanf("%lld%lld",&y,&b);
        scanf("%lld",&k);
        if(x<y)
        {
            swap(x,y);
            swap(a,b);
        }
        sort(&ar[1],&ar[n+1],compare);
        sum[0] = 0LL;
        for(i=1;i<=n;i++)
            sum[i] = ar[i] + sum[i-1];
        ans = -1LL;
        cnt1 = cnt2 = cnt3 = 0LL;
        for(i=1;i<=n;i++)
        {
            if(i%a==0LL && i%b==0LL)
                cnt1 = cnt1 +1LL;
            else if(i%a==0LL)
                cnt2 = cnt2 +1LL;
            else if(i%b==0LL)
                cnt3 = cnt3+1LL;

            temp1 = sum[cnt1];
            temp2 = sum[cnt1+cnt2]-sum[cnt1];
            temp3 = sum[cnt1+cnt2+cnt3]-sum[cnt1+cnt2];

            temp1 = (temp1/100LL)*(x+y);
            temp2 = (temp2/100LL)*(x);
            temp3 = (temp3/100LL)*(y);
            sum1 = temp1+temp2+temp3;
            if(sum1>=k)
            {
                ans = i;
                break;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
