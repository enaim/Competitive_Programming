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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
    int x,y;
};

bool compare(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int sz[30];

char str[2010][2010];
node ar[30][1000010];
int r,c,i,j,ch,mx,flag;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(sz,0,sizeof sz);
        mx = -1;

        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",str[i]);
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='.')
                    continue;
                ch = str[i][j]-'a';
                mx = max(ch,mx);
                node t;
                t.x = i;
                t.y = j;
                ar[ch][sz[ch]] = t;
                sz[ch]++;
            }
        }
        if(mx==-1)
        {
            printf("YES\n0\n");
            continue;
        }

        flag = 1;
        for(i=0;i<=mx;i++)
        {
            if(sz[i]==0)
                continue;

            sort(&ar[i][0],&ar[i][sz[i]],compare);

            int cnt = 0,cnt1 = 0;

            for(j=0;j<sz[i];j++)
                if(ar[i][j].x==ar[i][0].x)
                    cnt++;

            for(j=0;j<sz[i];j++)
                if(ar[i][j].y==ar[i][0].y)
                    cnt1++;
            if(!((cnt==1 && cnt1==sz[i]) || (cnt1==1 && cnt==sz[i])))
                {
                    flag = 0;
                    break;
                }
        }
        if(flag==0)
        {
            printf("NO\n");
            continue;
        }

        for(i=mx;i>=0;i--)
        {
            if(sz[i]==0)
            {
                for(j=0;j<sz[i+1];j++)
                    ar[i][j]=ar[i+1][j];
                sz[i] = sz[i+1];
            }
            if(ar[i][0].x==ar[i][sz[i]-1].x)
            {
                for(j=ar[i][0].y;j<=ar[i][sz[i]-1].y;j++)
                {
                    int a = ar[i][0].x;
                    int b = j;
                    if(str[a][b]=='.' || str[a][b]-'a'<i)
                    {
                        flag = 0;
                        break;
                    }
                    else
                        str[a][b]='a'+i;
                }
            }
            else
            {
                for(j=ar[i][0].x;j<=ar[i][sz[i]-1].x;j++)
                {
                    int a = j;
                    int b = ar[i][0].y;
                    if(str[a][b]=='.' || str[a][b]-'a'<i)
                    {
                        flag = 0;
                        break;
                    }
                    else
                        str[a][b]='a'+i;
                }
            }
            if(flag==0)
                break;
        }

        if(flag==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d\n",mx+1);
        for(i=0;i<=mx;i++)
        {
            printf("%d %d %d %d\n",ar[i][0].x+1,ar[i][0].y+1,ar[i][sz[i]-1].x+1,ar[i][sz[i]-1].y+1);
        }
    }

    return 0;
}
