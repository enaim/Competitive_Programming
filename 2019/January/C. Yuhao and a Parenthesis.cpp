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

int o[500010];
int c[500010];
char str[500010];
int x;

bool valid()
{
    int oo=0,cc=0,j;
    for(j=0;j<x;j++)
    {
        if(str[j]=='(')
            oo++;
        else if(oo)
            oo--;
        else
            cc++;
    }
    if(oo && cc)
        return false;
    return true;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,ok,j,ans;

    while(1==scanf("%d",&n))
    {
        ans = ok = 0;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            x = strlen(str);
            int cnt = 0;
            if(!valid())
                continue;
            for(j=0;j<x;j++)
            {
                if(str[j]=='(')
                    cnt++;
                else
                    cnt--;
            }
            if(cnt==0)
                ok++;
            else if(cnt>0)
                o[abs(cnt)]++;
            else
                c[abs(cnt)]++;
        }
        int ans = ok/2;
        for(i=1;i<=5e5;i++)
        {
            if(o[i]<=c[i])
                ans+=o[i];
            else
                ans+=c[i];
        }
        printf("%d\n",ans);
    }

    return 0;
}
