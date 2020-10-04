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


const int M = 1.5e7;

int mp[M+10];
int sz[M+10];
int ar[300010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,ans,g,i,j,x;
    while(scanf("%d",&n)==1)
    {
        for(i=2;i<=M;i++)
            if(!mp[i])
                for(j=i;j<=M;j+=i)
                    if(!mp[j])
                        mp[j] = i;

        for(g=0,i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            g =__gcd(g,ar[i]);
        }
        for(i=0;i<n;i++)
        {
            ar[i]/=g;
            for(x=ar[i];x>1;)
            {
                int p = mp[x];
                while(x%p==0)
                    x/=p;
                sz[p]++;
            }
        }

        ans = n;
        for(i=2;i<=M;i++)
            ans = min(ans,n-sz[i]);

        printf("%d\n",ans!=n ? ans : -1);
    }

    return 0;
}
