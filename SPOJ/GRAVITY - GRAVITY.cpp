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
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

struct go{
    int i,j,k;
};

int m,n,ti,tj,o;
char str[110][110];

int dr[] = {-1,-1,-1, 0,0, 1,1,1};
int dc[] = {-1, 0, 1,-1,1,-1,0,1};

int flag[110][110];

bool bfs(go a)
{
    queue<go>Q;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {
            int p = a.i+ dr[i];
            int q = a.j+ dc[i];
            if((p>=0 && p<m && q>=0 && q<n))
            {
                if(str[p][q]!='#' && flag[p][q])
                {
                    if(str[p][q]=='T' && a.k+1<=o)
                        return true;
                    flag[p][q]=0;
                    go t;
                    t.i = p;
                    t.j = q;
                    t.k = a.k+1;
                    Q.push(t);
                }
            }
        }
    }
    return false;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,si,sj;
    char ch;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,1,sizeof flag);
        scanf("%d%d%d",&o,&m,&n);
        scanf("%c",&ch);

        for(int i=0;i<m;i++)
        {
            cin.getline(str[i],110);
            for(int j=0;j<n;j++)
            {
                if(str[i][j]=='S')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        go a;
        a.i = si;
        a.j = sj;
        a.k = 0;
        bool x = bfs(a);
        if(x)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
