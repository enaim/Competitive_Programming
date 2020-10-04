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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,m,i,j,cnt,pos,sum,mn,mx;

    while(2==scanf("%lld%lld",&n,&m))
    {
        sum = 0;
        mn = OO;
        mx = -OO;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            mn = min(mn,ar[i]);
            mx = max(mx,ar[i]);
            sum+=ar[i];
        }
        sort(&ar[0],&ar[n]);
        j = 0;
        cnt = 0;
        pos = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]>pos)
            {
                pos++;
                cnt++;
            }
            else
                cnt++;
        }
        if(pos<mx)
            printf("%lld\n",sum-(cnt+mx-pos));
        else if(pos==mx)
            printf("%lld\n",sum-cnt);
    }

    return 0;
}
