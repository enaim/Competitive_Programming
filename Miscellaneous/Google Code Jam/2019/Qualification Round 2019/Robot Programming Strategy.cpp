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

int flag[510];
int sz[510];
string str[600];
string ans;
int n,mx;

void func(int j,char ch)
{
    int i;
    for(i=0;i<n;i++)
        if(flag[i]==0 && str[i][j]==ch)
            flag[i]=1;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,i,j,f,p,s,r;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<260;i++)
        {
            sz[i]=flag[i]=0;
            str[i].clear();
        }
        ans.clear();
        ans = "";

        scanf("%d",&n);
        mx = 0;
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            sz[i] = (int)str[i].size();
            mx = max(mx,sz[i]);
        }

        for(i=0;i<n;i++)
        {
            int k = 0;
            for(j=sz[i];j<mx;j++)
                str[i] += str[i][k%sz[i]],k++;
        }

        f = 0;
        for(j=0;j<mx;j++)
        {
            p=s=r=0;
            for(i=0;i<n;i++)
            {
                if(flag[i])
                    continue;
                if(str[i][j]=='P')
                    p++;
                else if(str[i][j]=='R')
                    r++;
                else if(str[i][j]=='S')
                    s++;
            }

            if(p && s && r)
            {
                f = 1;
                break;
            }

            if(p && r)
            {
                ans = ans + 'P';
                func(j,'R');
            }
            else if(p && s)
            {
                ans = ans + 'S';
                func(j,'P');
            }
            else if(s && r)
            {
                ans = ans + 'R';
                func(j,'S');
            }
            else if(p)
            {
                ans = ans + 'S';
                func(j,'P');
            }
            else if(r)
            {
                ans = ans + 'P';
                func(j,'R');
            }
            else if(s)
            {
                ans = ans + 'R';
                func(j,'S');
            }
        }

        p = s = r = 0;
        for(i=0;i<n;i++)
        {
            j = mx-1;
            if(flag[i]==1)
                continue;
            if(str[i][j]=='P')
                p++;
            else if(str[i][j]=='R')
                r++;
            else if(str[i][j]=='S')
                s++;
        }

        if(p && s && r)
            f = 1;
        else if(p && r)
        {
            ans = ans + 'P';
            ans = ans + 'S';
        }
        else if(p && s)
        {
            ans = ans + 'S';
            ans = ans + 'R';
        }
        else if(s && r)
        {
            ans = ans + 'R';
            ans = ans + 'P';
        }
        else if(p)
            ans = ans + 'S';
        else if(r)
            ans = ans + 'P';
        else if(s)
            ans = ans + 'R';

        if(f==0 && ans.size()<=500)
            printf("Case #%d: %s\n",ks++,ans.c_str());
        else
            printf("Case #%d: IMPOSSIBLE\n",ks++);
    }

    return 0;
}
