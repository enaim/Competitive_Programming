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
int br[100010];
int cr[100010];
int i,j,n,ans,sum;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        for(i=0;i<n;i++)
        {
            sum = 0;
            br[i]=0;
            j = i-1;
            while(j>=0 && ar[j]<ar[i])
            {
                sum+=ar[j];
                br[i]=max(sum,br[i]);
                j--;
            }
        }
        for(i=0;i<n;i++)
        {
            sum = 0;
            cr[i]=0;
            j = i+1;
            while(j<n && ar[j]<ar[i])
            {
                sum+=ar[j];
                cr[i]=max(sum,cr[i]);
                j++;
            }
        }

        for(i=0;i<n;i++)
        {
            sum = 0;
            j = i-1;
            while(j>=0 && ar[j]<=ar[i])
            {
                sum+=ar[j];
                if(ar[j]==ar[i])
                {
                    br[i]=max(br[i],br[j]+sum);
                    break;
                }
                j--;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            sum = 0;
            j = i+1;
            while(j<n && ar[j]<=ar[i])
            {
                sum+=ar[j];
                if(ar[j]==ar[i])
                {
                    cr[i]=max(cr[i],cr[j]+sum);
                    break;
                }
                j++;
            }
        }
        int ans = 0;
        for(i=0;i<n;i++)
            ans = max(ans,br[i]+cr[i]);

        printf("%d\n",ans);
    }

    return 0;
}
