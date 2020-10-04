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

int ar[5010];
map<int,int>mp,mp1;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        mp1.clear();
        int i,n,f=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            if(mp[ar[i]]!=0 && abs(i-mp[ar[i]])>=2)
                f = 1;
            mp[ar[i]]=i;
            mp1[ar[i]]++;
            if(mp1[ar[i]]==3)
                f = 1;
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
