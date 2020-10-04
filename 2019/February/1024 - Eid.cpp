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

string MUL(string a,long long b)
{
    long long carry=0,i,l;
    string habijabi="";
    l=a.size()-1;

    for(i=l;i>=0;i--)
    {
        carry += (a[i] - 48) * b;
        habijabi+= ( carry % 10 + 48 );
        carry /= 10;
    }

    while(carry)
    {
        habijabi += ( carry % 10 + 48 );
        carry /= 10;
    }
    reverse(habijabi.begin(),habijabi.end());

    return habijabi;
}


ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

set<ll>st;
set<ll>:: iterator it;
map<ll,ll>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll j,n,m,p,cnt;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        st.clear();
        scanf("%lld",&m);
        for(j=0;j<m;j++)
        {
            scanf("%lld",&n);
            for(int i=0;prime[i]*prime[i]<=n && i<25;i++)
            {
                cnt = 0LL;
                p = prime[i];
                while(n%p==0)
                {
                    n/=p;
                    cnt++;
                }
                if(cnt)
                {
                    st.insert(p);
                    mp[p]=max(cnt,mp[p]);
                }
            }
            if(n!=1)
            {
                st.insert(n);
                mp[n]=max(1LL,mp[n]);
            }
        }
        string a="1";
        for(it=st.begin();it!=st.end();it++)
        {
            for(int i=0;i<mp[*it];i++)
                a = MUL(a,*it);
        }

        printf("Case %d: %s\n",ks++,a.c_str());
    }

    return 0;
}
