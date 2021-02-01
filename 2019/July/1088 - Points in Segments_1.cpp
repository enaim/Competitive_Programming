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

int ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n,q,a,b;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int l,r,mid;

        printf("Case %d:\n",ks++);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            l = 0;
            r = n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(ar[mid]<a)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            a = r+1;

            l = 0;
            r = n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(ar[mid]>b)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            b = l-1;

            printf("%d\n",b-a+1);
        }
    }

    return 0;
}
