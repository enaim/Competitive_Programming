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

double Angle(double a,double b,double c)
{
    return acos((sqr(b)+sqr(c)-sqr(a))/(2*b*c));
}

double AreaOfTriangle(double a,double b,double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    double a,b,c,d,angle,area,r1,r2,r,R,h,p,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        a = r1-r2;
        b = sqrt(sqr(a)+sqr(h));
        angle = Angle(a,h,b);
        c = tan(angle)*p;
        r = r2;
        R = r2+c;
        ans = ((pi*p)/3.0)*(sqr(R)+(R*r)+sqr(r));
        printf("Case %d: %.10lf\n",ks++,ans);
    }

    return 0;
}
