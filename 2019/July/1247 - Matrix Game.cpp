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

    int tks,ks=1,i,j,m,n,x,ans,sum;
    scanf("%d",&tks);
    while(tks--)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            int sum=0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                sum+=x;
            }
            ans^=sum;
        }
        if(ans)
            printf("Case %d: Alice\n",ks++);
        else
            printf("Case %d: Bob\n",ks++);
    }

    return 0;
}
