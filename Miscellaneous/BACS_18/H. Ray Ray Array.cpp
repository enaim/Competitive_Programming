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
    ll p,n,i,ar[1010],q,x,y;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%lld",&ar[i]);
        while(q--)
        {
            scanf("%lld%lld%lld",&p,&x,&y);

            for(i=1;i<=n;i++)
            {
                if(p==1)
                {
                    if(ar[i]<=x)
                        ar[i]= ar[i]-y;
                }
                else
                {
                    if(ar[i]>=x)
                        ar[i]+=y;
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            if(i==1)
                printf("%lld",ar[i]);
            else
                printf(" %lld",ar[i]);
        }
        printf("\n");
    }


    return 0;
}
