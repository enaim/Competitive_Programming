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

int r,c;
int dp[510][1100];
int ar[510][510];
vector<int>vec;
int go(int pos,int k)
{
    int i;
    if(r==pos && k!=0)
        return 1;
    if(r==pos)
        return 0;
    int &re = dp[pos][k];
    if(re!=-1)
        return re;
    re = 0;
    for(i=0;i<c;i++)
    {
        re = go(pos+1,k^ar[pos][i]);
        if(re==1)
        {
            vec.pb(i);
            return re;
        }
    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j;
    while(2==scanf("%d%d",&r,&c))
    {
        memset(dp,-1,sizeof dp);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&ar[i][j]);
        int ans = go(0,0);
        if(ans==0)
        {
            printf("NIE\n");
            continue;
        }
        reverse(vec.begin(),vec.end());
        printf("TAK\n");
        for(auto it:vec)
            cout<<it+1<<" ";
    }

    return 0;
}
