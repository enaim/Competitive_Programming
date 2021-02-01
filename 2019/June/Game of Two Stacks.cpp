#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

ll ar[100010];
ll br[100010];
ll sum1[100010];
ll sum2[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,n,m,x,cnt1,cnt2;
    ll sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&n,&m,&x);
        sum1[0] = sum2[0] = ar[0] = br[0] = 0LL;
        for(i=1;i<=n;i++)
            scanf("%lld",&ar[i]),sum1[i] = sum1[i-1] + ar[i];
        for(i=1;i<=m;i++)
            scanf("%lld",&br[i]),sum2[i] = sum2[i-1] + br[i];

        cnt1 = cnt2 = 0;
        for(i=1;i<=n;i++)
        {
            if(sum1[i]>x)
                break;
            cnt1++;
        }
        for(i=1;i<=m;i++)
        {
            if(sum2[i]>x)
                break;
            cnt2++;
        }
        int mx = max(cnt1,cnt2);

        j = 0;
        sum = 0LL;
        for(i=cnt1;i>=1;i--)
        {
            while(j<=m && sum1[i]+br[j]+sum<=x)
                sum+=br[j],j++;
            mx = max(mx,i+j-1);
        }

        j = 0;
        sum = 0LL;
        for(i=cnt2;i>=1;i--)
        {
            while(j<=n && sum2[i]+ar[j]+sum<=x)
                sum+=ar[j],j++;
            mx = max(mx,i+j-1);
        }
        printf("%d\n",mx);
    }

    return 0;
}
