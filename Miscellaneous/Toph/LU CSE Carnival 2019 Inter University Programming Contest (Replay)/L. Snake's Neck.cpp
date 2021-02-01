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

struct node{
    int x,y;
};

node ar[100010];
node br[100010];

pii a,b;
map<pii,int>mp;
int i,n,ans,f;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int cnt = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&ar[i].x,&ar[i].y);
        a = make_pair(ar[i].x,ar[i].y);
        mp[a]=cnt++;
    }

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&ar[i].x,&ar[i].y);
    cnt = ans = f = 0;
    for(i=0;i<n;i++)
    {
        a = make_pair(ar[i].x,ar[i].y);
        if(mp[a]!=0)
        {
            if(f==0 && cnt==0)
            {
                cnt++;
            }
            else if(f==0)
            {
                cnt++;
                b = make_pair(ar[i-1].x,ar[i-1].y);
                if(mp[b]-mp[a]==1)
                    f = 1;
                else if(mp[b]-mp[a]==-1)
                    f = 2;
                else
                    cnt = 1;
            }
            else if(f==1)
            {
                b = make_pair(ar[i-1].x,ar[i-1].y);
                if(mp[b]-mp[a]==1)
                    cnt++;
                else
                {
                    f = 0;
                    cnt = 1;
                }
            }
            else if(f==2)
            {
                b = make_pair(ar[i-1].x,ar[i-1].y);
                if(mp[b]-mp[a]==-1)
                    cnt++;
                else
                {
                    f = 0;
                    cnt = 1;
                }
            }
            ans = max(cnt,ans);
        }
        else
        {
            f = 0;
            cnt = 0;
        }
    }
    printf("%d\n",ans);

    return 0;
}
