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

int flag[30];
int ar[2010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,cnt1,cnt2;
        memset(flag,0,sizeof flag);
        scanf("%d",&n);
        int mx = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            flag[ar[i]]++;
            mx = max(mx,flag[ar[i]]);
        }
        for(i=1;i<=26;i++)
        {
            for(j=1;j<=26;j++)
            {
                if(i==j)
                    continue;
                int x = 0;
                int y = n-1;
                int sz = flag[j];
                cnt1 = cnt2 = 0;
                while(x<y)
                {
                    while(ar[x]!=i && x<y)
                    {
                        if(ar[x]==j)
                            sz--;
                        x++;
                    }
                    if(x==y)
                        break;
                    cnt1++;
                    while(ar[y]!=i && x<y)
                    {
                        if(ar[y]==j)
                            sz--;
                        y--;
                    }
                    if(x==y)
                        break;
                    cnt2++;
                    if(cnt1==cnt2)
                        mx = max(mx,cnt1+cnt2+sz);
                    x++;
                    y--;
                }
            }
        }
        printf("%d\n",mx);
    }

    return 0;
}
