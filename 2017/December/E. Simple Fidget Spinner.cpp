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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;
typedef pair<int,int>pii;

//const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,q,k;
    double pi = 2*acos(0.0),a,b,r;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf",&r,&a,&b);
        double ca = pi*r*r;
        double x = 2.0*r*r;
        double z = (x-(b*b))/x;
        double angle = acos(z);
        double cut = (ca/(2*pi))*angle;
        double s = (r+r+b)/2.0;
        double temp = cut -  sqrt(s*(s-r) *(s-r)*(s-b));
        double ans = (ca*4) + (((a*b)-(temp*2))*3);
        printf("%.2lf\n",ans);
    }

    return 0;
}
