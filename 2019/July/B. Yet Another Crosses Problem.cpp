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

string str[50010];
int row[50010];

int main()
{
    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,r,c,cnt,j,ans,k;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&r,&c);
        int flag[r+10][c+10];
        memset(flag,0,sizeof flag);

        for(i=0;i<r;i++)
            cin>>str[i];
        int mxr = 0;
        for(i=0;i<r;i++)
        {
            cnt = 0;
            for(j=0;j<c;j++)
                if(str[i][j]=='*')
                    cnt++;

            row[i]=r-cnt;
            for(j=0;j<c;j++)
                if(str[i][j]!='*')
                {
                    flag[i][j]=1;
                }
        }

        int mxc = OO;
        for(i=0;i<c;i++)
        {
            cnt = 0;
            for(j=0;j<r;j++)
                if(str[j][i]=='*')
                    cnt++;
            for(k=0;k<r;k++)
            {
                ans = row[k]+c-cnt;
                if(flag[k][i]==1)
                    ans--;
                mxc = min(mxc,ans);
            }
        }
        printf("%d\n",mxc);
        for(i=0;i<r;i++)
            str[i].clear();
    }

    return 0;
}
