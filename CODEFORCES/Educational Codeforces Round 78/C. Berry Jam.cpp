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

int ar[200010];
map<int,int>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,mx,sum;
        mp.clear();
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=n;i<2*n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<2*n;i++)
            if(ar[i]==2)
                ar[i]=-1;

        sum = 0;
        mx = 0;
        for(i=0;i<2*n;i++)
            sum+=ar[i];

        int mn = 2*n;
        int need = sum;
        if(need==0)
            mn = 0;

        sum = 0;
        for(i=n;i<2*n;i++)
        {
            sum += ar[i];
            if(mp[sum]==0)
                mp[sum]=i;
            if(need==sum)
                mn = min(mn,i-n+1);
        }

        sum = 0;
        for(i=n-1;i>=0;i--)
        {
            sum += ar[i];
            int x = need - sum;
            if(mp[x]!=0)
                mn = min(mn,mp[x]-i+1);
            if(need==sum)
                mn = min(mn,n-i);
        }

        printf("%d\n",mn);
    }

    return 0;
}
