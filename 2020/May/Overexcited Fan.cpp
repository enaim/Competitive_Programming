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
node ar[10010];
char str[10010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,a,b;
        scanf("%d%d",&a,&b);
        scanf("%s",&str);
        n = strlen(str);
        if(a==b && a==0)
        {
            printf("Case #%d: 0\n",ks++);
            continue;
        }

        ar[0].x = -a;
        ar[0].y = b;
        for(i=1;i<=n;i++)
        {
            char ch = str[i-1];
            if(ch=='E')
            {
                ar[i].x = ar[i-1].x-1;
                ar[i].y = ar[i-1].y;
            }
            else if(ch=='W')
            {
                ar[i].x = ar[i-1].x+1;
                ar[i].y = ar[i-1].y;
            }
            else if(ch=='N')
            {
                ar[i].x = ar[i-1].x;
                ar[i].y = ar[i-1].y+1;
            }
            else
            {
                ar[i].x = ar[i-1].x;
                ar[i].y = ar[i-1].y-1;
            }
        }
        int mn = OO;
        for(i=1;i<=n;i++)
        {
            a = ar[i].x;
            b = ar[i].y;
            int need = abs(a)+abs(b);
            if(need<=i)
                mn = min(mn,i);
        }
        if(mn==OO)
            printf("Case #%d: IMPOSSIBLE\n",ks++);
        else
            printf("Case #%d: %d\n",ks++,mn);
    }

    return 0;
}
