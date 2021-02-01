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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[1010];
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int high,low,ans,n,k,i;
        scanf("%d%d",&n,&k);
        high = low = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            low = max(ar[i],low);
            high+=ar[i];
        }
        ans = OO;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int part = 1;
            int part_sum = 0;
            for(i=0;i<n;i++)
            {
                if(part_sum+ar[i]>mid)
                {
                    part++;
                    part_sum = ar[i];
                }
                else
                    part_sum += ar[i];
            }
            if(part<=k)
            {
                ans = min(ans,mid);
                high = mid-1;
            }
            else
                low = mid+1;
        }
        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
