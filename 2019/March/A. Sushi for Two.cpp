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

int ar[100010];
vector<int>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,cnt;
    while(1==scanf("%d",&n))
    {
        cnt = 0;
        vec.clear();
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<n;i++)
        {
            if(i==0)
                cnt++;
            else if(ar[i-1]!=ar[i])
            {
                if(ar[i-1]==1)
                    vec.pb(-cnt);
                else
                    vec.pb(cnt);
                cnt=1;
            }
            else
                cnt++;
        }
        vec.pb(cnt);
        int sz = vec.size();
        int mx= 0;
        for(i=0;i<sz-1;i++)
            mx = max(mx,min(abs(vec[i]),abs(vec[i+1])));

        printf("%d\n",mx*2);
    }

    return 0;
}
