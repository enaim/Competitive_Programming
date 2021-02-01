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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    double x1,x2,x3,y1,y2,y3,x4,y4;

    while(8==scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4))
    {
        if(x1==x3 && y1==y3)
            printf("%.3lf %.3lf\n",x2+x4-x3,y2+y4-y3);
        else if(x1==x4 && y1==y4)
            printf("%.3lf %.3lf\n",x2+x3-x4,y2+y3-y4);
        else if(x2==x3 && y2==y3)
            printf("%.3lf %.3lf\n",x1+x4-x3,y1+y4-y3);
        else
            printf("%.3lf %.3lf\n",x1+x3-x4,y1+y3-y4);
    }

    return 0;
}
