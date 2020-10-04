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

int vis[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,mx;
    int ar[1010],l[1010],r[1010];
    int L[1010],R[1010];

    while(1==scanf("%d",&n))
    {
        set<int>st;
        for(i=1;i<=n;i++)
            scanf("%d",&l[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&r[i]);

        for(i=1;i<=n;i++)
        {
            L[i]=l[i];
            R[i]=r[i];
        }

        mx = n;
        for(i=1;i<=n;i++)
            if(l[i]==0 && r[i]==0 && vis[i]==0)
                st.insert(i);

        while(st.size())
        {
            for(auto it : st)
            {
                ar[it]=mx;
                vis[it]=1;
                for(i=it+1;i<=n;i++)
                {
                    if(l[i]>0)
                        l[i]--;
                }
                for(i=1;i<it;i++)
                {
                    if(r[i]>0)
                        r[i]--;
                }
            }
            st.clear();
            mx--;
            for(i=1;i<=n;i++)
                if(l[i]==0 && r[i]==0 && vis[i]==0)
                    st.insert(i);
        }
        for(i=1;i<=n;i++)
            if(l[i]!=0 || r[i]!=0 || vis[i]!=1)
            {
                printf("NO\n");
                return 0;
            }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(ar[j]>ar[i])
                    L[i]--;
            }
            for(j=i+1;j<=n;j++)
            {
                if(ar[j]>ar[i])
                    R[i]--;
            }
            if(L[i]!=0 || R[i]!=0)
            {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
        for(i=1;i<=n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
