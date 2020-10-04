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

struct node{
    double x,y,r;
};

double distance(double x1,double x2,double y1,double y2)
{
    return sqrt((sqr(x1-x2))+(sqr(y1-y2)));
}

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
    node a,b;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.r,&b.x,&b.y,&b.r);
        if(a.r<b.r)
            swap(a,b);
        double dis = distance(a.x,b.x,a.y,b.y);
        if(dis+b.r<=a.r)
            printf("%.6lf\n",(pi*a.r*a.r)-(pi*b.r*b.r));
        else if(abs(dis-(b.r+a.r))<=eps)
            printf("%.6lf\n",(pi*a.r*a.r)+(pi*b.r*b.r));
        else if(dis>a.r+b.r)
            printf("%.6lf\n",(pi*a.r*a.r)+(pi*b.r*b.r));
        else
        {
            double angle1 = Angle(b.r,a.r,dis);
            double arc_area1 = ((a.r*a.r)/2.0)*(2.0*angle1);
            double Tarea1 = .5*(a.r*a.r)*sin(2.0*angle1);
            double part1 = arc_area1 - Tarea1;

            double angle2 = Angle(a.r,b.r,dis);
            double arc_area2 = ((b.r*b.r)/2.0)*(2.0*angle2);
            double Tarea2 = .5*(b.r*b.r)*sin(2.0*angle2);
            double part2 = arc_area2 - Tarea2;

            double ans = (pi*a.r*a.r)+(pi*b.r*b.r) - (part1+part2);
            printf("%.6lf\n",ans);
        }
    }

    return 0;
}
