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

int ar[200010];
int flag[110];
int i,n,k,sum;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        sum = 0;
        memset(flag,0,sizeof flag);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            flag[ar[i]%k]++;
        }
        for(i=0;i<=k/2;i++)
        {
            if(i==0 || i==k-i)
                sum += (flag[i]/2);
            else
                sum += min(flag[i],flag[k-i]);
        }
        printf("%d\n",sum*2);
    }

    return 0;
}
