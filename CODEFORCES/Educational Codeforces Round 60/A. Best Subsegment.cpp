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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

//int dr[]={1, 0, 0,-1};                //4 Direction
//int dc[]={0,-1, 1, 0};

//int dr[]={-1,-1,-1, 0, 0, 1, 1, 1;    //8 direction
//int dc[]={-1, 0, 1,-1, 1,-1, 0, 1};

//int dr[]={ 1, 1,-1,-1,-2, 2,-2, 2;    //Knight Direction
//int dc[]={-2, 2,-2, 2, 1, 1,-1,-1};


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[100010];
    int i,mx,ans,n;

    while(1==scanf("%d",&n))
    {
        mx=ans= 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            mx = max(mx,ar[i]);
        }
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            if(ar[i]==mx)
                cnt++;
            else
                cnt = 0;
            ans = max(ans,cnt);
        }
        printf("%d\n",ans);
    }

    return 0;
}
