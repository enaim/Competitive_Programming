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

vector<int>vec[1000010];

void divisor()
{
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            vec[j].push_back(i);
}

int ans[1000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    divisor();
    int i,j,x;
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for(i=4;i<=1000000;i++)
    {
        int sz = vec[i].size();
        ans[i] = ans[i-1]+1;
        for(j=0;j<(sz+1)/2;j++)
        {
            ans[i] = min(ans[i],ans[max(vec[i][j],(i/vec[i][j]))]+1);
        }
    }
    for(i=4;i<=1000000;i++)
    {
        int sz = vec[i].size();
        ans[i] = ans[i-1]+1;
        for(j=0;j<sz;j++)
        {
            ans[i] = min(ans[i],ans[max(vec[i][j],(i/vec[i][j]))]+1);
        }
    }

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }

    return 0;
}
