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

    ll ar[10],ans[10],mn,i,ind;

    while(1==scanf("%lld",&ar[1]))
    {
        for(i=2;i<=9;i++)
            scanf("%lld",&ar[i]);
        ans[0] = ar[2]+ar[3]+ar[4]+ar[5]+ar[7]+ar[9];
        ans[1] = ar[2]+ar[3]+ar[4]+ar[6]+ar[7]+ar[8];
        ans[2] = ar[1]+ar[2]+ar[5]+ar[6]+ar[7]+ar[9];
        ans[3] = ar[1]+ar[2]+ar[4]+ar[6]+ar[8]+ar[9];
        ans[4] = ar[1]+ar[3]+ar[5]+ar[6]+ar[7]+ar[8];
        ans[5] = ar[1]+ar[3]+ar[4]+ar[5]+ar[8]+ar[9];
        mn = 1e18;
        for(i=0;i<6;i++)
            if(mn>ans[i])
            {
                ind = i;
                mn = ans[i];
            }

        if(ind==0)
            printf("BCG %lld\n",mn);
        if(ind==1)
            printf("BGC %lld\n",mn);
        if(ind==2)
            printf("CBG %lld\n",mn);
        if(ind==3)
            printf("CGB %lld\n",mn);
        if(ind==4)
            printf("GBC %lld\n",mn);
        if(ind==5)
            printf("GCB %lld\n",mn);
    }

    return 0;
}
