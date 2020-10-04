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

set<int>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        int i,n,x,k,t,j;
        scanf("%d%d",&n,&k);
        int mx = 0,mn = 0;;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            st.insert(x);
            mx = max(mx,x);
        }

        int sz = st.size();
        if(sz>k)
        {
            printf("-1\n");
            continue;
        }

        for(i=1;i<=n;i++)
        {
            if(k%sz==0)
                break;
            st.insert(i);
            sz = st.size();
        }

        t = n;
        printf("%d\n",n*sz);
        while(t--)
        {
            for(auto it:st)
                printf("%d ",it);
        }
        printf("\n");
        continue;
    }

    return 0;
}
