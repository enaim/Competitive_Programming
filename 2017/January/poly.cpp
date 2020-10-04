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

struct Point
{
    double x,y;
};

//Point MV(Point a,Point b){return Point(b.x-a.x,b.y-a.y);}
Point MV(Point a, Point b)
{
    Point ans;
    ans.x = b.x-a.x;
    ans.y = b.y-a.y;

    return ans;
}
double DP(Point a,Point b){return a.x*b.x+a.y*b.y;}
double MUL(Point a,Point b){return (sqrt(pow(a.x,2) + pow(a.y,2)))*(sqrt(pow(b.x,2) + pow(b.y,2)));}


int main()
{
    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i;
    double sum,ans;
    Point p[1010],temp,T,a,b;
    while(1==scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        scanf("%lf%lf",&T.x,&T.y);

        int x = 0;
        for(i=0;i<n;i++)
        {
            if(p[i].x == T.x || p[i].y == T.y)
            {
                printf("F\n");
                x = 1;
                break;
            }
        }
        if(x)
            continue;

        temp.x = p[0].x;
        temp.y = p[0].y;

        sum = 0;
        for(i=0;i<n-1;i++)
        {
            a = MV(T,p[i]);
            b = MV(T,p[i+1]);

            ans = acos((DP(a,b))/(MUL(a,b)));
//            printf("ans - > %lf\n",ans);
            sum += ans;
        }

            a = MV(T,p[i]);
            b = MV(T,temp);

            ans = acos((DP(a,b))/MUL(a,b));
//            printf("ans - > %lf\n",ans);
            sum += ans;
//            printf("sum - > %lf\n",sum);

            if(cos(sum) == cos(2*pi))
                printf("T\n");
            else
                printf("F\n");
    }

    return 0;
}
