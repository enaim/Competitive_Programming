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

int ar[200010];
int br[200010];
char str[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll a,b,x;
    int i,last,cnt,n;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%lld%lld",&n,&a,&b);
        scanf("%s",str);
        last = -1;
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='1')
                ar[i]=1,ar[i+1]=1;
        }
        last = 0;
        for(i=n;i>=0;i--)
        {
            br[i]=last;
            if(ar[i]==1)
                last = i,cnt++;
        }
        ll ans = 0;
        ans+=(n*a);
        n++;
        ans+=(n*b);
        if(cnt==0)
        {
            cout<<ans<<endl;
            continue;
        }
        ans+=(cnt*b);
        ans+=(2*a);
        for(i=last;i<=n;i++)
        {
            if(br[i]==i+1)
                continue;
            x = br[i]-i-1;
            if(br[i]==0)
                break;
            if(x*b>2*a)
            {
                i = br[i];
                ans+=(2*a);
            }
            else
            {
                i = br[i];
                ans+=(x*b);
            }
        }
        for(i=0;i<=n+5;i++)
            ar[i]=0,br[i]=0;
        cout<<ans<<endl;
    }

    return 0;
}
