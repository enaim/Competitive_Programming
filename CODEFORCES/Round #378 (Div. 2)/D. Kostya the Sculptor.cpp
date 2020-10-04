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
typedef pair<int,int>pii;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int SIZE = 100010;

map<pii,int>mp,mx;
int mx2,o,p;

int smaller(int a,int b,int c)
{
    if(a <= b && a <= c)    return a;
    if(b <= a && b <= c)    return b;
    return c;
}


void go(int a,int b,int c,int i)
{
    int x,y,z;

    if(mp[pii(a,b)]>0)
    {
        x = smaller(a,b,c);
        y = smaller(a,b,mp[pii(a,b)]);
        z = smaller(a,b,c+mp[pii(a,b)]);

        if(mx2<z)
        {
            mx2 = z;
            o = mx[pii(a,b)];
            p = i;
        }
        if(y<x)
        {
            mp[pii(a,b)] = c;
            mx[pii(a,b)] = i;
        }
    }

    else
    {
        mp[pii(a,b)]=c;
        mx[pii(a,b)]=i;
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,mx1,n,ind,a,b,c;
    int ar[3];
    while(1==scanf("%d",&n))
    {
        mp.clear();
        mx.clear();
        mx1 = 0;
        mx2 = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&ar[0],&ar[1],&ar[2]);
            sort(&ar[0],&ar[3]);
            a = ar[0];  b = ar[1];  c = ar[2];
            go(a,b,c,i);
            go(a,c,b,i);
            go(b,c,a,i);

            if(mx1<a)
            {
                mx1 = a;
                ind = i;
            }
        }

        if(mx1>=mx2)
            printf("1\n%d\n",ind);
        else
            printf("2\n%d %d\n",o,p);
    }

    return 0;
}
