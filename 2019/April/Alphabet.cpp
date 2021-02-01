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

int dp[60][30];
int n;
char str[60];

int go(int pos,int last)
{
    if(pos==n)
        return 0;
    int  &re = dp[pos][last];
    if(re!=-1)
        return re;
    re = go(pos+1,last);
    if(last<str[pos]-'a'+1)
        re = max(re,go(pos+1,str[pos]-'a'+1)+1);
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%s",str))
    {
        memset(dp,-1,sizeof dp);
        n = strlen(str);
        int ans = go(0,0);

        printf("%d\n",max(0,26-ans));
    }

    return 0;
}
