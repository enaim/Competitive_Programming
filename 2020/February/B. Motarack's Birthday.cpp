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

int ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        int mn = OO,mx= -OO,i,cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]==-1)
            {
                cnt++;
                continue;
            }
            mn = min(mn,ar[i]);
            mx = max(mx,ar[i]);
        }
        if(cnt==n)
        {
            printf("0 0\n");
            continue;
        }
        int l=mn,r=mx,mid,ans=OO,k,temp1,temp2,temp,a,b;
        while(l<=r)
        {
            mid = (l+r)/2;
            temp = -OO;
            for(i=1;i<n;i++)
            {
                a = ar[i-1];
                b = ar[i];
                if(a==-1)
                    a = mid;
                if(b==-1)
                    b = mid;
                temp = max(temp,abs(a-b));
            }
            if(ans>temp)
            {
                ans = temp;
                k = mid;
            }

            int x = mid;
            mid = ((x-1)+l)/2;
            temp1 = -OO;
            for(i=1;i<n;i++)
            {
                a = ar[i-1];
                b = ar[i];
                if(a==-1)
                    a = mid;
                if(b==-1)
                    b = mid;
                temp1 = max(temp1,abs(a-b));
            }
            if(ans>temp1)
            {
                ans = temp1;
                k = mid;
            }

            temp2 = -OO;
            mid = ((x+1)+r)/2;
            for(i=1;i<n;i++)
            {
                a = ar[i-1];
                b = ar[i];
                if(a==-1)
                    a = mid;
                if(b==-1)
                    b = mid;
                temp2 = max(temp2,abs(a-b));
            }
            if(ans>temp2)
            {
                ans = temp2;
                k = mid;
            }

            if(temp1>temp2)
                l = x+1;
            else
                r = x-1;
        }
        printf("%d %d\n",ans,k);
//        printf("Case %d: ",ks++);
    }

    return 0;
}
