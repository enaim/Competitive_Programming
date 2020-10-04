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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,mx,cnt;
    while(1==scanf("%d",&n))
    {
        mx = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        i = 0;
        j = 0;
        cnt = 0;
        while(i<n && j<n)
        {
            if(ar[j]-ar[i]<=5)
            {
                cnt = j-i+1;
                j++;
            }
            else
            {
                cnt = 0;
                if(i==j)
                    j++;
                else
                    i++;
            }
            mx = max(mx,cnt);
        }
        printf("%d\n",mx);
    }

    return 0;
}
