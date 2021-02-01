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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    ll l,n,x,y,d,ans,z,zz;
    while(tks--)
    {
        cin>>n>>x>>y>>d;
        z = x-1;
        zz = n-x;
        z = z/d+1;
        zz = zz/d+1;
        ans = OO;
        l = abs(y-x);
        if(abs(y-1)%d==0)
            ans = z+(abs(y-1)/d);
        if(abs(n-y)%d==0)
            ans = min(ans,zz+(abs(n-y)/d));
        if(l%d==0)
            cout<<l/d<<endl;
        else if(ans!=OO)
            cout<<ans<<endl;
        else
            printf("-1\n");
    }

    return 0;
}
