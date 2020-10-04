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

int flag[100010];
map<int,int>mp;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        int i,n,x;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            flag[i]=0;
            scanf("%d",&x);
            mp[x]=i;
        }
        int f = 0;
        for(i=1;i<=n;i++)
        {
            int pos = mp[i];
            int start = i;
            for(int j=pos;j<=n;j++)
            {
                if(flag[j])
                    break;
                if(mp[start]==j)
                    start++,
                    flag[j]=1;
                else
                {
                    f = 1;
                    break;
                }
            }
            i = start-1;
            if(f)
                break;
        }
        if(f)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
