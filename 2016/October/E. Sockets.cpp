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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

typedef pair<int,int>pii;
const int SIZE = 200010;

map<int,int>freq,Hash,cnt;
vector<int>adj[SIZE];
vector<pii>v;
pii z;
int ar[SIZE];
int n,m,cnt1,cmp;
long long adp;

struct res{
    int a,s;
};

res ans[SIZE];

void initialize()
{
    cmp=0;
    adp=0;
    v.clear();
    cnt.clear();
    freq.clear();
    Hash.clear();

    int r = n>m ? n : m ;

    for(int i=1;i<=r;i++)
    {
        ans[i].a=0;
        ans[i].s=0;
        adj[i].clear();
    }
}

void input()
{
    int p;
    int c = 1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(!Hash[p])
            Hash[p]=c++;
        freq[p]++;
        adj[Hash[p]].pb(i);
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&ar[i]);
}

void check1()
{
    for(int i=1;i<=m;i++)
    {
        int  x = ar[i];
        if(freq[x]>0)
        {
            int temp = adj[Hash[x]][cnt[x]++];
            ans[temp].s = i;
            freq[x]--;
            cmp++;
        }
        else
        {
            z = make_pair(ar[i],i);
            v.pb(z);
        }
    }
}

void check2()
{
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        bool flag = false;
        cnt1=0;
        while(x>1)
        {
            x = (x+1)/2;
            cnt1++;
            if(freq[x]>0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            int temp = adj[Hash[x]][cnt[x]++];
            ans[y].a = cnt1;
            ans[temp].s = y;
            freq[x]--;
            adp+=cnt1;
            cmp++;
        }
    }
}

void output()
{
    printf("%d %I64d\n",cmp,adp);
    for(int i=1;i<=m;i++)
    {
        if(i!=m)
            printf("%d ",ans[i].a);
        else
            printf("%d\n",ans[i].a);
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n)
            printf("%d ",ans[i].s);
        else
            printf("%d\n",ans[i].s);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    while(2==scanf("%d%d",&n,&m))
    {
        initialize();
        input();
        check1();
        check2();
        output();
    }

    return 0;
}
