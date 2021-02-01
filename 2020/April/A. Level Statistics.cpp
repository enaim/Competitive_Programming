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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,x,y,n,lastx,lasty;
        scanf("%d",&n);
        int flag = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x<y)
            {
                flag = 1;
                continue;
            }
            if(flag)
                continue;
            if(i==0)
            {
                lastx = x;
                lasty = y;
                continue;
            }
            if(x==lastx)
            {
                if(y==lasty)
                {
                    lastx = x;
                    lasty = y;
                    continue;
                }
                else
                    flag = 1;
                continue;
            }
            if(x>lastx)
            {
                int dify = y-lasty;
                int difx = x-lastx;
                if(!(difx>=dify  && dify>=0))
                    flag = 1;
                lastx = x;
                lasty = y;
                continue;
            }
            flag = 1;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
