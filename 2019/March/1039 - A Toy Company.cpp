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
    int x,y,z,s;
};

int ans;
node start,finish;
int vis[26][26][26];

bool check(node v)
{
    if(vis[v.x][v.y][v.z]==0)
        return true;
    return false;
}

void visited(node v)
{
    vis[v.x][v.y][v.z]=1;
}

void bfs()
{
    int i;
    node v,ar[6];

    queue<node>Q;
    if(check(start))
    {
        visited(start);
        Q.push(start);
    }
    else
        return;

    if(start.x==finish.x && start.y==finish.y && start.z==finish.z)
    {
        ans = 0;
        Q.pop();
        return;
    }

    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();

        for(i=0;i<6;i++)
            ar[i]=v;

        ar[0].x = (v.x+1+26)%26,ar[1].x = (v.x-1+26)%26,ar[2].y = (v.y+1+26)%26;
        ar[3].y = (v.y-1+26)%26,ar[4].z = (v.z+1+26)%26,ar[5].z = (v.z-1+26)%26;

        for(i=0;i<6;i++)
        {
            ar[i].s=v.s+1;
            if(check(ar[i]))
            {
                visited(ar[i]);
                if(ar[i].x==finish.x && ar[i].y==finish.y && ar[i].z==finish.z)
                {
                    ans = ar[i].s;
                    while(!Q.empty())
                        Q.pop();
                    break;
                }
                Q.push(ar[i]);
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,k,l,l1,l2,l3,n;
    char str1[30],str2[30],str3[30];
    scanf("%d",&tks);
    while(tks--)
    {
        ans = -1;
        memset(vis,0,sizeof vis);

        scanf("%s%s%d",str1,str2,&n);
        start.x = str1[0]-'a', start.y = str1[1]-'a', start.z = str1[2]-'a',start.s=0;
        finish.x = str2[0]-'a',finish.y = str2[1]-'a',finish.z = str2[2]-'a',finish.s=0;

        for(i=0;i<n;i++)
        {
            scanf("%s%s%s",str1,str2,str3);
            l1 = strlen(str1);
            l2 = strlen(str2);
            l3 = strlen(str3);
            for(j=0;j<l1;j++)
                for(k=0;k<l2;k++)
                    for(l=0;l<l3;l++)
                        vis[str1[j]-'a'][str2[k]-'a'][str3[l]-'a']=1;
        }

        bfs();

        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
