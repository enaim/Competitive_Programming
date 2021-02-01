#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int dr[] = {-1,-1,-1, 0,0, 1,1,1};
int dc[] = {-1, 0, 1,-1,1,-1,0,1};

typedef pair<int,int>pii;
typedef pair<int,pii>pipii;

int ar[710][710];
int clr[710][710];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int cnt,i,j,r,c,m,n;
    pipii b;
    pii a;
    vector<pipii>vec;
    stack<pii>stk;

    while(2==scanf("%d%d",&r,&c))
    {
        vec.clear();
        memset(clr,0,sizeof clr);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&ar[i][j]);
                a = make_pair(i,j);
//                a = pii(i,j);
                b = make_pair(ar[i][j],a);
                vec.push_back(b);
            }
        }
            sort(vec.rbegin(),vec.rend());
            cnt = 0;
            for(int i=0;i<vec.size();i++)
            {
                a  = vec[i].second;
                if(!clr[a.first][a.second] && ar[a.first][a.second] != 0)
                {
                    clr[a.first][a.second] = 1;
                    cnt++;
                    stk.push(a);
                }
                while(!stk.empty())
                {
                    pii top = stk.top();
                    stk.pop();
                    for(int j=0;j<8;j++)
                    {
                        int m = top.first + dr[j];
                        int n = top.second + dc[j];
                        if(clr[m][n] == 0 && ar[m][n] <= ar[top.first][top.second]
                                    && (m>=0 && n>=0 && m<r && n<c) && ar[m][n] != 0)
                        {
                            clr[m][n] = 1;
                            stk.push(make_pair(m,n));
                        }
                    }
                }
            }
        printf("%d\n",cnt);
    }

    return 0;
}
