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

int i,x,sz1,sz2,n,f;
int ar[200010];
int flag[200010];
vector<int>v1,v2;
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        v1.clear();
        v2.clear();
        f = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]),flag[ar[i]]++;
            if(flag[ar[i]]>=3)
                f = 1;
        }
        if(f)
        {
            printf("NO\n");
            continue;
        }
        sort(&ar[0],&ar[n]);
        v1.pb(ar[0]);
        for(i=1;i<n;i++)
            if(ar[i]==ar[i-1])
                v2.pb(ar[i]);
            else
                v1.pb(ar[i]);

        printf("Yes\n");
        sz1 = v1.size();
        sz2 = v2.size();

        printf("%d\n",sz1);
        for(i=0;i<sz1;i++)
            printf("%d ",v1[i]);
        printf("\n");
        sort(v2.rbegin(),v2.rend());
        printf("%d\n",sz2);
        for(i=0;i<sz2;i++)
            printf("%d ",v2[i]);
        printf("\n");
    }

    return 0;
}
