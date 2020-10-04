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
    long long x,y;

    Point(long long ax = 0,long long ay = 0){
        x = ax;
        y = ay;
    }

    void scan(){
        scanf("%lld%lld",&x,&y);
    }
    void print(){
        printf("%lld %lld\n",x,y);}
};

Point pivot;
long long n,cnt;


Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
long long CP(Point a,Point b){return a.x*b.y - a.y*b.x;}


long long dist(Point a,Point b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}

bool compare(Point a,Point b)
{
    long long x = CP(MV(pivot,a),MV(pivot,b));
    if(x)   return x>0;
    return dist(pivot,a)<dist(pivot,b);
}

void ConvexHull(Point ar[])
{
    pivot = ar[0];
    for(int i=1;i<n;i++)
    {
        if(ar[i].y<pivot.y)
            pivot = ar[i];
        else if(pivot.x>ar[i].x && ar[i].y==pivot.y)
            pivot = ar[i];
    }
    sort(&ar[0],&ar[n],compare);
    cnt = 2;
    for(int i=2;i<n;i++)
    {
        while(CP(MV(ar[cnt-2],ar[cnt-1]),MV(ar[cnt-2],ar[i]))<0 && cnt>1)   cnt--;
        ar[cnt++] = ar[i];
    }
//    for(int i=0;i<cnt;i++)
//        ar[i].print();
}

double getArea(Point ar[],int n)
{
    ar[n]=ar[0];
    double ans = 0.0;
    for(int i=1;i<=n;i++)
        ans+=(double)CP(ar[i-1],ar[i]);

    return abs(ans)/2;
}


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point ar[110];
    Point br[110];
    int ks=1;
    while(1==scanf("%lld",&n) && n)
    {
        printf("Tile #%d\n",ks++);
        for(int i=0;i<n;i++)
        {
            ar[i].scan();
            br[i] = ar[i];
        }
        ConvexHull(ar);
        double ans1 = getArea(ar,cnt);
        double ans2 = getArea(br,n);
        double ans = (100.00/ans1)*(ans1-ans2);
        printf("Wasted Space = %.2lf %\n\n",ans);
    }

    return 0;
}

