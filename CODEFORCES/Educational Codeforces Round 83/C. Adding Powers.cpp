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

int flag[110];
ll ar[35];
ll i,n,k,t,temp,p,sum,j;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,0,sizeof flag);
        sum = 0LL;
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            sum+=ar[i];
        }
        p = 1LL;
        for(i=1;i<100LL;i++)
        {
            if(p>1e16/k)
                break;
            p*=k;
        }
        temp = i-1;
        t = p;
        int f=1;
        for(i=0;i<n;i++)
        {
            if(ar[i]==0LL)
                continue;
            p = t;
            for(j=temp;j>=0;j--)
            {
                if(ar[i]>=p && flag[j]==0)
                {
                    flag[j]=1;
                    ar[i]-=p;
                    if(ar[i]==0LL)
                        break;
                }
                p/=k;
            }
            if(ar[i]!=0)
            {
                f = 0;
                break;
            }
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
