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
    int val,lv;
};

int vis[1010];

int dfs(int n,int k)
{
    if(n==k)
        return 0;
    if(n>k)
        return -1;
    int ans = OO;
    node v,x;
    v.val = n;
    v.lv = 0;
    vis[v.val]=0;
    stack<node>stk;
    stk.push(v);
    while(!stk.empty())
    {

        v = stk.top();
        stk.pop();
        if(v.lv != vis[v.val])
            continue;
        if(v.val==k)
        {
            ans = min(ans,v.lv);
            continue;
        }
        int temp = v.val,i,f;
        for(i=2;i*i<=temp;i++)
        {
            f = 0;
            while(temp%i==0)
            {
                f = 1;
                temp/=i;
            }
            if(f)
            {
                x.val=v.val+i,x.lv=v.lv+1;
                if(x.val<=k && vis[x.val]>x.lv)
                    stk.push(x),vis[x.val]=x.lv;
            }
        }
        i = temp;
        if(i!=1 && i!=v.val)
        {
            x.val=v.val+i,x.lv=v.lv+1;
            if(x.val<=k && vis[x.val]>x.lv)
                stk.push(x),vis[x.val]=x.lv;
        }
    }
    if(ans==OO)
        return -1;
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,k;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(vis,OO,sizeof vis);
        scanf("%d%d",&n,&k);
        printf("Case %d: %d\n",ks++,dfs(n,k));
    }

    return 0;
}
