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

int clr[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,j;
    int ar[100010];
    while(1==scanf("%d",&n))
    {
        map<int,int>mp;
        set<int>st;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            mp[ar[i]]++;
            st.insert(ar[i]);
        }
        int sz = st.size();
        ll sum = 0;
        for(i=0;i<n-1;i++)
        {
            mp[ar[i]]--;
            if(mp[ar[i]]==0)
                    sz--;
            if(clr[ar[i]]==0)
                sum+=sz;
            clr[ar[i]]=1;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
