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

int i,l,r,n,q,val;
int ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[1],&ar[n+1]);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&val);
            l = 1;
            r = n;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(ar[mid]<val)
                    l = mid+1;
                else
                    r = mid-1;
            }
            if(ar[r+1]==val)
                printf("Yes %d\n",r+1);
            else
                printf("No %d\n",r+1);
        }
    }

    return 0;
}
