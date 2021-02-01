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

template<class T> T sqr(T x){return x*x;}

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

double A,B,temp;
double ab;
int cnt;

double getAngleA(double a, double b, double c){
    return acos((sqr(b)+sqr(c)-sqr(a))/2.0/b/c);
}

double redianToDegree(double rad){
    return rad*180.0/pi;
}

double Triangle(double mid)
{
    double h,x,y,k,ans;
    h = (mid*sin(A))/sin(pi/2);
    k = temp*mid;
    if(cos(A)<0)
    {
        x = mid*(cos(pi-A));
        y = cos(B)*k;
        ans = (h*(ab+ab+x-y))/2.0;
    }
    else if(cos(B)<0)
    {
        x = mid *cos(A);
        y  = k * (cos(pi-B));
        ans = (h*(ab+ab-x+y))/2.0;
    }
    else
    {
        x = cos(A)*mid;
        y = cos(B)*k;
        ans = (h*(ab+ab-x-y))/2.0;
    }

    return ans;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1;
    double s,area_of_trapezium,area_of_triangle,height_of_triangle,half,low,high,mid,ans,cd,ad,bc,a,b,c;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt = 0;
        scanf("%lf%lf%lf%lf",&ab,&cd,&ad,&bc);
        c = ab-cd;
        b = ad;
        a = bc;

        temp = (100.0/ad)/(100.0/bc);
        A = getAngleA(a,b,c);
        B = getAngleA(b,a,c);

        s = (a+b+c)/2.0;

        height_of_triangle = b * sin(A);
        area_of_trapezium = (height_of_triangle*(ab+cd))/2.0;
        half = area_of_trapezium/2.0;

        low = 0.0;
        high = ad;
        for(int i=0;i<100;i++)
        {
            mid = (low+high)/2.0;
            ans = Triangle(mid);

            if(ans < half)
                low = mid;
            else
                high = mid;
        }

        ans = mid*temp;
        printf("Land #%d: %.6lf %.6lf\n",ks++,mid,ans);
    }

    return 0;
}
