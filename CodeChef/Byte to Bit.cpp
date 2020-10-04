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

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll x,n,r,bit;
        scanf("%lld",&n);
        x = n/26;
        r = n%26;
        bit = pow(2,x);
        if(r==0)
        {
            bit = pow(2,x-1);
            printf("0 0 %lld\n",bit);
            continue;
        }
        if(r<=2)
        {
            printf("%lld 0 0\n",bit);
            continue;
        }
        if(r<=10)
        {
            printf("0 %lld 0\n",bit);
            continue;
        }
        printf("0 0 %lld\n",bit);
    }

    return 0;
}
