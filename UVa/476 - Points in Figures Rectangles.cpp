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


struct coord{
    double x1,y1,x2,y2;
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[2];
    coord ar[12];

    int i,n,k,z;
    double x,y;
    while(1==scanf("%s",str))
    {
        i = 0;
        while(str[0] == 'r')
        {
            i++;
            scanf("%lf%lf%lf%lf",&ar[i].x1,&ar[i].y1,&ar[i].x2,&ar[i].y2);
            scanf("%s",str);
        }
        n = i;
        scanf("%lf%lf",&x,&y);
        k=0;
        while(x != 9999.9 && y != 9999.9)
        {
            k++;
            z = 0;
            for(i=1;i<=n;i++)
            {
                if(ar[i].x1<x && ar[i].y1>y && ar[i].x2>x && ar[i].y2<y)
                {
                    printf("Point %d is contained in figure %d\n",k,i);
                    z = 1;
                }
            }
            if(z == 0)
                printf("Point %d is not contained in any figure\n",k);
            scanf("%lf%lf",&x,&y);
        }
    }

    return 0;
}
