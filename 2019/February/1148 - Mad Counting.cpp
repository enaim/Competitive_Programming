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

set<int>st;
set<int>:: iterator it;
map<int,int>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,sum,i,n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        sum = 0;
        st.clear();
        mp.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            st.insert(x);
            mp[x]++;
        }
        for(it=st.begin();it!=st.end();it++)
        {
            x = mp[*it];
            for(i=1;i<=x;i+=(*it+1))
                sum+=(*it+1);
        }
        printf("Case %d: %d\n",ks++,sum);
    }

    return 0;
}
