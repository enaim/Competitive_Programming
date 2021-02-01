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

double cosA,AB,AC,BC,per1,per2;

double ThirdArm(double b,double c)
{
    double a = sqrt(sqr(c)+sqr(b)-(cosA*2*b*c));
    return a;
}

double Area(double AD)
{
    double area,AE,DE,per,s;
    per = AD/per1;
    AE = per*per2;
    DE = ThirdArm(AD,AE);
    s = (AD+AE+DE)/2.0;
    area = sqrt(s*(s-AD)*(s-DE)*(s-AE));
    return area;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        double d,A,s,per,TotalArea,UpperTArea,l,r,mid;
        scanf("%lf%lf%lf%lf",&AB,&AC,&BC,&d);
        cosA = (sqr(AB)+sqr(AC)-sqr(BC))/(2.0*AB*AC);
        s = (AB+BC+AC)/2.0;
        TotalArea = sqrt(s*(s-AB)*(s-BC)*(s-AC));
        per = TotalArea/(d+1);
        UpperTArea = per*d;
        per1 = AB/100.0;
        per2 = AC/100.0;

        l = 0;
        r = AB;
        int t = 100;
        while(t--)
        {
            mid = (l+r)/2;
            if(Area(mid)<UpperTArea)
                l = mid+.00000000000001;
            else
                r = mid-.00000000000001;
        }
        printf("Case %d: %.10lf\n",ks++,mid);;
    }

    return 0;
}
