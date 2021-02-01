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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

    ll n,l,r,a,b;
    while(1==scanf("%lld",&n))
    {
        if(2LL<=n && n<=9LL)
        {
            printf("Stan wins.\n");
            continue;
        }
        a = n-1LL;
        b = (n+8LL)/9LL;
        l = min(a,b);
        r = max(a,b);
        int f = 0;
        int ans;
        while(true)
        {
            if(f==0)
            {
                a = (min(l,r)+1LL)/2LL;
                b = max(l,r)/9LL;
                l = min(a,b);
                r = max(a,b);
                if((2LL<=l && l<=9LL) || (2LL<=r && r<=9LL))
                {
                    ans = 1;
                    break;
                }
                if(r<=1LL)
                {
                    ans = 0;
                    break;
                }
            }
            if(f==1)
            {
                a = (min(l,r)+8)/9LL;
                b = max(l,r)/2LL;
                l = min(a,b);
                r = max(a,b);
            }

            f = !f;
        }
        if(ans)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }

    return 0;
}
