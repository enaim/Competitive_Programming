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

int dp[110][110][110][2];
int ar[110],n;

int go(int pos,int odd,int even,int prev)
{
    if(pos==n+1)
        return 0;

    int &re = dp[pos][odd][even][prev];

    if(re!=-1)
        return re;

    re = OO;

    if(ar[pos]!=0)
    {
        if(ar[pos]%2==0 && prev%2==0)
            re = min(re,go(pos+1,odd,even,ar[pos]));
        else if(ar[pos]%2==1 && prev%2==1)
            re = min(re,go(pos+1,odd,even,ar[pos]));
        else
            re = min(re,go(pos+1,odd,even,ar[pos])+1);
    }

    else
    {
        if(prev%2==0)
        {
            if(even)
                re = min(re,go(pos+1,odd,even-1,2));
            if(odd)
                re = min(re,go(pos+1,odd-1,even,1) + 1);
        }
        else
        {
            if(odd)
                re = min(re,go(pos+1,odd-1,even,1));
            if(even)
                re = min(re,go(pos+1,odd,even-1,2) + 1);
        }
    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x;
    while(1==scanf("%d",&n))
    {
        int odd = (n+1)/2;
        int even = n/2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x==0)
                ar[i]=0;
            else if(x%2==1)
                ar[i]=1,odd--;
            else
                ar[i]=2,even--;
        }

        memset(dp,-1,sizeof dp);
        int ans1 = go(1,odd,even,0);
        memset(dp,-1,sizeof dp);
        int ans2 = go(1,odd,even,1);

        printf("%d\n",min(ans1,ans2));
    }

    return 0;
}
