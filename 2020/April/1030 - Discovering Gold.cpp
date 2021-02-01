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

double ar[110];
double ans[110];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,cnt;
        double sum;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&ar[i]);

        for(i=n-2;i>=0;i--)
        {
            cnt = 0;
            sum = 0.0;
            for(j=1;j<=6;j++)
            {
                if(i+j>=n)
                    continue;
                cnt++;
                sum+=ar[i+j];
            }
            ar[i]+=(sum/cnt);
        }
        printf("Case %d: %.6lf\n",ks++,ar[0]);
    }

    return 0;
}
