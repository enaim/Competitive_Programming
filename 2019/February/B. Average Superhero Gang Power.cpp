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

ll n,k,m,x,i,t;
priority_queue<ll>pq;
double sum,mx,sum1;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(3==scanf("%lld%lld%lld",&n,&k,&m))
    {
        sum = 0.0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            sum+=(double)x;
            pq.push(-x);
        }
        t = n;
        mx = sum/n;
        for(i=1;i<=n && i<=m;i++)
        {
            if(m-i+1<=t*k)
                sum1 = sum+(double)(m-i+1);
            else
                sum1 = sum+(double)(t*k);
            mx = max(mx,sum1/t);
            ll top = pq.top();
            top = abs(top);
            pq.pop();
            sum-=(double)top;
            t--;
            if(m-i<=t*k)
                sum1 = sum+(double)(m-i);
            else
                sum1 = sum+(double)(t*k);
            mx = max(mx,sum1/t);
        }
        printf("%.15f\n",mx);
    }

    return 0;
}
