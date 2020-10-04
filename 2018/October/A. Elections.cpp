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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;

    while(1==scanf("%d",&n))
    {
        int i,mx = -1,x,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
            mx = max(x,mx);
        }
        int t = mx*n;
        x = t-sum;

        if(x==0)
        {
            x = (sum+1)/n;
            if((sum+1)%n!=0)
                x++;
            printf("%d\n",mx+x);
            continue;
        }
        if(x > sum)
            printf("%d\n",mx);
        else
        {
            int di = sum-x;
            x = (di+1)/n;
            if((di+1)%n!=0)
                x++;
            printf("%d\n",x+mx);
        }
    }

    return 0;
}
