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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

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
const int SIZE = 150010;

int n;
int Q[SIZE];
int ar[SIZE];
int seg[SIZE];
int BIT[SIZE];

void update(int n,int index,int v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

int Query(int n,int index)
{
    int ans = 0;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,e,n,s,x,y,ans,t,v,q;
    int tks,ks=1;
    scanf("%d",&tks);
    map<int,int>mp;
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        mp.clear();
        memset(BIT,0,sizeof BIT);
        scanf("%d%d",&n,&q);
        for(i=1;i<=n*2;i+=2)
        {
            scanf("%d%d",&x,&y);
            seg[i] = x;
            seg[i+1] = y;
            ar[i] = x;
            ar[i+1] = y;;
        }
        for(j=1;j<=q;j++)
        {
            scanf("%d",&x);
            ar[i++] = x;
            Q[j]=x;
        }
        sort(&ar[1],&ar[i]);
        int cnt = 1;
        for(j=1;j<i;j++)
            mp[ar[j]] = cnt++;
        for(j=1;j<=n*2;j+=2)
        {
            update(i-1,mp[seg[j]],1);
            update(i-1,mp[seg[j+1]]+1,-1);
        }
        for(j=1;j<=q;j++)
            printf("%d\n",Query(i-1,mp[Q[j]]));
    }

    return 0;
}
