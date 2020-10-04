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

#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

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
};

Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
double DP(Point a,Point b){return a.x*b.x+a.y*b.y;}
double CP(Point a,Point b){return a.x*b.y - a.y*b.x;}
double ABS(Point a){return sqrt(DP(a,a));}

struct Cir{
    Point cen;
    double rad;

    Cir()
    {

    }

    Cir(Point p, double r)
    {
        cen = p;
        rad = r;
    }

    void takeInput()
    {
        scanf("%lf%lf%lf",&cen.x,&cen.y,&rad);
    }
};

Cir circle[3];
Point tp,t1,t2;
Point Zero,yaxis(0.0,5.0);

Point Vector_Rotation(Point a,double angle)
{
    Point b;
    b.x = a.x*cos(angle)-a.y*sin(angle);
    b.y = a.x*sin(angle)+a.y*cos(angle);
    return b;
}

Point MakeLVector(Point a, Point v, double l){
    double ab = ABS(v);
    return Point( a.x+((v.x/ab)*l) ,a.y+((v.y/ab)*l) );
}

double vertical_distance()
{
    Point veca = (MV(t1,circle[2].cen));
    Point vecb = (MV(t1,t2));
    return abs((CP(veca,vecb))/ABS(vecb));
}

double Minimum_Angle(Point veca,Point vecb)
{
    return acos((DP(veca,vecb)/(ABS(veca)*ABS(vecb))));
}

double Angle()
{
    Point veca = MV(t1,t2);
    Point vecb = MV(yaxis,Zero);
    return Minimum_Angle(veca,vecb);
}

double Hypo(double h,double angle)
{
    return h/sin(angle);
}

double dist(Point a,Point b)
{
    double X = a.x-b.x;
    double Y = a.y-b.y;
    return sqrt((X*X)+(Y*Y));
}

double Update(Point touchPoint,Point a,double R,double r)
{
    Point temp,temp1;
    double h = R+r;
    double p = abs(R-r);

    temp = touchPoint;
    temp1 = MV(temp,a);
    temp1  = MakeLVector(temp,temp1,R);

    double land = sqrt((h*h)-(p*p));
    double distance = dist(tp,temp1) - land;

    return distance;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i;
    double distance;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<3;i++)
            circle[i].takeInput();

        if(circle[1].rad < circle[0].rad)            // Make sure that 1st is smaller radius and vice versa
        {
            swap(circle[0],circle[1]);
        }
        if(circle[1].cen.x<circle[0].cen.x)          //If 2th circle situated on the left side of 1st circle then
        {                                            //take 2th and 3rd circle on right side of 1st circle ( produce mirror circle )
            double delx = circle[0].cen.x - circle[1].cen.x;
            circle[1].cen.x=delx+circle[0].cen.x;
            delx = circle[0].cen.x - circle[2].cen.x;
            circle[2].cen.x=delx+circle[0].cen.x;
        }

        double hypo   = dist(circle[0].cen,circle[1].cen); // distance between 1st and 2th circle center
        double hs = hypo*hypo;
        double perpen = circle[1].rad - circle[0].rad;     // difference between 1st and 2th circle radius
        double ps = perpen*perpen;
        double land   = sqrt(hs - ps);
        double ls = land*land;

        double theta  = acos((hs+ls-ps)/(2.0*hypo*land));
        //        theta = acos(land/hypo);
        Point c1c2 = MV(circle[0].cen,circle[1].cen);
        Point c1d  = Vector_Rotation(c1c2,-theta);
        Point d    = MakeLVector(circle[0].cen,c1d,land);
        Point dc1  = MV(d,circle[0].cen);
        Point c1t1 = Vector_Rotation(c1d,-(pi/2.0));
        Point dt2 = Vector_Rotation(dc1,(pi/2.0));

        t1 = MakeLVector(circle[0].cen,c1t1,circle[0].rad); //left coordinate of tangent
        t2 = MakeLVector(d,dt2,circle[0].rad);

        double vd = vertical_distance();            // vertical distance between point to tangent
        double angle = Angle();                     // angle between tangent and y axis
        double K = Hypo(vd,angle);                  // distance between point to tangent along y axis
        double H = Hypo(circle[2].rad,angle);       // distance between tangent and 3rd circle after falling center along y axis
        double vm = K - H;                          // vertically movement (without cut partition)

        tp.x = circle[2].cen.x;                     //3rd circle center when it touches the line
        tp.y = circle[2].cen.y-vm;

        double rev;
        if(abs(t1.y-t2.y) < eps)
        {
            rev = 0.0;
        }
        else if(t1.y<t2.y)
        {
            distance = Update(t1,circle[0].cen,circle[2].rad,circle[0].rad);
            rev = distance/(2*pi*circle[2].rad);
        }
        else if(t1.y>t2.y)
        {
            distance = Update(t2,circle[1].cen,circle[2].rad,circle[1].rad);
            rev = distance/(2*pi*circle[2].rad);
        }

        double ans = vm + rev;

        printf("Case %d: %.10lf\n",ks++,ans);
    }

    return 0;
}
