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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int ar[110];
    int br[110];
    map<int,int>mp;
    int i,j,n,m;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            mp[ar[i]]++;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&br[i]);
            mp[br[i]]++;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(mp[ar[i]+br[j]]==0)
                    break;
            if(mp[ar[i]+br[j]]==0 && j<m)
                break;
        }
        printf("%d %d\n",ar[i],br[j]);
    }

    return 0;
}
