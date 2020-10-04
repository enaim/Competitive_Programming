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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,x,n,m,i,t;
    int ar[1010];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d",&x);
        for(i=1;i<n;i++)
            scanf("%d",&ar[i]);
        i=1;
        if(x==-1)
        {
            while(i<n)
            {
                if(ar[i]==-1)
                    i++;
                else
                {
                    x = ar[i]-i;
                    while(x<0)
                        x+=m;
                    break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(i == n-1)
                printf("%d\n",x);
            else
                printf("%d ",x);
            x++;
            if(x==m)
                x=0;
        }
    }

    return 0;
}
