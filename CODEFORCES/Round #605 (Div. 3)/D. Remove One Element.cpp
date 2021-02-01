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

int ar[200010];
int flag[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        int l=0,r=1,cnt=1;
        flag[l]=1;
        while(r<n)
        {
            if(ar[r-1]<ar[r])
                r++,cnt++;
            else
            {
                for(i=l;i<r;i++)
                    flag[i]=cnt;
                cnt = 1;
                l = r;
                r++;
            }
            if(r==n)
            {
                for(i=l;i<r;i++)
                    flag[i]=cnt;
            }
        }
        int mx = max(flag[0],flag[n-1]);

        for(i=1;i<n-1;i++)
        {
            mx = max(mx,flag[i]);
            if(ar[i]>=ar[i+1] || ar[i-1]>=ar[i])
            {
                if(ar[i-1]<ar[i+1])
                {
                    if(ar[i-1]<ar[i])
                        mx = max(mx,flag[i-1]-1+flag[i+1]);
                    else if(ar[i]<ar[i+1])
                        mx = max(mx,flag[i-1]+flag[i+1]-1);
                    else
                        mx = max(mx,flag[i-1]+flag[i+1]);
                }
            }
        }
        printf("%d\n",mx);
    }

    return 0;
}
