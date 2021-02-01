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

string str;
int temp1,temp2,sz;
long long dp[3010][3010];
long long mod = 1000000007;

long long go(int last,int pos)
{
    if(pos==sz)
       return 1LL;

    long long &re = dp[last][pos];
    if(re !=-1LL)
        return re;
    re = 0;
    int w=0,b=0;
    for(int i=pos;i<sz;i++)
    {
        if(str[i]=='w')
            w++;
        else
            b++;
        if(w==temp1 && b==temp2)
        {
            re += (2LL*go(pos,i+1));
            re%=mod;
        }
        else if(w==temp1)
        {
            re += go(pos,i+1);
            re%=mod;
        }
        else if(b==temp2)
        {
            re += go(pos,i+1);
            re%=mod;
        }
    }
    return re;
}


int getNumber(vector <int> balls, int white, int black)
{
  temp1 = white;
  temp2 = black;
  str.clear();
  str = "#";
  int i,j;
  for(i=0;i<balls.size();i++)
    {
        if(i%2==0)
        {
            for(j=0;j<balls[i];j++)
                str+="w";
        }
        else
        {
            for(j=0;j<balls[i];j++)
                str+="b";
        }
    }
    sz = str.size();
    memset(dp,-1,sizeof dp);
    return go(0,1);
}


int main()
{
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);

    vector<int>v;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        v.clear();
        int i,x,n,w,b;
        scanf("%d%d%d",&n,&w,&b);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        printf("Case #%d: %d\n",ks++,getNumber(v,w,b));
    }

    return 0;
}

