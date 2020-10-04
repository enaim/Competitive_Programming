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
    ll sum,l,r,o,t,z,x;
    while(tks--)
    {
        scanf("%lld%lld",&l,&r);
        if(l==r)
        {
            if(l%2==0)
                printf("%lld\n",l);
            else
                printf("-%lld\n",l);
            continue;
        }

        sum = 0;
        if(l%2==0)
        {
            sum += l;
            l++;
        }
        if(r%2==0)
        {
            sum += r;
            r--;
        }
        x = r-l+1;
        o = (x+1)/2;

        z  = o*((l+r)/2);

        t = ((r*(r+1))/2) - ((l*(l-1))/2);
        cout<<t+sum-z-z<<endl;
    }

    return 0;
}
