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

struct node{
    int v,ind;
};
node ar[200010];

bool compare(node a,node b)
{
    if(a.v==b.v)
        return a.ind<b.ind;
    return a.v<b.v;
}

ll sum;
int i,n,x,y,p1,p2;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n*2;i+=2)
        {
            scanf("%d%d",&x,&y);
            ar[i].ind=i;
            ar[i].v=x;
            ar[i+1].ind=i+1;
            ar[i+1].v=y;
        }
        sort(&ar[1],&ar[(2*n)+1],compare);
        sum = ar[1].ind+ar[2].ind-2;
        p1 = ar[1].ind;
        p2 = ar[2].ind;
        for(i=3;i<=n*2;i+=2)
        {
            if((abs(p1-ar[i].ind) + abs(p2-ar[i+1].ind)) < (abs(p1-ar[i+1].ind) + abs(p2-ar[i].ind)))
            {
                sum+=(abs(p1-ar[i].ind) + abs(p2-ar[i+1].ind));

                p1 = ar[i].ind;
                p2 = ar[i+1].ind;
            }
            else
            {
                sum+=(abs(p1-ar[i+1].ind) + abs(p2-ar[i].ind));
                p2 = ar[i].ind;
                p1 = ar[i+1].ind;
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
