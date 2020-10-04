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

    ll n,i,j,cnt,cnt1,ans;
    char str[200010];
    while(1==scanf("%lld",&n))
    {
        cnt=cnt1=0;
        scanf("%s",str);
        if(str[0]==str[n-1])
        {
            for(i=0;i<n;i++)
                if(str[i]==str[0])
                    cnt++;
                else
                    break;
            for(j=n-1;j>0;j--)
                if(str[j]==str[0])
                    cnt1++;
                else
                    break;
            ans = (cnt+cnt1)+(cnt*cnt1)+1;
            ans%=998244353;
            cout<<ans<<endl;
        }
        else
        {
            for(i=0;i<n;i++)
                if(str[i]==str[0])
                    cnt++;
                else
                    break;
            for(j=n-1;j>0;j--)
                if(str[j]==str[n-1])
                    cnt1++;
                else
                    break;
            cout<<cnt+cnt1+1<<endl;
        }
    }

    return 0;
}
