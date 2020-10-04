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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int ar[100010];
int flag[100010];
int ans[100010];
int f[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,last;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<100010;i++)
            ans[i]=-1;
        for(i=0;i<n;i++)
            sf(ar[i]);

        int cnt = 0;
        for(i=0;i<n;i++)
            if(ar[i]==0)
                cnt++;

        if(cnt==n)
        {
            for(i=0;i<n;i++)
                printf("1 ");
            nn;
            return 0;
        }
        last = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]>ar[last])
            {
                ans[i]=ar[last];
                f[ar[last]]=1;
                last = i;
            }
        }
        f[ar[n-1]]=1;

        int mn = 0;
        for(i=0;i<n;i++)
        {
            while(f[mn]!=0)
                mn++;
            if(ans[i]==-1)
            {
                ans[i]=mn;
                f[mn]=1;
            }
            while(f[mn]!=0)
                mn++;
            if(ar[i]>mn)
                break;
        }
        if(i!=n)
        {
            pf(-1);
            return 0;
        }
        for(i=0;i<n;i++)
            printf("%d ",ans[i]);
        nn;
    }

    return 0;
}
