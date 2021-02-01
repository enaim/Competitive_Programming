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

vector<ll>mi,pl,ze;
ll ar[200010],szm,szz,szp,ind,l,n,cnt;
int flag[200010];

void func()
{
    cnt = 0;
    int zzz = 1;
    if(szz)
    {
        zzz = 0;
        l = ze[0];
        flag[ze[0]]=1;
        for(int i=1;i<szz;i++)
        {
            printf("1 %lld %lld\n",l,ze[i]);
            l = ze[i];
            flag[ze[i]]=1;
            cnt++;
        }
        if(cnt<n-1 && szm%2!=0)
        {
            printf("1 %lld %lld\n",l,ind);
            cnt++;
            flag[ind]=1;
            if(cnt<n-1)
                printf("2 %lld\n",ind);
        }
        else
        {
            flag[l]=1;
            if(cnt<n-1)
                printf("2 %lld\n",l);
        }
    }
    if(zzz && szm%2!=0)
    {
        printf("2 %lld\n",ind);
        flag[ind]=1;
    }
    return;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,x,indi;
    while(1==scanf("%lld",&n))
    {
        cnt = 0;
        memset(flag,0,sizeof flag);
        ll mn = -1e18+10;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            if(x<0)
            {
                mi.pb(i);
                if(mn<x)
                {
                    mn = x;
                    ind = i;
                }
            }
            else if(x>0)
                pl.pb(i);
            else
                ze.pb(i);
            ar[i]=x;
        }
        szz = ze.size();
        szm = mi.size();
        szp = pl.size();
        func();
        ll last = n+10;
        indi = 1e10;
        for(i=1;i<=n;i++)
            if(flag[i]==0)
            {
                indi = i;
                break;
            }
        last = indi;
        for(i=indi+1;i<=n;i++)
        {
            if(flag[i]==0)
            {
                printf("1 %lld %lld\n",last,i);
                last = i;
            }
        }
    }

    return 0;
}
