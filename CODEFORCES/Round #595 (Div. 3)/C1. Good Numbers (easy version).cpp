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

set<int>st;
int p[12];
int dp[12][35000];
int go(int pos, int sum)
{
    if(pos==10)
    {
        st.insert(sum);
        return 1;
    }
    int &re = dp[pos][sum];
    if(re!=-1)
        return 1;
    go(pos+1,sum);
    go(pos+1,sum+p[pos]);
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset(dp,-1,sizeof dp);
    p[0]=1;
    p[1]=3;
    for(int i=2;i<10;i++)
        p[i]=p[i-1]*3;
    go(0,0);

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(auto it:st)
        {
            if(it>=n)
            {
                n = it;
                break;
            }
        }
        printf("%d\n",n);
    }

    return 0;
}
