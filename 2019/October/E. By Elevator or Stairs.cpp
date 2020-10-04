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

int flag[200010];
ll pre[200010];
ll ar[200010];
ll br[200010];
ll ans[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll c;
    int i,n;
    scanf("%d%lld",&n,&c);

    for(i=2;i<=n;i++)
        scanf("%lld",&ar[i]);
    for(i=2;i<=n;i++)
        scanf("%lld",&br[i]);

    flag[1]=1;
    ans[1]=0;
    for(i=2;i<=n;i++)
    {
        if(flag[i-1]==1)
        {
            if((i>2) && (pre[i-1]+br[i]<=ans[i-1]+ar[i]) && (pre[i-1]+br[i]<=ans[i-1]+br[i]+c))
            {
                flag[i]=2;
                ans[i]=pre[i-1]+br[i];
                pre[i]=pre[i-1]+br[i];
            }
            else if(ans[i-1]+ar[i]<ans[i-1]+br[i]+c)
            {
                flag[i]=1;
                ans[i]=ans[i-1]+ar[i];
                if(i==2)
                    pre[i]=ans[i-1]+br[i]+c;
                else
                    pre[i]= min(pre[i-1]+br[i],ans[i-1]+br[i]+c);
            }
            else
            {
                flag[i]=2;
                ans[i]=ans[i-1]+br[i]+c;
                pre[i]=ans[i-1]+br[i]+c;
            }
        }
        else
        {
            if(ans[i-1]+br[i]<=ans[i-1]+ar[i])
            {
                flag[i]=2;
                ans[i]=ans[i-1]+br[i];
                pre[i]=ans[i];
            }
            else
            {
                flag[i]=1;
                ans[i]=ans[i-1]+ar[i];
                pre[i]=pre[i-1]+br[i];
            }
        }
    }
    for(i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    printf("\n");

    return 0;
}
