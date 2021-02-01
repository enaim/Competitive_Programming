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

int f[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int ar[200],i,j,n,ans;
    while(1==scanf("%d",&n))
    {
        set<int>st;
        st.clear();
       for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            f[ar[i]]++;
        }
        sort(&ar[0],&ar[n]);
        for(j=0;j<n-1;j++)
        {
            if(ar[n-1]%ar[j]!=0)
                st.insert(ar[j]);

            if(f[ar[j]]==2)
                st.insert(ar[j]);
        }
        for(auto it : st)
            ans = it;
       printf("%d %d\n",ar[n-1],ans);
    }

    return 0;
}
