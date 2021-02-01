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

Point pivot,br[110];
int cnt;


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

void ConvexHull(Point ar[],int n)
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
//    for(int i=0;i<cnt;i++)
//        ar[i].print();
}

double getArea(Point ar[],int n)
{
    ar[n]=ar[0];
    double ans = 0.0;
    for(int i=1;i<=n;i++)
        ans+=(double)CP(ar[i-1],ar[i]);

    return abs(ans)/2.0;
}

bool check_missile(Point ar[],double area,int temp)
{
    int i;
    double ans;
    for(i=0;i<temp;i++)
    {
        Point z  = br[i];
        ans = 0.0;
        for(int j=1;j<=cnt;j++)
        {
            Point X = MV(z,ar[j-1]);
            Point Y = MV(z,ar[j]);
            ans += (double)abs((CP(X,Y)))/2.0;
        }
        if(ans == area)
            return true;
    }

    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point ar[110][110];
    int temp,sz[110],i;
    double a,b;
    while(1==scanf("%d",&sz[0]))
    {
        int j=0;
        while(sz[j] != -1)
        {
            for(i=0;i<sz[j];i++)
                ar[j][i].scan();
            j++;
            scanf("%d",&sz[j]);
        }
        i = 0;
        while(scanf("%lf%lf",&a,&b)==2)
        {
            br[i].x = a;
            br[i].y = b;
            i++;
        }

        temp = i;

        double ans = 0.0;
        for(i=0;i<j;i++)
        {
            ConvexHull(ar[i],sz[i]);
            double area  = getArea(ar[i],cnt);
            if(check_missile(ar[i],area,temp))
                ans+=area;
        }
        printf("%.2lf\n",ans);
    }

    return 0;
}

