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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

double func(double r,double R)
{
    double x =(R-r)*(R-r);
    return (x-(2.0*r*r))/x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        double R,n,mid,l,r;
        scanf("%lf%lf",&R,&n);
        double cosA =cos((2.0*pi)/n);
        l = 0.00000001;
        r = 1000.00;
        int k = 1000;
        while(k--)
        {
            mid=(l+r)/2.0;
            if(cosA>func(mid,R))
                r = mid;
            else
                l = mid;
        }
        printf("Case %d: %.10lf\n",ks++,mid);
    }

    return 0;
}
