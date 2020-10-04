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

int n,i,x,l,r,q;
int sum[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(i==0)
                sum[i]=x;
            else
                sum[i]=sum[i-1]+x;
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            if(l>r)
                swap(l,r);
            if(l==0)
                printf("%d\n",sum[r]);
            else
                printf("%d\n",sum[r]-sum[l-1]);
        }
    }

    return 0;
}
