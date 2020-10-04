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

int ar[100010];
int dp[10][100010];
int n;
vector<int>vec;

int go(int l,int pos)
{
    int i;
    if (pos==n)
        return 1;

    int &re = dp[l][pos];
    if(re!=-1)
        return re;

    re = 0;
    if(ar[pos-1] < ar[pos])
    {
        if(l==5)
            re =  0;
        else
        {
            for(i=l+1;i<6;i++)
            {
                re = go(i,pos+1);
                if(re==1)
                {
                    vec.pb(i);
                    return re;
                }
            }
        }
    }
    else if(ar[pos-1] > ar[pos])
    {
        if(l==1)
            re =  0;
        else
        {
            for(i=l-1;i>0;i--)
            {
                re = go(i,pos+1);
                if(re==1)
                {
                    vec.pb(i);
                    return re;
                }
            }
        }
    }
    else
    {
        if(l<5)
        {
            for(i=l+1;i<6;i++)
            {
                re = go(i,pos+1);
                if(re==1)
                {
                    vec.pb(i);
                    return re;
                }
            }
        }
        if(l>1)
        {
            for(i=l-1;i>0;i--)
            {
                re = go(i,pos+1);
                if(re==1)
                {
                    vec.pb(i);
                    return re;
                }
            }
        }
    }
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,x;

    while(1==scanf("%d",&n))
    {
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<=5;i++)
        {
            x = 0;
            x = go(i,1);
            if(x == 1)
            {
                vec.pb(i);
                break;
            }
        }
        if(x==0)
        {
            printf("-1\n");
            continue;
        }
        for(i=n-1;i>=0;i--)
            printf("%d ",vec[i]);
        printf("\n");
    }

    return 0;
}
