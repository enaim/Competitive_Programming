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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll s,x,n,m,ans;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&m);
        ans = 0LL;
        if(m%10==0 || n<m)
        {
            printf("0\n");
            continue;
        }
        if(m%5LL==0LL)
        {
            x = n/m;
            ans = (x/2LL)*5;
            if(x&1LL)
                ans+=5;
            printf("%lld\n",ans);
            continue;
        }
        if(m%2LL==1LL)
        {
            x = n/(m*10LL);
            ans += (x*45LL);
            s = x*(m*10LL);
            s+=m;
            while(s<=n)
            {
                ans+=(s%10LL);
                s+=m;
            }
        }
        else
        {
            x = n/(m*5LL);
            ans += (x*20LL);
            s = x*(m*5LL);
            s+=m;
            while(s<=n)
            {
                ans+=(s%10LL);
                s+=m;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
