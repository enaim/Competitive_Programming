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

char str[510][510];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,m,cnt;
    while(2==scanf("%d%d",&n,&m))
    {
        cnt = 0;
        int firstRow = OO;
        int firstcolumn = OO;
        int lastRow = -OO;
        int lastcolumn = -OO;
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='X')
                {
                    firstRow = min(firstRow,i);
                    firstcolumn = min(firstcolumn,j);
                    lastRow = max(lastRow,i);
                    lastcolumn = max(lastcolumn,j);
                }
            }
        }

        int flag = 0;
        for(i=firstRow;i<=lastRow;i++)
        {
            for(j=firstcolumn;j<=lastcolumn;j++)
            {
                if(str[i][j]!='X')
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }

        if(!flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
