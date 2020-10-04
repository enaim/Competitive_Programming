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

int cnt,ar[10],br[10],i,j,cnt1;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&ar[0]))
    {
        cnt = cnt1 = 0;
        for(i=1;i<6;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<6;i++)
            scanf("%d",&br[i]);

        for(i=0;i<6;i++)
            for(j=0;j<6;j++)
                if(ar[i]>br[j])
                    cnt++;
                else if(ar[i]<br[j])
                    cnt1++;

        double ans = double(cnt)/(cnt1+cnt);

        printf("%.5f\n",ans);
    }

    return 0;
}
