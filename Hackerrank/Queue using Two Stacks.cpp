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

int ar[100010];
vector<int>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    int f = 0,x,i,n,z;
    stack<int>st[2];
    scanf("%d",&n);
    int d = 0,cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d",&z);
            st[0].push(z);
            cnt++;
        }
        if(x==2 && d+1<=cnt)
            d++;
        if(x==3)
            vec.pb(d);
    }
    i = 0;
    while(!st[0].empty())
        st[1].push(st[0].top()),st[0].pop();
    while(!st[1].empty())
        ar[i++] = st[1].top(),st[1].pop();
    int sz = vec.size();
    for(i=0;i<sz;i++)
        cout<<ar[vec[i]]<<endl;

    return 0;
}
