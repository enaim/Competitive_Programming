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
    double x,y,z;

    Point(double ax = 0, double ay = 0,double az = 0){
        x = ax;
        y = ay;
        z = az;
    }
};

Point ar[30];

Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y,b.z-a.z);}
Point CP(Point a,Point b){return Point(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z,a.x*b.y - a.y*b.x);}
double DP(Point a,Point b){return a.x*b.x + a.y*b.y + a.z*b.z;}
double ABS(Point a){return sqrt(((a.x)*(a.x))+((a.y)*(a.y))+((a.z)*(a.z)));}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Point A,B,P,Q;
    int tks = 1,n,i,j,k,it,cnt1,cnt2;
    double sum;
    while(1==scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf",&ar[i].x,&ar[i].y,&ar[i].z);
        sum = 0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                A = MV(ar[i],ar[j]);
                for(k=j+1;k<n;k++)
                {
                    B = MV(ar[i],ar[k]);
                    P = CP(A,B);

                    cnt1 = cnt2 = 0;
                    for(it=0;it<n;it++)
                    {
                        if(it == i || it == j || it == k)
                            continue;
                        Q = MV(ar[i],ar[it]);
                        if(DP(P,Q) < 0)
                            cnt1++;
                        else
                            cnt2++;
                    }
                    if(cnt1 == n-3 || cnt2 == n-3)
                    {
                        sum+=ABS(CP(A,B))/2.0;
                    }
                }
            }

        printf("Case %d: %.2lf\n",tks++,sum);
    }

    return 0;
}
