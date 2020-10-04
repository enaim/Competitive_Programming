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

    int i,x,n,mn,mx,indmx,indmn;
    while(1==scanf("%d",&n))
    {
        mx = 0,mn = 10000;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(mx<x)
                mx = x,indmx = i;
            if(mn>=x)
                mn = x,indmn = i;
        }
        if(indmx<=indmn)
            printf("%d\n",indmx-1 + n-indmn);
        else
            printf("%d\n",indmx-1 + n-indmn-1);
    }

    return 0;
}
