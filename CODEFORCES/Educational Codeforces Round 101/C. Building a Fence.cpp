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

int ar[200010];
int maxi[200010];
int mini[200010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,ind,mx,flag=0,k;
        sf2(n,k);
        mx = ind = -1;
        for(i=0;i<n;i++)
        {
            sf(ar[i]);
            if(ar[i]>mx)
            {
                mx = ar[i];
                ind = i;
            }
        }
        maxi[ind] = ar[ind]+k;
        mini[ind] = ar[ind];
        for(i=ind-1;i>=0;i--)
        {
            if(i==0)
            {
                if(mini[i+1]-k+1>ar[i] || maxi[i+1]-1<ar[i])
                {
                    flag = 1;
                    break;
                }
                continue;
            }
            if(mini[i+1]-k+1>ar[i]+k-1 || maxi[i+1]-1<ar[i])
            {
                flag = 1;
                break;
            }
            mini[i] = max(mini[i+1]-k+1,ar[i]);
            maxi[i] = min(maxi[i+1]-1+k,ar[i]+k-1+k);
        }
        if(flag)
        {
            puts("NO");
            continue;
        }
        for(i=ind+1;i<n;i++)
        {
            if(i==n-1)
            {
                if(mini[i-1]-k+1>ar[i] || maxi[i-1]-1<ar[i])
                {
                    flag = 1;
                    break;
                }
                continue;
            }
            if(mini[i-1]-k+1>ar[i]+k-1 || maxi[i-1]-1<ar[i])
            {
                flag = 1;
                break;
            }
            mini[i] = max(mini[i-1]-k+1,ar[i]);
            maxi[i] = min(maxi[i-1]-1+k,ar[i]+k-1+k);
        }
        if(flag)
        {
            puts("NO");
            continue;
        }
        puts("YES");
    }

    return 0;
}
