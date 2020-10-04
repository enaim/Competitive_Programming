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

    int tks,ks=1,i,n,mid,l,r,L,R,q,a,b;
    int ar[100010];
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        while(q--)
        {
            scanf("%d%d",&L,&R);
            l = 0;
            r= n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(ar[mid]<L)
                    l = mid+1;
                else
                    r = mid-1;
            }
            a = mid;
            l = 0;
            r= n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(ar[mid]>R)
                    r = mid-1;
                else
                    l = mid+1;
            }
            b = mid;
            if(ar[a]<L && a<n-1)
                a++;
            if(ar[b]>R && b>0)
                b--;
            if(a<=b && ar[a]>=L && ar[b]<=R)
                printf("%d\n",b-a+1);
            else
                printf("0\n");
        }
    }

    return 0;
}
