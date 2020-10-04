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

double l,r,mid,z,x,y,h;

double func(double w)
{
    double h1 = sqrt(sqr(x)-sqr(w));
    double h2 = sqrt(sqr(y)-sqr(w));
    return (h1*h2)/(h1+h2);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,t;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf",&x,&y,&h);
        l = 0;
        if(x<y)
            r = x;
        else
            r = y;
        t = 100;
        while(t--)
        {
            mid = (l+r)/2.0;
            z = func(mid);
            if(h>=z)
                r = mid;
            else
                l = mid;
        }
        printf("Case %d: %.10lf\n",ks++,mid);
    }

    return 0;
}
