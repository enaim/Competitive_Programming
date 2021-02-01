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
int sum[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,k;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            flag[i]=0;
            scanf("%d",&ar[i]);
        }

        for(i=1;i<n-1;i++)
        {
            if(ar[i-1]<ar[i] && ar[i]>ar[i+1])
                flag[i]=1;
        }

        sum[0]=0;
        for(i=1;i<n;i++)
            sum[i]=sum[i-1]+flag[i];

        int ind = 0,mx = -1;
        for(i=0;i+k-1<n;i++)
        {
            int right = sum[i+k-2];
            int left = sum[i];
            int val = right - left;
            if(val>mx)
            {
                mx = val;
                ind = i;
            }
        }
        printf("%d %d\n",mx+1,ind+1);
    }

    return 0;
}
