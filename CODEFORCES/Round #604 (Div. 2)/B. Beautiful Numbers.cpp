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

ll sum[200010];
ll ar[200010];
ll flag[200010];
ll ans[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll i,n,mx,mn;
        scanf("%lld",&n);
        sum[0]=0LL;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&ar[i]);
            flag[ar[i]]=i;
            sum[i] = ar[i]+sum[i-1];
        }

        for(i=1;i<=n;i++)
        {
            if(i==1)
            {
                mx = flag[i];
                mn = flag[i];
                if(sum[mx]-sum[mn-1]==(i*i+1)/2LL)
                    ans[i]=1;
                else
                    ans[i]=0;
                continue;
            }
            if(mx<flag[i])
                mx = flag[i];
            if(mn>flag[i])
                mn = flag[i];
            if(sum[mx]-sum[mn-1]==(i*(i+1LL))/2LL && (mx-mn+1)==i)
                ans[i]=1;
            else
                ans[i]=0;
        }
        for(i=1;i<=n;i++)
            printf("%lld",ans[i]);
        printf("\n");
    }

    return 0;
}
