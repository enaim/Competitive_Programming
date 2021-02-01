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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

int dr[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dc[]={-1, 0, 1,-1, 1,-1, 0, 1};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,m,i,j,k,x,y;
    char str[110][110];
    while(2==scanf("%d%d",&n,&m))
    {
        bool ans = true;
        for(i=0;i<n;i++)
            scanf("%s",&str[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int cnt = 0;
                if(str[i][j]!='.' && str[i][j]!='*')
                {
                    for(k=0;k<8;k++)
                    {
                        x = i+dr[k];
                        y = j+dc[k];
                        if(str[x][y]=='*' && x>=0 && x<=n && y<=m && y>=0)
                        {
                            cnt++;
                        }
                    }
                    if(cnt != str[i][j]-'0')
                        ans = false;
                }
                else if(str[i][j]=='.')
                {
                    for(k=0;k<8;k++)
                    {
                        x = i+dr[k];
                        y = j+dc[k];
                        if(str[x][y]=='*' && x>=0 && x<=n && y<=m && y>=0)
                        {
                            ans = false;
                        }
                    }
                }
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
