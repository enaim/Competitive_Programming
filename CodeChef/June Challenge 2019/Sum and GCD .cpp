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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    set<int,greater<int>>st;
    int tks,ks=1,x,i,y,n,sum,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&x),st.insert(x);

        if(st.size()==1)
        {
            printf("%d\n",x+x);
            continue;
        }

        sum = 0;
        int sz = st.size();
        for(i=1;i<=min(sz,2);i++)
        {
            cnt = 0;
            x = 0;
            y = 0;
            for(auto it : st)
            {
                cnt++;
                if(cnt==i)
                    x = it;
                else
                    y = __gcd(it,y);
            }
            sum = max(x+y,sum);
        }

        printf("%d\n",sum);
    }

    return 0;
}
