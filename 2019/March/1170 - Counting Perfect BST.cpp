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

const int MOD = 1e8 + 7;
const int MAX = 1200;

ll catalan[MAX];

void CATALAN() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<MAX; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

set<ll>st;
set<ll>::iterator it;
ll i,j,x,a,b,ans,ans1,ans2,l,r,mid,cnt;
ll ar[110000];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    CATALAN();
    catalan[0]=0;
    for(i=2;i<=1e5;i++)
    {
        x = i;
        while(x<=1e10/i)
        {
            x*=i;
            st.insert(x);
        }
    }
    cnt = 0;
    for(it = st.begin();it!=st.end();it++)
        ar[cnt++]=*it;

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&a,&b);

        l = 0;
        r = cnt-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(ar[mid]<a)
                l = mid+1;
            else
                r = mid-1;
        }
        ans1 = r+1;
        l = 0;
        r = cnt-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(ar[mid]>b)
                r = mid-1;
            else
                l = mid+1;
        }
        ans2 = l-1;
        ans = ans2 - ans1 + 1;

        printf("Case %d: %lld\n",ks++,catalan[ans]);
    }

    return 0;
}
