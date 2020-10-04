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

double ar[100010];
vector<int>vec;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    ar[1] = 0.0;
    for(i=2;i<=1e5;i++)
    {
        vec.clear();
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                vec.pb(i/j);
                if(i/j != j)
                    vec.pb(j);
            }
        }

        int sz = vec.size();
        double sum=0.0;
        for(j=0;j<sz;j++)
        {
            if(vec[j]==i)
                continue;
            sum += ar[vec[j]];
        }
        ar[i] = (sum+sz)/(sz-1.0);
    }

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %.6lf\n",ks++,ar[n]);;
    }

    return 0;
}
