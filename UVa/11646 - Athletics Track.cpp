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

template<class T> T sqr(T x){return x*x;}

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

double getAngleA(double a, double b, double c){
    return acos( (sqr(b)+sqr(c)-sqr(a))/2.0/b/c);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char c[20];
    string str,cr;
    stringstream ss;
    int x,y,ks=1;
    double r,d,k,cir,angle;
    while(gets(c))
    {
        stringstream ss;
        str = c;
        ss<<str;
        ss>>x>>cr>>y;

        r = sqrt(pow(x,2)+pow(y,2))/2.0;
        cir = 2 * pi * r;
        angle = getAngleA(y,r,r);
        d = (cir/(2*pi))*angle;
        k = 400/(2*x + 2*d);
        printf("Case %d: %.10lf %.10lf\n",ks++,k*x,k*y);
    }

    return 0;
}
