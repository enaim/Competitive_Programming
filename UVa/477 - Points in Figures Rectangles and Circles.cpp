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
    char st;
    double a,b,c,d;
};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[2];
    int i,j,z,n;
    double x,y;
    coord ar[12];

    while(1==scanf("%s",str))
    {
        i=0;
        while(str[0] != '*')
        {
            if(str[0] == 'r')
            {
                i++;
                ar[i].st = str[0];
                scanf("%lf%lf%lf%lf",&ar[i].a,&ar[i].b,&ar[i].c,&ar[i].d);
            }
            else
            {
                i++;
                ar[i].st = str[0];
                scanf("%lf%lf%lf",&ar[i].a,&ar[i].b,&ar[i].c);
            }
            scanf("%s",str);
        }
        n = i;
        j = 0;
        scanf("%lf%lf",&x,&y);
        while(x!=9999.9 && y !=9999.9)
        {
            j++;
            z = 0;
            for(i=1;i<=n;i++)
            {
                if(ar[i].st == 'r')
                {
                    if(ar[i].a < x && ar[i].b > y && ar[i].c > x && ar[i].d < y)
                    {
                        printf("Point %d is contained in figure %d\n",j,i);
                        z = 1;
                    }
                }
                else
                {
                    if(sqrt(pow((ar[i].a-x),2) + pow((ar[i].b-y),2)) < ar[i].c)
                    {
                        printf("Point %d is contained in figure %d\n",j,i);
                        z = 1;
                    }
                }
            }
            if(z==0)
                printf("Point %d is not contained in any figure\n",j);
            scanf("%lf%lf",&x,&y);
        }
    }

    return 0;
}
