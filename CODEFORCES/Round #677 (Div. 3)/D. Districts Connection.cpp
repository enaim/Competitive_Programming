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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

vector<int>vec[5010];
set<int>st;
set<int>st1;
map<int,int>mp;
int flag[5010];
int last[5010];
int szz[5010];
int arr[5010];

struct node{
    int u,v;
};
node ar[5010];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,cnt1,cnt;
        mp.clear();
        st.clear();
        for(i=0;i<5010;i++)
        {
            szz[i]=0;
            last[i]=0;
            flag[i]=0;
            vec[i].clear();
        }
        sf(n);
        for(i=1;i<=n;i++)
        {
            sf(arr[i]);
            st.insert(arr[i]);
        }

        cnt = 1;
        for(auto it:st)
        {
            mp[it] = cnt++;
        }

        for(i=1;i<=n;i++)
        {
            szz[i]=mp[arr[i]];
            vec[szz[i]].pb(i);
        }

        cnt1 = 0;
        int ok = 0;
        for(i=2;i<cnt;i++)
        {
            j = 1;

            ar[cnt1].u = vec[i][0];
            ar[cnt1].v = vec[j][0];

            flag[vec[i][0]]=1;
            flag[vec[j][0]]=1;
            cnt1++;
            ok = 1;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(szz[i] != szz[j] && (flag[i]+flag[j]==1) && cnt1<n-1)
                {
                    ar[cnt1].u = i;
                    ar[cnt1].v = j;
                    flag[i]=1;
                    flag[j]=1;
                    cnt1++;
                }
                if(cnt1==n-1)
                    break;
            }
            if(cnt1==n-1)
                break;
        }

        if(cnt1==n-1)
        {
            puts("YES");
            for(i=0;i<cnt1;i++)
                pf2(ar[i].u,ar[i].v);
        }
        else
            puts("NO");
    }

    return 0;
}
