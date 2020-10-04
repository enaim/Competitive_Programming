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

struct coordinate{
    int x,y;
};


coordinate Vector(coordinate a,coordinate b)
{
    coordinate c;
    c.x = (b.x - a.x);
    c.y = (b.y - a.y);

    return c;
}


int Cross(coordinate A , coordinate B)
{
    return (A.x*B.y) - (A.y*B.x);
}


int main()
{
////    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,ans;
    coordinate a,b,c,d,A,B,C;
    printf("INTERSECTING LINES OUTPUT\n");
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

        A = Vector(a,b);
        B = Vector(c,d);
        C = Vector(a,d);
        ans = Cross(A,B);

        if( ans == 0 )
        {
            if(!Cross(A,C))
                printf("LINE\n");
            else
                printf("NONE\n");
        }
        else
        {
            double a1,b1,c1,a2,b2,c2;

            a1 = b.y - a.y;
            b1 = a.x - b.x;
            c1 = (a1*a.x)+(b1*a.y);
            a2 = d.y - c.y;
            b2 = c.x - d.x;
            c2 = (a2*c.x)+(b2*c.y);

            double x = ((b2*c1)-(b1*c2))/((a1*b2) - (a2*b1));
            double y = ((a1*c2)-(a2*c1))/((a1*b2) - (a2*b1));

            if(x == -0.00)
                x = fabs(x);
            if(y == -0.00)
                y = fabs(y);

            printf("POINT %.2lf %.2lf\n",x,y);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
