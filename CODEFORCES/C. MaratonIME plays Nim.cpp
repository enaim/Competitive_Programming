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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int a,b,x,y,i,f;
    int ks = 0;
    while(2==scanf("%d%d",&x,&y))
    {
        ks++;
        if(ks==1)
        {
            a = x;
            b = y;
        }
        else
        {
            if(x==1)
                a = a -  y;
            else
                b = b - y;
            x = a;
            y = b;
        }
        f = 0;
        for(i=20;i>=0;i--)
        {
            if(((a & (1<<i)) != 0) && ((b & (1<<i)) != 0))
                continue;
            if(((a & (1<<i)) == 0) && ((b & (1<<i)) == 0))
                continue;
            if(((a & (1<<i)) != 0) && f==0)
            {
                f = 1;
                a = (a ^ (1<<i));
            }
            else if(f==1)
            {
                f = 1;
                a = (a ^ (1<<i));
            }

            else if(((b & (1<<i)) != 0) && f==0)
            {
                f = 2;
                b = (b ^ (1<<i));
            }
            else if(f==2)
            {
                f = 2;
                b = (b ^ (1<<i));
            }
        }
        if(f==1)
            printf("1 %d\n",x-a);
        else
            printf("2 %d\n",y-b);
        fflush(stdout);
    }

    return 0;
}
