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

struct node{
    ll x,y;
};

node ans[10];
ll ar[200010];

set<ll>st;
int main()
{
    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n,j;
        scanf("%lld",&n);
        ll cnt = 0,sum = 0LL,s = 0,z,i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            sum+=ar[i];
        }
        s = 0LL;
        for(i=0;i<n;i++)
        {
            st.clear();
            s +=ar[i];
            z = n-(i+1);
            ll f1 = i+1;
            if((f1*(f1+1LL))/2LL==s && (z*(z+1))/2LL==sum-s)
            {
                st.clear();
                for(j=0LL;j<=i;j++)
                    st.insert(ar[j]);
//                cout<<st.size()<<endl;

                if(!((long long)(st.size()) == f1 && f1!=0LL))
                    continue;

                st.clear();
                for(j=i+1;j<n;j++)
                    st.insert(ar[j]);
//                cout<<st.size()<<endl;

                if(!((long long)(st.size())== z && z!=0LL))
                    continue;


                ans[cnt].x = f1;
                ans[cnt].y = z;
                cnt++;
            }
        }
        printf("%lld\n",cnt);
        for(i=0;i<cnt;i++)
            printf("%lld %lld\n",ans[i].x,ans[i].y);
    }

    return 0;
}
