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

    int ar[1010];
    int tks,ks=1,l,i,mid,x,r,s,cnt,n,k,ind,mx;
    scanf("%d",&tks);
    while(tks--)
    {
        mx = 0;
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            mx = max(x,mx);
            ar[i]=x;
        }
        l = mx;
        r = OO;
        while(l<=r)
        {
            mid = (l+r)/2;
            cnt = s = 0;
            for(i=1;i<=n;i++)
            {
                s = s + ar[i];
                if(mid==s)
                {
                    ind = i;
                    s = 0;
                    cnt++;
                }
                else if(mid<s)
                {
                    ind = i-1;
                    cnt++;
                    s = ar[i];
                }
            }
            if(ind!=n)
                cnt++;
            if(cnt>k)
                l = mid+1;
            else
                r = mid-1;
        }
        printf("Case %d: %d\n",ks++,r+1);
    }

    return 0;
}
