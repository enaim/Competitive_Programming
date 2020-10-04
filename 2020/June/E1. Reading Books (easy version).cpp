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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

vector<int>alice,bob,common;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,c,n,k,t,p,q,r,i;
    while(2==scanf("%d%d",&n,&k))
    {
        int ans = 0;
        alice.clear();
        bob.clear();
        common.clear();

        for(i=0;i<n;i++)
        {
            sf3(t,a,b);
            if(a+b==2)
                common.pb(t);
            else if(a==1)
                alice.pb(t);
            else if(b==1)
                bob.pb(t);
        }

        sort(alice.begin(),alice.end());
        sort(bob.begin(),bob.end());
        sort(common.begin(),common.end());

        int sz1 = alice.size();
        int sz2 = bob.size();
        int sz3 = common.size();

        if(sz1+sz3<k || sz2+sz3<k)
        {
            pf(-1);
            continue;
        }

        p = q = r = 0;
        for(i=0;i<k;i++)
        {
            a = b = c = OO;

            if(p<sz1)
                a = alice[p];
            if(q<sz2)
                b = bob[q];
            if(r<sz3)
                c = common[r];

            if(a != OO && b != OO && c != OO)
            {
                if(a+b<c)
                {
                    p++;
                    q++;
                    ans+=(a+b);
                }
                else
                {
                    r++;
                    ans+=c;
                }
            }
            else if(a == OO || b == OO)
            {
                r++;
                ans+=c;
            }
            else
            {
                p++;
                q++;
                ans+=(a+b);
            }
        }
        pf(ans);
    }

    return 0;
}
