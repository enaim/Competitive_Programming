#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

struct node{
    int s,e,ind;
};

node ar[1010];

bool compare(node a,node b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}

char ans[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,flag=0;

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&ar[i].s,&ar[i].e),ar[i].ind=i;

        sort(&ar[0],&ar[n],compare);

        int jamie = 0;
        int cameron = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i].s>=jamie)
            {
                ans[ar[i].ind]='J';
                jamie = ar[i].e;
            }
            else if(ar[i].s>=cameron)
            {
                ans[ar[i].ind]='C';
                cameron = ar[i].e;
            }
            else
                flag = 1;
        }
        ans[n]='\0';
        if(flag)
            printf("Case #%d: IMPOSSIBLE\n",ks++);
        else
            printf("Case #%d: %s\n",ks++,ans);
    }

    return 0;
}
