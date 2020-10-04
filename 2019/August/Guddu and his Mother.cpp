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
set<ll>st;
map<ll,ll>mp,mp1;
vector<ll>vec[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll tks,ks=1,x,y,cnt,i,n,j,sz,last,temp;
    scanf("%lld",&tks);
    while(tks--)
    {
        x = 0;
        y = 0;
        st.clear();
        mp.clear();
        mp1.clear();

        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            x^=ar[i];
            st.insert(x);
        }

        cnt = 0;
        for(auto it:st)
        {
            mp[it]=cnt++;
            mp1[cnt-1]=it;
        }
        y = cnt;

        if(mp1[0]==0)
            vec[0].pb(-1);

        x = 0;
        for(i=0;i<n;i++)
        {
            x^=ar[i];
            vec[mp[x]].pb(i);
        }

        x = cnt = 0;
        for(i=0;i<y;i++)
        {
            x = vec[i][0];
            sz = vec[i].size();
            temp = cnt;

            for(j=1;j<sz;j++)
                cnt+=(vec[i][j]-x-1);

            last = cnt-temp;
            for(j=1;j<sz-1;j++)
            {
                last = last - ((sz-j)*(vec[i][j]-x));
                last++;
                cnt+=last;
                x = vec[i][j];
            }
        }

        for(i=0;i<y;i++)
            vec[i].clear();

        printf("%lld\n",cnt);
    }

    return 0;
}
