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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n,k,i;
        scanf("%lld%lld",&n,&k);
        for(i=1;i<=n+5;i++)
        {
            if((i*(i+1))/2LL > k)
                break;
        }
        ll x = i-1;
        k = k - ((x*(x+1))/2LL);
        string ans = "";
        for(i=0;i<n;i++)
            ans+='a';
        if(k==0LL)
        {
            ans[n-x]='b';
            ans[n-x-1]='b';
            cout<<ans<<endl;
        }
        else
        {
            ans[n-k]='b';
            ans[n-x-2]='b';
            cout<<ans<<endl;
        }
    }

    return 0;
}
