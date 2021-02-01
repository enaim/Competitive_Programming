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
bool flag;


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
    flag = true;
    if(n<3)
    {
        flag = false;
        return;
    }
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

double Nails(Point ar[])
{
    ar[cnt]=ar[0];

    double ans = 0.0;
    for(int i=1;i<=cnt;i++)
    {
        ans += sqrt(sqr(ar[i-1].x-ar[i].x) + sqr(ar[i-1].y-ar[i].y));
    }
    return ans;
}

int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point ar[100];
    int tks;
    double k;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf%lld",&k,&n);
        for(int i=0;i<n;i++)
            ar[i].scan();

        ConvexHull(ar);

        double ans;
        if(flag)
            ans = Nails(ar);
        else
        {
            cnt = n;
            ans = Nails(ar);
        }

        if(abs(k-ans)<eps)
            printf("%.5lf\n",k);
        else if(k<ans)
            printf("%.5lf\n",ans);
        else
            printf("%.5lf\n",k);
    }

    return 0;
}

