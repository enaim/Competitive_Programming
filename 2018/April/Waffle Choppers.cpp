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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

char str[110][110];
int row[110],column[110],ro,co,h,v,i,j,k,o,p,x,y,cnt,sum,l1,l2,f1,f2;
vector<int>r,c,ans;
bool flag;

void input()
{
    scanf("%d%d%d%d",&ro,&co,&h,&v);
    sum = 0;
    for(i=0;i<ro;i++)
    {
        scanf("%s",str[i]);
        cnt = 0;
        for(j=0;j<co;j++)
        {
            if(str[i][j]=='@')
            cnt++;
        }
        row[i] = cnt;
        sum += row[i];
    }
    for(i=0;i<co;i++)
    {
        cnt = 0;
        for(j=0;j<ro;j++)
        {
            if(str[j][i]=='@')
                cnt++;
        }
        column[i]=cnt;
    }
}

void func1()
{
    cnt = 0;
    flag = true;
    for(i=0;i<ro;i++)
    {
        cnt+=row[i];
        if(x==cnt)
        {
            r.pb(i);
            cnt = 0;
        }
        if(x<cnt)
        {
            flag = false;
            break;
        }
    }
    if(r.size() != h+1)
        flag = false;
}

void func2()
{
    cnt = 0;
    flag = true;
    for(i=0;i<co;i++)
    {
        cnt+=column[i];
        if(y==cnt)
        {
            c.pb(i);
            cnt = 0;
        }
        if(y<cnt)
        {
            flag = false;
            break;
        }
    }
    if(c.size() != v+1)
        flag = false;

}

void check()
{
    i = 0;
    j = 0;
    while(i<r.size())
    {
        if(i==0)
        {
            l1 = 0;
            f1 = r[i];
        }
        else
        {
            l1 = f1+1;
            f1 = r[i];
        }
        for(j=0;j<c.size();j++)
        {
            if(j==0)
            {
                l2 = 0;
                f2 = c[j];
            }
            else
            {
                l2 = f2+1;
                f2 = c[j];
            }
            cnt = 0;
            for(o=l1;o<=f1;o++)
            {
                for(p=l2;p<=f2;p++)
                {
                    if(str[o][p]=='@')
                        cnt++;
                }
            }
            ans.pb(cnt);
        }
        i++;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        r.clear();
        c.clear();
        ans.clear();
        input();
        x = sum/(h+1);
        y = sum/(v+1);
        if(sum ==0 )
        {
            printf("Case #%d: POSSIBLE\n",ks++);
            continue;
        }
        if(sum%x==0)
        {
            func1();
        }
        else
            flag = false;

        if(flag && sum%y==0)
        {
            func2();
        }
        else
            flag = false;

        if(flag)
        {
            check();
        }
        if(flag)
        {
            for(i=1;i<ans.size();i++)
            {
                if(ans[i-1]!=ans[i])
                {
                    flag = false;
                }
            }
        }
        if(flag)
            printf("Case #%d: POSSIBLE\n",ks++);
        else
            printf("Case #%d: IMPOSSIBLE\n",ks++);
    }

    return 0;
}
