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

struct point{
    int x;
    double y;
};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,r,i,k;
    while(2==scanf("%d%d",&n,&r))
    {
        point ar[1010];
        for(i=0;i<n;i++)
            scanf("%d",&ar[i].x);

        for(i=0;i<n;i++)
        {
            k = i-1;
            ar[i].y = (double)r;
            while(k!=-1)
            {
                int l = abs(ar[k].x-ar[i].x);
                if(l<=2*r);
                {
                    double h = 2.0*r;
                    double p = sqrt((h*h) - ((double)l*l));
                    ar[i].y = max(ar[i].y,ar[k].y + p);
                    k--;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(i==0)
                printf("%.11lf",ar[i].y);
            else
                printf(" %.11lf",ar[i].y);
        }
        printf("\n");
    }


    return 0;
}
