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

int i,j,n,m,cnt,x,mx;
set<int>st;
map<int,int>mp;
int ar[1010][1010];
int br[1010][1010];
int br1[1010][1010];
int flag1[1010];
int flag2[1010];


void func()
{
    printf("\n\n\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                printf("%d ",br[i][j]);
            printf("\n");
        }

        printf("\n\n\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                printf("%d ",br1[i][j]);
            printf("\n");
        }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            st.clear();
            mp.clear();
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                ar[i][j]=x;
                st.insert(x);
            }
            cnt = 1;
            for(auto it : st)
            {
                mp[it]=cnt;
                cnt++;
            }
            for(j=1;j<=m;j++)
                br[i][j]=mp[ar[i][j]];
            flag1[i]=cnt-1;
        }

        for(i=1;i<=m;i++)
        {
            st.clear();
            mp.clear();
            for(j=1;j<=n;j++)
                st.insert(ar[j][i]);
            cnt = 1;
            for(auto it : st)
            {
                mp[it]=cnt;
                cnt++;
            }
            for(j=1;j<=n;j++)
                br1[j][i]=mp[ar[j][i]];
            flag2[i]=cnt-1;
        }
//        func();
//        printf("\n");printf("\n");printf("\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(br[i][j]==br1[i][j])
                {
                    printf("%d ",max(flag1[i],flag2[j]));
                    continue;
                }
                if(br[i][j]<br1[i][j])
                {
                    x = br1[i][j]-br[i][j];
                    mx = max(flag1[i]+x,flag2[j]);
                    printf("%d ",mx);
                }
                else
                {
                    x = br[i][j]-br1[i][j];
                    mx = max(flag1[i],flag2[j]+x);
                    printf("%d ",mx);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
