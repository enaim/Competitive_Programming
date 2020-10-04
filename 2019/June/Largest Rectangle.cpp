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
ll i,ans,n,j,l;
vector<ll>vec[1000010];
set<ll>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%lld",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]),st.insert(-ar[i]);
            vec[ar[i]].pb(i);
        }

        ans = 0;
        for(auto it : st)
        {
            it  = abs(it);
            l = -1;
            for(i=0;i<vec[it].size();i++)
            {
                int cnt = 0;
                for(j=vec[it][i];j>l;j--)
                {
                    if(ar[j]>=it)
                        cnt++;
                    else
                        break;
                }
                for(j=vec[it][i]+1;j<n;j++)
                {
                    if(ar[j]>=it)
                        cnt++;
                    else
                        break;
                }
                l = j-1;
                ans = max(ans,cnt*it);
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
