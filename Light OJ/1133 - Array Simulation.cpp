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

    int tks,ks=1,i,n,d,x,y,m;
    int ar[110];
    char str[5];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='S')
            {
                scanf("%d",&d);
                for(i=0;i<n;i++)
                    ar[i]+=d;
            }
            if(str[0]=='M')
            {
                scanf("%d",&d);
                for(i=0;i<n;i++)
                    ar[i]*=d;
            }
            if(str[0]=='D')
            {
                scanf("%d",&d);
                for(i=0;i<n;i++)
                    ar[i]/=d;
            }
            if(str[0]=='R')
            {
                for(i=0;i<n/2;i++)
                    swap(ar[i],ar[n-1-i]);
            }
            if(str[0]=='P')
            {
                scanf("%d%d",&x,&y);
                swap(ar[x],ar[y]);
            }
        }
        printf("Case %d:\n",ks++);
        for(i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",ar[i]);
            else
                printf(" %d",ar[i]);
        }
        printf("\n");
    }

    return 0;
}
