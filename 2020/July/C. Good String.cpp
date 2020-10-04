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

char str[200010];
int n;

int pass(int a, int b)
{
    int i,cnt=0;
    int f = 0;
    for(i=0;i<n;i++)
    {
        int x = str[i]-'0';
        if(f==0 && x==a)
            f = 1;
        else if(f==1 && x==b)
        {
            cnt++;
            f = 0;
        }
    }
    return cnt*2;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[12];
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(ar,0,sizeof ar);
        int i,a,b,mx=0;
        for(i=0;i<10;i++)
            ar[i]=0;
        ssf(str);
        n = strlen(str);
        mx = 0;
        for(i=0;i<n;i++)
        {
            int x = str[i]-'0';
            ar[x]++;
            mx = max(ar[x],mx);
        }
        for(i=0;i<100;i++)
        {
            a = i/10;
            b = i%10;
            mx = max(mx,pass(a,b));
        }
        pf(n-mx);
    }

    return 0;
}
