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

ll i,j,mn,x,z,sum,ar[100010],n,s;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&n,&s))
    {
        mn = 1e18;
        sum = 0LL;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            mn = min(mn,x);
            sum+=x;
        }
        x = sum-(n*mn);
        if(x>=s)
            printf("%lld\n",mn);
        else
        {
            sum = sum-s;
            if(sum<0)
                printf("-1\n");
            else
            {
                mn = sum/n;
                printf("%lld\n",mn);
            }
        }
    }

    return 0;
}
