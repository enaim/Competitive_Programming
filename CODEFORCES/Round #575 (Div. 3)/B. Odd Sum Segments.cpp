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

int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n,k;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&k);
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]%2!=0)
                cnt++;
        }
        if(cnt<k)
        {
            printf("NO\n");
            continue;
        }
        int x = cnt - k;
        x++;
        if(x%2==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int c1 = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]&1)
                c1++;
            if(c1==x)
            {
                k--;
                if(k!=0)
                    printf("%d ",i+1);
                else if(k==0)
                    printf("%d\n",n);
                x = 1;
                c1 = 0;
            }
        }
    }

    return 0;
}
