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

ll ar[20];
ll i,j,per,n,m,cnt,sum,lcm;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
            scanf("%lld",&ar[i]);

        per = 1LL<<m;
        sum = 0;
        for(i=1;i<per;i++)
        {
            lcm = 1;
            cnt = 0;
            for(j=0;j<m;j++)
                if(i & 1LL<<j)
                    lcm = ((lcm*ar[j])/__gcd(lcm,ar[j])),cnt++;
            if(cnt & 1LL)
                sum += (n/lcm);
            else
                sum -= (n/lcm);
        }

        printf("Case %d: %d\n",ks++,n-sum);
    }

    return 0;
}
