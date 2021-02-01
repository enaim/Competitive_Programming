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

struct point
{
    int x,y;
};


bool eq(point a,point b)
{
    if(a.x == b.x && a.y == b.y)
        return true;
    return false;
}

bool ok(int a,int b,int c,int d)
{
    if(max(a,b) < min(c,d))
        return false;

    if(max(c,d) < min(a,b))
        return false;

    return true;
}


bool SameSnack(point a,point b,point c,point d)
{
    if(a.x==b.x && a.x == c.x && a.x == d.x)
        return ok(a.y,b.y,c.y,d.y);

    if(a.y==b.y && a.y == c.y && a.y == d.y)
        return ok(a.x,b.x,c.x,d.x);

    return eq(a,c) || eq(b,c)|| eq(a,d) || eq(b,d);
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1;
    point a,b,c,d;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

        if(SameSnack(a,b,c,d))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
