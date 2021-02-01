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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

vector<ll>vec[100010];
vector<ll>vec1;
ll ar[100010];
ll br[100010];
map<ll,ll>mp;
set<ll>st;
ll i,j,sz,n,cnt,cnt1,sum,x;

int main()
{
////    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%lld",&n))
    {
        st.clear();
        for(i=0;i<100010;i++)
            vec[i].clear();
        vec1.clear();
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            st.insert(ar[i]);
        }
        cnt = 1;
        for(auto it:st)
            mp[it]=cnt++;
        for(i=0;i<n;i++)
            br[i]=mp[ar[i]];
        for(i=0;i<n;i++)
            vec[br[i]].pb(i);
        sum = 0;
        cnt1 = 1;

        for(i=1;i<cnt;i++)
        {
            sz = vec[i].size();
            x = 0;
            cnt1 = 1;
            for(j=1;j<sz;j++)
            {
                if(vec[i][j]==vec[i][j-1]+1)
                {
                    cnt1++;
                    x = j;
                }
                else
                {
                    vec1.pb(cnt1);
                    cnt1=1;
                }
            }
            vec1.pb(cnt1);
        }
        sz = vec1.size();
        for(i=0;i<sz;i++)
        {
            x = vec1[i];
            sum+=((x*(x+1))/2LL);
        }
        printf("%lld\n",sum);
    }

    return 0;
}
