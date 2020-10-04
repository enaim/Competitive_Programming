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

vector<int>vec[1010];
int ans[1010];
int sz[1010];
char str[100];
map<int,int>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        int i,sum,k,j,n,dif,x,mx,l,r,mid;
        for(i=0;i<1005;i++)
        {
            vec[i].clear();
            sz[i]=0;
            ans[i]=0;
        }

        scanf("%d%d",&n,&k);
        sum = 0;
        for(i=1;i<=k;i++)
        {
            scanf("%d",&sz[i]);
            for(j=0;j<sz[i];j++)
            {
                scanf("%d",&x);
                vec[i].pb(x);
                mp[x]++;
            }
            sum+=sz[i];
        }
        int add = -1;
        if(sum<n)
        {
            k++;
            add = k;
            for(i=1;i<=n;i++)
            {
                if(mp[i])
                    continue;
                vec[add].pb(i);
                sz[add]++;
            }
        }

        printf("? %d",n);
        for(i=1;i<=n;i++)
            printf(" %d",i);
        printf("\n");
        fflush(stdout);

        scanf("%d",&mx);

        for(i=1;i<=k;i++)
            ans[i]=mx;

        l = 1;
        r = k;
        while(true)
        {
            if(l==r)
                break;
            mid = (l+r)/2;
            sum = 0;
            for(i=l;i<=mid;i++)
                sum+=sz[i];

            printf("? %d",sum);
            for(i=l;i<=mid;i++)
            {
                for(j=0;j<sz[i];j++)
                    printf(" %d",vec[i][j]);
            }
            printf("\n");
            fflush(stdout);

            scanf("%d",&x);
            if(x==-1)
                exit(0);

            if(x==mx)
                r = mid;
            else
                l = mid+1;
        }
        dif = r;
        if(dif!=add)
        {
            sum = n-sz[dif];
            mp.clear();
            for(i=0;i<sz[dif];i++)
                mp[vec[dif][i]]++;
            printf("? %d",sum);
            for(i=1;i<=n;i++)
            {
                if(mp[i]==1)
                    continue;
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            if(x==-1)
                exit(0);
            ans[dif]=x;
        }
        if(add!=-1)
            k--;

        printf("!");
        for(i=1;i<=k;i++)
            printf(" %d",ans[i]);
        printf("\n");
        fflush(stdout);

        scanf("%s",str);
        if(strcmp(str,"Correct")!=0)
            exit(0);
    }

    return 0;
}
