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

ll ar[200010];
ll br[200010];
ll i,j,n,oil,dis,ans;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%lld",&n))
    {
        for(i=0;i<n;i++)
            scanf("%lld%lld",&br[i],&ar[i]);

        for(i=0;i<n;i++)
            ar[n+i]=ar[i];
        for(i=0;i<n;i++)
            br[n+i]=br[i];

        i = j = dis = oil = 0;

        while(i<2*n && j<2*n)
        {
            if(dis+ar[j]<=oil+br[j])
            {
                oil+=br[j];
                dis+=ar[j];
                j++;
                if(j==i+n)
                {
                    ans = i;
                    break;
                }
            }
            else
            {
                if(i==j)
                {
                    i++;
                    j++;
                    dis=oil=0;
                    continue;
                }
                while(dis+ar[j]>oil+br[j])
                {
                    dis-=ar[i];
                    oil-=br[i];
                    i++;
                    if(i==j)
                    {
                        dis = 0;
                        oil = 0;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
