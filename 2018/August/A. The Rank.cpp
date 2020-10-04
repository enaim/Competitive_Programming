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
    int v=0,ind;
};

node ar[10010];

bool compare(node a,node b)
{
    if(a.v == b.v)
        return a.ind<b.ind;
    return a.v>b.v;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ans,x,i,n,j;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&x);
                ar[i].v+=x;
            }
            ar[i].ind = i;
        }
        sort(&ar[0],&ar[n],compare);
        for(i=0;i<n;i++)
            if(ar[i].ind==0)
                ans = i+1;
        printf("%d\n",ans);
    }

    return 0;
}
