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

ll ar[12];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,k,x;
    string str[12];
    string str1[12];
    str[0]="c";
    str[1]="o";
    str[2]="d";
    str[3]="e";
    str[4]="f";
    str[5]="o";
    str[6]="r";
    str[7]="c";
    str[8]="e";
    str[9]="s";
    for(i=0;i<10;i++)
        str1[i]=str[i];
    for(i=0;i<10;i++)
        ar[i]=1LL;

    while(1==scanf("%lld",&k))
    {
        ll ans = 1LL;
        for(i=0;ans<k;i++)
        {
            x = i%10LL;
            str[x]+=str1[x];
            ar[x]++;
            ans=1LL;
            for(ll j=0;j<10;j++)
                ans*=ar[j];
        }
        for(i=0;i<10;i++)
            cout<<str[i];
        printf("\n");
    }

    return 0;
}
