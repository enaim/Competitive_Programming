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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,ans,x,n,i,j,half,mx,sum;
    int dp[25010],ar[110];
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,0,sizeof dp);
        dp[0] = 1;

        scanf("%d",&n);
        
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum += ar[i];
        }

        half = sum/2;
        mx = 0;
        for(i=0;i<n;i++)
            for(j=half;j>=0 && 0<=j-ar[i];j--)
            {
                x = j-ar[i];
                if(dp[x])
                {
                    dp[j]=1;
                    if(j>mx)
                        mx = j;
                }
            }
        ans = sum-mx;
        printf("%d\n",ans-mx);
    }

    return 0;
}
