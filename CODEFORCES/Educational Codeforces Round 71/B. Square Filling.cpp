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

struct node{
    int x,y;
};
node ans[2510];
int ar[60][60];
int br[60][60];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int r,c,i,j;
    while(2==scanf("%d%d",&r,&c))
    {
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&ar[i][j]);

        int cnt,f,m,n;
        cnt = f = 0;
        for(i=0;i<r-1;i++)
        {
            for(j=0;j<c-1;j++)
            {
                m = i;
                n = j;
                if(ar[i][j]==1 && ar[i+1][j]==1 && ar[i][j+1]==1 && ar[i+1][j+1]==1)
                {
//                    if(i+1==r || j+1==c)
//                    {
//                        if(i+1==r)
//                            i--;
//                        if(j+1==c)
//                            j--;
//                        br[i][j] = 1;
//                        br[i+1][j] = 1;
//                        br[i][j+1] = 1;
//                        br[i+1][j+1] = 1;
//                        node a;
//                        a.x = i+1;
//                        a.y = j+1;
//                        ans[cnt++] = a;
//                        continue;
//                    }
                    br[i][j] = 1;
                    br[i+1][j] = 1;
                    br[i][j+1] = 1;
                    br[i+1][j+1] = 1;
                    node a;
                    a.x = i+1;
                    a.y = j+1;
                    ans[cnt++] = a;
                }
                i = m;
                j = n;
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                if(ar[i][j]!=br[i][j])
                {
                    f =  1;
                    break;
                }
            if(f)
                break;
        }
        if(f)
        {
            printf("-1\n");
            return 0;
        }
        cout<<cnt<<endl;
        for(i=0;i<cnt;i++)
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }

    return 0;
}
