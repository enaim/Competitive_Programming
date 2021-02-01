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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

struct Point{
    double x,y;

    Point(double ax = 0, double ay = 0){
        x = ax;
        y = ay;
    }

    void scan(){
        scanf("%lf%lf",&x,&y);
    }

    void print(string tag){
        printf("%s = [%lf %lf]",tag.c_str(),x,y);
    }
    void Add(Point p){
        x+=p.x;
        y+=p.y;
    }
};

Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
double DP(Point a,Point b){return a.x*b.x+a.y*b.y;}
double CP(Point a,Point b){return a.x*b.y - a.y*b.x;}
double ABS(Point a){return sqrt(DP(a,a));}
Point MakeLVector(Point v,double l){
    double ab = ABS(v);
    return Point(v.x/ab*l,v.y/ab*l);
}

Point add(Point a,Point b){return Point(a.x+b.x,a.y+b.y);}


Point getClosestPoint(Point a,Point b,Point p)
{
    if(0 > DP(MV(a,b),MV(a,p)) )
    {
        return a;
    }
    if(0 > DP(MV(b,a),MV(b,p)) )
    {
        return b;
    }

    double len = abs(DP(MV(a,b),MV(a,p)) / ABS(MV(a,b)));

    Point lAB = MakeLVector(MV(a,b),len);
    Point q = a;

    q.Add(lAB); //It is also answer.
    q = add(a,lAB);

    return q;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point a,b,p;
    a.scan();
    b.scan();
    p.scan();

    return 0;
}
