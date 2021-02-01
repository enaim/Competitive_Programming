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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

int two[1000010];
int five[1000010];

void func()
{
    int i,a,b,x;
    two[0]=0;
    two[1]=0;
    five[0]=0;
    five[1]=0;
    for(i=1;i<=1e6;i++)
    {
        a = i;
        b = i;
        x = 2;
        while(a>=x)
        {
            two[i]+=(a/x);
            x*=2;
        }
        x = 5;
        while(b>=x)
        {
            five[i]+=(b/x);
            x*=5;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    func();

    int tks,ks=1,a,b,f,n,r,p,q,t,x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&n,&r,&p,&q);

        x4 = 0;
        y4 = p;
        while(p%2==0)
        {
            p/=2;
            x4++;
        }
        p = y4;
        y4 = 0;
        while(p%5==0)
        {
            y4++;
            p/=5;
        }

        a = r;
        b = n-r;
        x1 = two[n];
        y1 = five[n];
        x2 = two[a];
        y2 = five[a];
        x3 = two[b];
        y3 = five[b];
        x4 = x4*q;
        y4 = y4*q;

        t = x1-(x2+x3)+x4;
        f = y1-(y2+y3)+y4;

        printf("Case %d: %d\n",ks++,min(t,f));
    }


    return 0;
}
