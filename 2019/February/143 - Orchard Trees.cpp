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

struct point{
    double x,y;
};

double dis(point a,point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

double Area(point a,point b,point c)
{
    return .5*(abs(a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y));
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double area;
    int i,j,cnt;
    point a,b,c,t;
    while(6==scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y))
    {
        if(a.x==0 && a.y==0 && b.x==0 && b.y==0 && c.x==0 && c.y==0)
            break;
        cnt = 0;
        area = Area(a,b,c);
        if(area-0.0>eps)
        for(i=1;i<=99;i++)
            for(j=1;j<=99;j++)
            {
                t.x = i;
                t.y = j;
                if(abs(area-(Area(a,b,t)+Area(a,c,t)+Area(b,c,t)))<=eps)
                    cnt++;
            }
        else
        for(i=1;i<=99;i++)
            for(j=1;j<=99;j++)
            {
                t.x = i;
                t.y = j;
                if(abs(dis(a,b)-dis(a,t)-dis(t,b))<=eps)
                    cnt++;
                else if(abs(dis(a,c)-dis(a,t)-dis(t,c))<=eps)
                    cnt++;
                else if(abs(dis(b,c)-dis(b,t)-dis(t,c))<=eps)
                    cnt++;
            }

        printf("%4d\n",cnt);
    }

    return 0;
}
