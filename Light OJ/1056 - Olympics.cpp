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

double getAngleA(double a, double b, double c){
    return acos( (sqr(b)+sqr(c)-sqr(a))/2.0/b/c);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[10];
    double x,y,r,d,k,cir,angle;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%s%lf",&x,str,&y);
        r = sqrt(pow(x,2)+pow(y,2))/2.0;
        cir = 2 * pi * r;
        angle = getAngleA(y,r,r);
        d = (cir/(2*pi))*angle;
        k = 400/(2*x + 2*d);
        printf("Case %d: %.10lf %.10lf\n",ks++,k*x,k*y);
    }

    return 0;
}
