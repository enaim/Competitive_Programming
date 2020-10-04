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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll sum = 0,k;
        int i,n;
        scanf("%d%lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i+1]);
        ll mx = -OO;
        int ind = 0,ans = 0;
        int f = 0;
        for(i=1;i<=n;i++)
        {
            sum+=ar[i];
            if(mx<ar[i])
            {
                mx = ar[i];
                ind = i;
            }
            if(sum>k && f==0)
            {
                if(i==1)
                {
                    f = 1;
                    sum = 0;
                    ans = 1;
                    continue;
                }
                if(sum-mx<=k)
                {
                    f = 1;
                    sum -= mx;
                    ans = ind;
                    continue;
                }
                else
                    break;
            }
            if(sum>k && f==1)
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
