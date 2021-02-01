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

//#define LOG

#ifdef LOG
    #define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl
#else
    #define deb(a)
#endif


typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


double arr[3];


struct Point{
    double x,y;

    Point(int ax = 0, int ay = 0){
        x = ax;
        y = ay;
    }

    void print(string tag="")
    {
#ifdef LOG
        printf("%s #[%lf %lf] = %lf \n",tag.c_str(),x,y, sqrt(sqr(x) + sqr(y)));
#endif
    }

};

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

    void print(string tag="")
    {
#ifdef LOG
        printf("%s #[%lf %lf] Rad: %lf \n",tag.c_str(),cen.x,cen.y, rad);
#endif
    }
};


Cir circle[3];
Point tp,t1,t2;
Point Zero,yaxis(0.0,5.0);


Point Vector_Rotate(Point a,double angle)
{
    Point b;
    b.x = a.x*cos(angle)-a.y*sin(angle);
    b.y = a.x*sin(angle)+a.y*cos(angle);
    return b;
}

Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
double DP(Point a,Point b){return a.x*b.x+a.y*b.y;}
double CP(Point a,Point b){return a.x*b.y - a.y*b.x;}
double ABS(Point a){return sqrt(DP(a,a));}

Point Make(int i)
{
    if(i==1)
        return t1;
    else
        return t2;
}


Point MakeLVector(Point a, Point v,double l){
    double ab = ABS(v);
    return Point(a.x+((v.x/ab)*l),a.y+((v.y/ab)*l));
}

double length(Point a,Point b)
{
    return abs(DP(a,b))/ABS(a);
}


double dist(Point a,Point b)
{
    double X = a.x-b.x;
    double Y = a.y-b.y;
    return sqrt((X*X)+(Y*Y));
}


double Update(int i,Point a,double R,double r)
{
    Point temp,temp1;
    double h = R+r;
    double p = abs(R-r);
    if(r<R)
    {
        temp = Make(i);
        temp1 = MV(temp,a);
        temp1  = MakeLVector(temp,temp1,r);
    }
    else
    {
        temp = Make(i);
        temp1 = MV(temp,a);
        temp1  = MakeLVector(temp,temp1,R);
    }
    double land = sqrt((h*h)-(p*p));
    double distance = dist(tp,temp1) - land;

    return distance;
}


double vertical_distance()
{
    Point veca = (MV(Make(1),circle[2].cen));
    Point vecb = (MV(Make(1),Make(2)));
    return abs((CP(veca,vecb))/ABS(vecb));
}

double Minimum_Angle(Point veca,Point vecb)
{
    return acos((DP(veca,vecb)/(ABS(veca)*ABS(vecb))));
}

double Angle()
{
    Point veca = MV(Make(1),Make(2));
    Point vecb = MV(yaxis,Zero);
    return Minimum_Angle(veca,vecb);
}

double Hypo(double h,double angle)
{
    return h/sin(angle);
}


int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    freopen("in1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);

    double R;
    int tks,ks=1,i;
    double distance;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<3;i++)
            circle[i].takeInput();
        circle[0].print("Cir0");
        circle[1].print("Cir1");
        circle[2].print("Cir2");

        if(circle[1].rad < circle[0].rad)
        {
            swap(circle[0],circle[1]);
        }
        if(circle[1].cen.x<circle[0].cen.x)
        {
            double delx = circle[0].cen.x - circle[1].cen.x;
            circle[1].cen.x=delx+circle[0].cen.x;
            delx = circle[0].cen.x - circle[2].cen.x;
            circle[2].cen.x=delx+circle[0].cen.x;
        }


        circle[0].print("Cir0");
        circle[1].print("Cir1");
        circle[2].print("Cir2");
//        for(i=0;i<3;i++)
//            printf("x: %.2lf  y:%.2lf  r: %.2lf\n",circle[i].cen.x,circle[i].cen.y,circle[i].rad);

//        printf("\n\n");

        double hypo   = dist(circle[0].cen,circle[1].cen);
        double hs = hypo*hypo;
//        printf("hypo = %lf\n",hypo);
        double perpen = circle[1].rad - circle[0].rad;
        double ps = perpen*perpen;
//        printf("perpen = %lf\n",perpen);
        double land   = sqrt(hs - ps);
        double ls = land*land;
//        printf("land = %lf\n",land);
        double theta  = acos((hs+ls-ps)/(2.0*hypo*land));
        deb(theta);

        Point c1c2 = MV(circle[0].cen,circle[1].cen);
        c1c2.print("c1c2");

        Point c1d  = Vector_Rotate(c1c2,-theta);
        c1d.print("c1d");

        Point d    = MakeLVector(circle[0].cen,c1d,land);
        d.print("d");
//        printf("d.x = %lf\nd.y = %lf\n",d.x,d.y);
        Point dc1  = MV(d,circle[0].cen);
        Point c1t1 = Vector_Rotate(c1d,-(pi/2.0));
        Point c1t2 = Vector_Rotate(dc1,(pi/2.0));

        t1 = MakeLVector(circle[0].cen,c1t1,circle[0].rad);
        t1.print("t1");

//        Point z = MakeLVector(t1,MV(t1,circle[0].cen),5);
//        printf("x -> %lf   y -> %lf\n",z.x,z.y);
        t2 = MakeLVector(d,c1t2,circle[0].rad);
        t2.print("t2");
//        printf("t2.x = %lf\nt2.y = %lf\n",t2.x,t2.y);
//        z = MakeLVector(t2,MV(t2,circle[1].cen),7);

//        printf("x -> %lf   y -> %lf\n",z.x,z.y);

        double vd = vertical_distance();    // vertical distance
        deb(vd);
//            double vd = 64.49677524;
        double angle = Angle();             // angle with y axis
        deb(angle);
//            printf("angle -> %lf\n",angle);
        double K = Hypo(vd,angle);          // hypotenuse line to point
//            printf("K -> %lf\n",K);
        double H = Hypo(circle[2].rad,angle);      // hypotenuse line to cut partition
//            printf("H -> %lfx\n",H);
        double vm = K - H;                  // vertically movement (without cut partition)
//            printf("vm -> %lf\n",vm);
        tp.x = circle[2].cen.x;
        tp.y = circle[2].cen.y-vm;       //After Falling center
//        printf("%lf , %lf\n",tp.x,tp.y);

        double rev = 0.0;
        if(abs(t1.y-t2.y) < eps)
        {
            rev = 0.0;
        }
        else if(t1.y<t2.y)
        {
            distance = Update(1,circle[0].cen,circle[2].rad,circle[0].rad);
            rev = distance/(2*pi*circle[2].rad);
        }
        else if(t1.y>t2.y)
        {
            distance = Update(2,circle[1].cen,circle[2].rad,circle[1].rad);
            rev = distance/(2*pi*circle[2].rad);
        }

        double ans = vm + rev;

        printf("Case %d: %.10lf\n",ks++,ans);
    }

    return 0;
}
