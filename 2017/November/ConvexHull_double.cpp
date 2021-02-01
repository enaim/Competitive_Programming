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

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){return a*a;}


struct Point{
    double x,y;

    Point(double ax = 0,double ay = 0){
        x = ax;
        y = ay;
    }

    void scan(){
        scanf("%lf%lf",&x,&y);
    }
    void print(){
    printf("%lf %lf\n",x,y);}
};

Point pivot;
int n,cnt;


Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
double CP(Point a,Point b){return a.x*b.y - a.y*b.x;}


double dist(Point a,Point b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}

bool compare(Point a,Point b)
{
    double c = CP(MV(pivot,a),MV(pivot,b));
    if(c && !(abs(c)<eps))   return c>0;
    return dist(pivot,a)<dist(pivot,b);
}

void ConvexHull(Point ar[])
{
    pivot = ar[0];
    for(int i=1;i<n;i++)
    {
        if(ar[i].y<pivot.y)
            pivot = ar[i];
        else if(abs(ar[i].y-pivot.y)<eps && pivot.x>ar[i].x)
            pivot = ar[i];
    }

    sort(&ar[0],&ar[n],compare);
    cnt = 2;
    for(int i=2;i<n;i++)
    {
        while(true)
        {
            double x  =  CP(MV(ar[cnt-2],ar[cnt-1]),MV(ar[cnt-2],ar[i]));
            if(!(abs(x)<eps) && x<0 && cnt>1)
                cnt--;
            else
                break;
        }
        ar[cnt++] = ar[i];
    }
    for(int i=0;i<cnt;i++)
        ar[i].print();
}

double getArea(Point ar[],int n)
{
    ar[n]=ar[0];
    double ans = 0.0;
    for(int i=1;i<=n;i++)
        ans+=(double)CP(ar[i-1],ar[i]);

    return abs(ans)/2.0;
}

int main()
{
    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point ar[100];
    while(1==scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            ar[i].scan();
        ConvexHull(ar);
//        double area  = getArea(ar,cnt);
    }

    return 0;
}

