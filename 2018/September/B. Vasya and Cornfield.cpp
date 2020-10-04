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

double area(int x1, int y1, int x2, int y2,
                        int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +
                x3 * (y1 - y2)) / 2.0);
}

bool check(int x1, int y1, int x2, int y2, int x3,int y3, int x4, int y4, int x, int y)
{
    double A = area(x1, y1, x2, y2, x3, y3) +
              area(x1, y1, x4, y4, x3, y3);

    double A1 = area(x, y, x1, y1, x2, y2);

    double A2 = area(x, y, x2, y2, x3, y3);

    double A3 = area(x, y, x3, y3, x4, y4);

    double A4 = area(x, y, x1, y1, x4, y4);

    return (A == A1 + A2 + A3 + A4);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double n,d,x,y;
    int m,i;

    while(scanf("%lf%lf%d",&n,&d,&m)==3)
    {
        for(i=0;i<m;i++)
        {
            scanf("%lf%lf",&x,&y);
            if(check(0,d,d,0,n,n-d,n-d,n,x,y))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
