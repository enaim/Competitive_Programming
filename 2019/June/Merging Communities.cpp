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

vector<int>vec[100010];
int ar[100010];
int i,n,q,x,y;
char str[5];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&q))
    {
        for(i=1;i<=n;i++)
            vec[i].pb(i),ar[i]=i;
        while(q--)
        {
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d",&x);
                printf("%d\n",vec[ar[x]].size());
            }
            else
            {
                scanf("%d%d",&x,&y);
                int a = ar[x];
                int b = ar[y];
                if(a==b)
                    continue;
                if(vec[a].size()>vec[b].size())
                {
                    for(i=0;i<vec[b].size();i++)
                    {
                        vec[a].pb(vec[b][i]);
                        ar[vec[b][i]]=a;
                    }
                    vec[b].clear();
                }
                else
                {
                    for(i=0;i<vec[a].size();i++)
                    {
                        vec[b].pb(vec[a][i]);
                        ar[vec[a][i]]=b;
                    }
                    vec[a].clear();
                }
            }
        }
        printf("\n");
    }

    return 0;
}
