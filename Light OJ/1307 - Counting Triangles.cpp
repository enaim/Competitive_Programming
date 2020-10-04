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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[2010];
    int tks,ks=1,l,r,sum,i,j,n,x,mid;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        sort(&ar[0],&ar[n]);

        sum = 0;
        for(i=0;i<n-2;i++)
            for(j=i+1;j<n-1;j++)
            {
                x = ar[i]+ar[j]-1;
                l = 0;
                r = n-1;
                while(l<=r)
                {
                    mid = (l+r)/2;
                    if(ar[mid]>x)
                        r = mid-1;
                    else
                        l = mid+1;
                }
                sum+=(l-1-j);
            }
        printf("Case %d: %d\n",ks++,sum);
    }

    return 0;
}
