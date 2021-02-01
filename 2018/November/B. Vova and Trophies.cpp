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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,t,cnt,g,s,ans,i,y;
    char str[100010];

    while(2==scanf("%d%s",&n,str))
    {
        g = s = 0;
        for(i=0;i<n;i++)
            if(str[i]=='G')
                g++;
            else
                s++;

        if(g==0 || g==1 || g==n)
        {
            printf("%d\n",g);
            continue;
        }
        if(s==1)
        {
            printf("%d\n",n-1);
            continue;
        }

        cnt = t = 0;
        ans  = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='G')
                cnt++;
            else
            {
                if(i>0 && str[i]==str[i-1])
                {
                    t = 0;
                    cnt = 0;
                    continue;
                }
                if(t==0)
                {
                    y = cnt;
                    if(cnt!=g)
                        ans = max(ans,cnt+1);
                    else
                        ans = max(ans,cnt);
                    t = 1;
                    cnt = 0;
                }
                else
                {
                    if(y+cnt!=g)
                        ans = max(ans,y+cnt+1);
                    else
                        ans = max(ans,y+cnt);
                    y = cnt;
                    cnt = 0;
                }
            }
        }
        if(t==0)
        {
            y = cnt;
            if(cnt!=g)
                ans = max(ans,cnt+1);
            else
                ans = max(ans,cnt);
            t = 1;
        }
        else
        {
            if(y+cnt!=g)
                ans = max(ans,y+cnt+1);
            else
                ans = max(ans,y+cnt);
            y = cnt;
            cnt = 0;
        }

        printf("%d\n",ans);
    }

    return 0;
}
