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

double func(double R,double r)
{
    double x;
    x = (2.0*(r+R)*(r+R))-(4.0*R*R);
    x = x/(2.0*(r+R)*(r+R));
    return x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double n,r,x,y,ans,l,f,mid,z;
    int t;
    while(2==scanf("%lf%lf",&n,&r))
    {
        l = 0;
        f = 10000;
        t = 10000;
        z = cos(2*pi/n);
        while(t--)
        {
            mid = (l+f)/2;
            x = func(mid,r);
            if(z<x)
                l = mid;
            else
                f = mid;
        }
        printf("%f\n",mid);
    }

    return 0;
}
