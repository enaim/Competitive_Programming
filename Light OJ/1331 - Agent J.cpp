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

double Angle(double a,double b,double c)
{
    return acos((sqr(b)+sqr(c)-sqr(a))/(2*b*c));
}

double AreaOfTriangle(double a,double b,double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double AreaOfPartition(double r,double angle)
{
    return ((pi*sqr(r)/(2*pi)))*angle;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double r1,r2,r3,a,b,c,A,B,C,angleA,angleB,angleC,area;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a = r1+r2;
        b = r1+r3;
        c = r2+r3;
        area = AreaOfTriangle(a,b,c);
        angleA = Angle(a,b,c);
        angleB = Angle(b,a,c);
        angleC = Angle(c,a,b);
        A = AreaOfPartition(r1,angleC);
        B = AreaOfPartition(r2,angleB);
        C = AreaOfPartition(r3,angleA);
        printf("Case %d: %.10lf\n",ks++,area-(A+B+C));
    }

    return 0;
}
