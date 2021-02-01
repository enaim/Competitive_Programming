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

int i,j,r,c,mn,mx,f;
int ar[60][60];
int br[60][60];
int cr[60][60];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&r,&c))
    {
        f = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&ar[i][j]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&br[i][j]);
        i = 0;
        for(j=0;j<c;j++)
        {
            if(i==j && i==0)
            {
                mn = min(ar[i][j],br[i][j]);
                mx = max(ar[i][j],br[i][j]);
                ar[i][j]=mn;
                br[i][j]=mx;
                continue;
            }
            mn = min(ar[i][j],br[i][j]);
            mx = max(ar[i][j],br[i][j]);
            if(mn>ar[i][j-1])
            {
                ar[i][j]=mn;
                br[i][j]=mx;
            }
            else if(mx>ar[i][j-1])
            {
                ar[i][j]=mx;
                br[i][j]=mn;
            }
            else
            {
                f = 1;
                break;
            }
        }
        j = 0;
        for(i=1;i<r;i++)
        {
            mn = min(ar[i][j],br[i][j]);
            mx = max(ar[i][j],br[i][j]);
            if(mn>ar[i-1][j])
            {
                ar[i][j]=mn;
                br[i][j]=mx;
            }
            else if(mx>ar[i-1][j])
            {
                ar[i][j]=mx;
                br[i][j]=mn;
            }
            else
            {
                f = 1;
                break;
            }
        }

        for(i=1;i<r;i++)
        {
            for(j=1;j<c;j++)
            {
                mn = min(ar[i][j],br[i][j]);
                mx = max(ar[i][j],br[i][j]);
                if(mn>ar[i][j-1] && mn > ar[i-1][j])
                {
                    ar[i][j]=mn;
                    br[i][j]=mx;
                }
                else if(mx>ar[i][j-1] && mx>ar[i-1][j])
                {
                    ar[i][j]=mx;
                    br[i][j]=mn;
                }
                else
                    f = 1;
            }
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(ar[i][j]>ar[i-1][j] && ar[i][j]>ar[i][j-1])
                    continue;
                else
                    f = 1;
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(br[i][j]>br[i-1][j] && br[i][j]>br[i][j-1])
                    continue;
                else
                    f = 1;
            }
        }

        if(f)
            printf("Impossible\n");
        else
            printf("Possible\n");
    }

    return 0;
}
