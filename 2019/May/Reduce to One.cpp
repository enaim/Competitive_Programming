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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

ll ar[1000010];
int mod = 1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    ar[1]=1;
    ar[2]=5;
    for(i=3;i<=1e6;i++)
        ar[i] = (((i*ar[i-1])%mod) + i + ar[i-1])%mod;

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        printf("%lld\n",ar[n]);
    }

    return 0;
}
