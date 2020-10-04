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

    int ar[100010];
    int br[100010];
    int cr[100010];
    int tks,ks=1,cnt1,cnt2,i,x,y,n;
    scanf("%d",&tks);
    while(tks--)
    {
        cnt1 = cnt2 = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        x = ar[0]-ar[1];
        y = ar[n-1]-ar[n-2];
        br[0]=ar[0];
        br[1]=ar[1];
        for(i=0;i<n-1;i++)
        {
            if(br[i]-br[i+1]!=x)
                br[i+1]=br[i]-x;
        }
        cr[n-1]=ar[n-1];
        cr[n-2]=ar[n-2];
        for(i=n-1;i>0;i--)
        {
            if(cr[i]-cr[i-1]!=y)
                cr[i-1]=cr[i]-y;
        }
        for(i=0;i<n;i++)
        {
            if(ar[i]!=br[i])
                cnt1++;
            if(ar[i]!=cr[i])
                cnt2++;
        }
        if(cnt1>cnt2)
        {
            for(i=0;i<n;i++)
            {
                if(i==0)
                    printf("%d",cr[i]);
                else
                    printf(" %d",cr[i]);
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(i==0)
                    printf("%d",br[i]);
                else
                    printf(" %d",br[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
