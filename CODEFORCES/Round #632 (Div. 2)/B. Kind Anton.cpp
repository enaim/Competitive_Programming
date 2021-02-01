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

map<int,int>mp;
int ar[100010];
int br[100010];
vector<int>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        vec.clear();
        int i,j,cnt=0,x,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(mp[ar[i]]==0)
                mp[ar[i]]=i+1;
        }

        for(i=0;i<n;i++)
            scanf("%d",&br[i]);

        int f = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]==br[i])
                continue;
            if(ar[i]<br[i] && mp[1]<=i && mp[1]>0)
                continue;
            if(ar[i]>br[i] && mp[-1]<=i && mp[-1]>0)
                continue;
            else
            {
                f = 1;
                break;
            }
        }
        if(f)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
