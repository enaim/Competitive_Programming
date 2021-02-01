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

int ar[400010];
int i,mx,j,cnt;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;
    while(1==scanf("%d",&n))
    {
        mx = cnt = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(j=n;j<2*n;j++)
            ar[j]=ar[j-n];
        for(i=0;i<2*n;i++)
            if(ar[i]==1)
                cnt++;
            else
                mx = max(mx,cnt),cnt = 0;
        printf("%d\n",mx);
    }

    return 0;
}
