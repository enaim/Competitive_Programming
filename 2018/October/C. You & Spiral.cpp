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

ll ar[1010][1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,j,r,c,cs,ce,rs,re,ks,sum;

    while(2==scanf("%lld%lld",&r,&c))
    {
        ks = 1;
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                scanf("%lld",&ar[i][j]);
        rs = 1;
        re = r;
        cs = 1;
        ce = c;
        sum = 0;
        while(ce>=cs && re>=rs)
        {
            if(ks%4==1)
            {
                rs++;
                if(rs<=re)
                    for(i=cs;i<=ce;i++)
                    sum+=ar[re][i];
                re--;
            }
            if(ks%4==2)
            {
                ce--;
                if(cs<=ce)
                for(i=rs;i<=re;i++)
                    sum+=ar[i][cs];
                cs++;
            }
            if(ks%4==3)
            {
                re--;
                if(rs<=re)
                for(i=cs;i<=ce;i++)
                    sum+=ar[rs][i];
                rs++;
            }
            if(ks%4==0)
            {
                cs++;
                if(cs<=ce)
                for(i=rs;i<=re;i++)
                    sum+=ar[i][ce];
                ce--;
            }
            ks++;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
