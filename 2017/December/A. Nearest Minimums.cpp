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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

    int n,x,i;
    while(1==scanf("%d",&n))
    {
        vector<int>vec[100010];
        map<int,int>mp;
        int mn = OO;
        int cnt = 1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(mp[x]==0)
                mp[x] = cnt++;
            vec[mp[x]].pb(i);
            if(x<mn)
                mn = x;
        }
        mn = mp[mn];
        int sz = vec[mn].size();
        int dis =  OO;
        for(i=0;i<sz-1;i++)
        {
            if(abs(vec[mn][i] - vec[mn][i+1]) < dis)
                dis = abs(vec[mn][i] - vec[mn][i+1]);
        }
        printf("%d\n",dis);
    }

    return 0;
}
