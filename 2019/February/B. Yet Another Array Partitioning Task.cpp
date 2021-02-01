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

ll n,m,k,i,z,sum,cnt;
set<ll>st;

struct node{
    ll v,ind;
};

node ar[200010];

bool compare(node a,node b)
{
    return a.v<b.v;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(3==scanf("%lld%lld%lld",&n,&m,&k))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i].v);
            ar[i].ind=i;

        }
        sort(&ar[0],&ar[n],compare);
        z = m*k;
        for(i=n-1;i>=0 && z>=1;i--,z--)
        {
            sum+=ar[i].v;
            st.insert(ar[i].ind);
        }
        z=0;
        cnt = 0;
        printf("%lld\n",sum);
        for(auto it:st)
        {
            z++;
            if(z%m==0)
            {
                printf("%d ",it+1);
                cnt++;
                if(cnt==k-1)
                    break;
            }
        }
    }

    return 0;
}
