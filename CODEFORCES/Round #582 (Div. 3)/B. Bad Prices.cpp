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


int ar[150010];
int br[150010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        int mn = OO;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=n-1;i>=0;i--)
        {
            br[i] = min(ar[i],mn);
            mn = min(ar[i],mn);
        }
        int cnt = 0;
        for(i=0;i<n;i++)
            if(ar[i]>br[i])
                cnt++;
        cout<<cnt<<endl;
    }

    return 0;
}
