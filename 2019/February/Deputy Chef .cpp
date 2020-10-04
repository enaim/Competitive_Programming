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

int p[110];
int d[110];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&p[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]);
        p[0]=p[n];
        d[0]=d[n];
        p[n+1]=p[1];
        d[n+1]=d[1];

        priority_queue<int>pq;
        for(i=1;i<=n;i++)
        {
            if(p[i-1]+p[i+1]<d[i])
                pq.push(d[i]);
        }
        if(pq.size()==0)
            printf("-1\n");
        else
            printf("%d\n",pq.top());
    }

    return 0;
}
