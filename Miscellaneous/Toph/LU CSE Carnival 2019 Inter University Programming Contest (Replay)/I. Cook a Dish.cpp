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

set<char>st;
char str[1100];
int ar[1100];
int i,k;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int f=0,a;
        st.clear();
        scanf("%s%d",str,&k);
        int n = strlen(str);
        for(i=0;i<n;i++)
        {
            if(str[i]=='0')
                f = 1;
            st.insert(str[i]);
        }
        n = st.size();
        a = n;
        if(f==1)
            a--;
        n--;
        int ans = a;
        for(i=n;i>(n-(k-1));i--)
            ans*=i;
        cout<<ans<<endl;
    }

    return 0;
}
