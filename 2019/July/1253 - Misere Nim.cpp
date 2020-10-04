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
    int tks,ks=1,i,p,cnt,n,x;
    scanf("%d",&tks);
    while(tks--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            ans^=ar[i];
        }
        for(i=0;i<n;i++)
        {
            if(ar[i]==1)
                continue;
            break;
        }
        if(i==n && n&1)
            ans = 0;
        if(i==n && n%2==0)
            ans = 1;
        if(ans==0)
            printf("Case %d: Bob\n",ks++);
        else
            printf("Case %d: Alice\n",ks++);
    }

    return 0;
}
