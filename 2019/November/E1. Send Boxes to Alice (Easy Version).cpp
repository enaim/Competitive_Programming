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
ll br[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,k,x,ans,sum,n,j;
    while(1==scanf("%lld",&n))
    {
        vector<ll>vec;
        sum = ans = 0;
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]),sum+=ar[i],br[i]=ar[i];
        if(sum<=1)
        {
            printf("-1\n");
            continue;
        }
        for(i=2;i<=sum;i++)
        {
            if(sum%i==0)
                vec.pb(i);
        }
        ll sz = vec.size();
        ll mn = 1e18;
        for(int l=0;l<sz;l++)
        {
            k = vec[l];
            for(i=0;i<n;i++)
                ar[i]=br[i];
            ans = sum = 0;
            for(i=0;i<n;i++)
            {
                if(ar[i]%k==0)
                    continue;
                if(i==n-1)
                    break;
                x = k-ar[i];
                if(x>=ar[i])
                {
                    ans+=ar[i];
                    ar[i+1]+=ar[i];
                }
                else
                {
                    int temp = x;
                    sum = 0;
                    for(j=i+1;j<n;j++)
                    {
                        if(ar[j]==1)
                        {
                           sum+=(j-i);
                           temp--;
                        }
                        if(temp==0)
                            break;
                    }
                    ans+=sum;
                    i = j;
                }
            }
            mn = min(ans,mn);
        }

        printf("%lld\n",mn);
    }

    return 0;
}
