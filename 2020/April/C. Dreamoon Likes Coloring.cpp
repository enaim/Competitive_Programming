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
int ans[100010];
int i,n,j,last,m;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
            scanf("%d",&ar[i]);

        int f = 1;
        for(i=m-1;i>=0;i--)
        {
            if(i==m-1)
            {
                ans[i]=n-ar[i]+1;
                last = ans[i];
                continue;
            }
            if(last-ar[i]>i)
            {
                ans[i]=last-ar[i];
                last = ans[i];
            }
            else
            {
                if(ar[i]+i>n)
                {
                    f = 0;
                    break;
                }
                ans[i]=i+1;
                last = i+1;
                for(j=i-1;j>=0;j--)
                {
                    if(ar[j]+j>n)
                    {
                        f = 0;
                        break;
                    }
                    ans[j]=j+1;
                    last = j+1;
                }
                break;
            }
        }
        for(i=0;i<m-1;i++)
            if(ans[i]>=ans[i+1])
            {
                f = 0;
                break;
            }
        if(f==0 || last!=1)
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<m;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }

    return 0;
}
