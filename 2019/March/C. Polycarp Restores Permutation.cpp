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

int ar[200010];
int br[200010];
set<int>st;
int i,j,mn,mx,n;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        st.clear();
        for(i=0;i<n-1;i++)
            scanf("%d",&ar[i]);

        if(ar[0]<0)
            br[0]=1+abs(ar[0]);
        else
            br[0]=1;
        mx = br[0];
        mn = br[0];

        st.insert(br[0]);
        for(i=0;i<n-1;i++)
        {
            br[i+1]=br[i]+ar[i];
            st.insert(br[i+1]);
            mx = max(mx,br[i+1]);
            mn = min(mn,br[i+1]);
        }
        if(st.size()==n && mn<=1 && mx<=n)
        {
            mn = 1-mn;
            mx = mn+mx;
            if(mx==n)
            {
                for(i=0;i<n;i++)
                    printf("%d ",br[i]+mn);
            }
            else
                printf("-1");
        }
        else
            printf("-1");
        printf("\n");
    }

    return 0;
}
