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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll a,b,cnt=0LL;
        scanf("%lld%lld",&a,&b);
        if(a==b)
        {
            printf("0\n");
            continue;
        }
        if(a>b)
            swap(a,b);
        while(a*8LL<=b)
        {
            a*=8LL;
            cnt++;
        }
        while(a*4LL<=b)
        {
            a*=4LL;
            cnt++;
        }
        while(a*2LL<=b)
        {
            a*=2LL;
            cnt++;
        }
        if(a==b)
            printf("%lld\n",cnt);
        else
            printf("-1\n");
    }

    return 0;
}