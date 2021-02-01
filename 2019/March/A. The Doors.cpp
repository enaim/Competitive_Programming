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

int i,x,n,ar[200010],cnt,cnt1;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        cnt=cnt1=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ar[i]=x;
            if(x==0)
                cnt++;
            else
                cnt1++;
        }
        for(i=0;i<n;i++)
        {
            if(ar[i]==0)
                cnt--;
            else
                cnt1--;
            if(cnt==0 || cnt1==0)
                break;
        }
        printf("%d\n",i+1);
    }

    return 0;
}
