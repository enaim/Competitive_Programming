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

template<class T> T abs(T x)
{
    if(x<0)
        return -x;
    return x;
}
template<class T>T sqr(T a)
{
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int ar[4010];
    int i,n,j;
    scanf("%d",&tks);
    while(tks--)
    {
        int f = 0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&ar[i]);
            ar[i+n]=ar[i];
        }
        if(n==1)
        {
            printf("YES\n");
            continue;
        }
        int cnt;
        for(i=1; i<=n*2; i++)
        {
            cnt = 1;
            for(j=i; j<i+n; j++)
            {
                if(ar[j]!=cnt)
                    break;
                else
                    cnt++;
            }
            if(cnt==n+1)
            {
                f = 1;
                break;
            }
        }
        if(f==0)
        {
            for(i=1; i<=n*2; i++)
            {
                cnt = n;
                for(j=i; j<i+n; j++)
                {
                    if(ar[j]!=cnt)
                        break;
                    else
                        cnt--;
                }
                if(cnt==0)
                {
                    f = 1;
                    break;
                }
            }
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
