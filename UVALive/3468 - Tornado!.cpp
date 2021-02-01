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

int ar[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n;
    while(1==scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        if(n==1 && ar[0]==0)
        {
            printf("1\n");
            continue;
        }
        for(i=0;i<n;i++)
            if(ar[i]==1)
                break;
        if(i==n)
        {
            printf("%d\n",(n+1)/2);
            continue;
        }
        for(i=0;i<n;i++)
            ar[n+i]=ar[i];

        int cnt = 0,sum=0,mn = OO;
        for(j=0;j<n;j++)
        {
            if(ar[j]==0)
                continue;
            cnt = sum = 0;
            for(i=j;i<j+n;i++)
            {
                if(ar[i]==0)
                    cnt++;
                else
                    sum+=(cnt/2),cnt=0;
            }
            sum+=cnt/2;
            mn = min(mn,sum);
            break;
        }

        printf("%d\n",mn);
    }

    return 0;
}
