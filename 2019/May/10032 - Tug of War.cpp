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

bool flag[22510];
int ans[22510];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[110],i,sum,n,x,j,mx;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        sort(&ar[0],&ar[n],greater<int>());
        x = (sum+1)/2;
        for(i=0;i<=x;i++)
            flag[i]=false,ans[i]=0;

        flag[0]=true;
        ans[0]=0;
        mx = 0;
        for(i=0;i<n;i++)
        {
            for(j=x;j>=0;j--)
            {
                if(flag[j] && j+ar[i]<=x)
                {
                    flag[j+ar[i]]=true;
                    ans[j+ar[i]] = max(ans[j+ar[i]],ans[j]+1);

                    if(ans[j+ar[i]]==n/2 || ans[j+ar[i]]==(n+1)/2)
                        mx = max(mx,j+ar[i]);
                }
            }
        }

        if(ks>1)
            printf("\n");
        ks++;
        printf("%d %d\n",min(mx,sum-mx),max(mx,sum-mx));
    }

    return 0;
}
