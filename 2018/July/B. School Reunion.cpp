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

struct node{
    int s,e;
};

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int flag1[200010],flag2[200010];
    set<int>st,st1;
    map<int,int>mp1,mp2;
    scanf("%d",&tks);
    while(tks--)
    {
        int x,y,n,p,i,j;
        scanf("%d%d",&n,&p);
        node ar[n+10];
        st.clear();
        mp1.clear();
        mp2.clear();

        for(i=0;i<200010;i++)
        {
            flag1[i]=0;
            flag2[i]=0;
        }

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            st.insert(x);
            st.insert(y);
            ar[i].s = x;
            ar[i].e = y;
        }
        int cnt = 1;
        for(auto it : st)
        {
           mp1[it]=cnt;
           mp2[cnt]= it;
           cnt++;
        }
        int a,b;

        for(i=0;i<n;i++)
        {
            x = ar[i].s;
            y = ar[i].e;
            a = mp1[x];
            b = mp1[y];
            flag1[a]++;
            flag2[b]++;
        }

        int mn = 2e9+10,sz = 0;

        i = j = x = 1;
        while(j<cnt)
        {

            if(x == 1)
                sz+=flag1[j];
            if(x == 0)
                sz-=flag2[i-1];
            if(sz>=p)
            {
                int ans = mp2[j]-mp2[i];
                if(ans<mn)
                    mn = ans;
                if(i!=j)
                {
                    i++;
                    x = 0;
                }
                else
                {
                    j++;
                    x = 1;
                }
            }
            else
            {
                j++;
                x = 1;
            }
        }

        printf("Case %d: %d\n",ks++,mn);
    }

    return 0;
}
