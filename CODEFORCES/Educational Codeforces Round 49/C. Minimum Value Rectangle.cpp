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
    int ind,v;
};

node ar[10010];
double mn;
int ans1,ans2;
void func(node a,node b)
{
    double ans = (double)sqr((a.ind+ b.ind)*2.0)/(double)(a.ind*b.ind);
    if(ans<mn)
    {
        mn = ans;
        ans1 = a.ind;
        ans2 = b.ind;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,cnt,n,x;
    int br[10010];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        mn = 1234567891011.00;
        memset(br,0,sizeof br);
        set<int>st;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            br[x]++;
            if(br[x]>=2)
                st.insert(x);
        }
        cnt = 0;
        for(auto it: st)
        {
            ar[cnt].ind = it;
            ar[cnt++].v =br[it];
        }

        if(ar[0].v>=4)
        {
            func(ar[0],ar[0]);
        }
        for(i=1;i<cnt && i<=100;i++)
        {
            if(ar[i].v>=4)
                func(ar[i],ar[i]);
            func(ar[i-1],ar[i]);
        }
        for(i=cnt-1;i>cnt-100 && i>0;i--)
        {
            if(ar[i].v>=4)
                func(ar[i],ar[i]);
            func(ar[i-1],ar[i]);
        }
        printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
    }

    return 0;
}
