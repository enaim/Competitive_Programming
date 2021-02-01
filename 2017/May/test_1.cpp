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

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

struct point{
    int x,y;
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1;
    point a,b,c,d;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
        scanf("%d%d%d%d",&c.x,&c.y,&d.x,&d.y);

        bool x = false;

        if(a.y == b.y)
        {
            if(a.y == c.y && b.y == d.y)
            {
                if((a.x <= c.x && b.x >= c.x) || (a.x <= d.x && b.x >= d.x)
                   || (a.x >= c.x && b.x <= c.x) || (a.x >= d.x && b.x <= d.x))
                x = true;
            }
            else if((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y)
                    || (b.x == c.x && b.y == c.y) || (b.x == d.x && b.y == d.y))
                x = true;
        }
        else
        {
            if(a.x == c.x && b.x == d.x)
            {
                if((a.y >= c.y && b.y <= c.y) || (a.y >= d.y && b.y <= d.y)
                   || (a.y <= c.y && b.y >= c.y) || (a.y <= d.y && b.y >= d.y))
                    x = true;
            }
            else if((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y)
                    || (b.x == c.x && b.y == c.y) || (b.x == d.x && b.y == d.y))
                x = true;
        }

        if(x)
            printf("yes\n");
        else
            printf("no\n");
    }


    return 0;
}
