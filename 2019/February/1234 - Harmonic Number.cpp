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
const double phi = 0.5772156649;

double ar[1000010];
double ans;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    ar[1]=1;
    for(i=2;i<=1e6;i++)
        ar[i]=ar[i-1]+(1.0/i);

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        if(n<=1e6)
            printf("Case %d: %.10f\n",ks++,ar[n]);
        else
        {
            ans = log(n+0.5)+phi;
            printf("Case %d: %.10f\n",ks++,ans);
        }
    }


    return 0;
}
