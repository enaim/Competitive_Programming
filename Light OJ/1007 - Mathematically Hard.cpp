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

unsigned long long phi[5000010];

void Euler_totient_function()
{
     for(ll i=2;i<=5e6;i++)
        phi[i]=i;
     for(ll i=2;i<=5e6;i++)
     {
         if(phi[i]==i)
         {
             for(ll j=i;j<=5e6;j+=i)
                phi[j]=phi[j]/i * (i-1);
         }
     }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Euler_totient_function();

    for(ll i=2;i<=5e6;i++)
    {
        phi[i] = sqr(phi[i]);
        phi[i] = phi[i]+phi[i-1];
    }

    int tks,ks=1,l,r;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&l,&r);
        printf("Case %d: %llu\n",ks++,phi[r]-phi[l-1]);
    }

    return 0;
}
