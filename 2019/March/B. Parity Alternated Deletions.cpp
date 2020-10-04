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

int ev[20010];
int od[20010];
int i,n,cnt1,cnt2,sum;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        cnt1=cnt2=sum=0;
        int x;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x%2==0)
                ev[cnt1++]=-x;
            else
                od[cnt2++]=-x;
        }
        sort(&ev[0],&ev[cnt1]);
        sort(&od[0],&od[cnt2]);
        if(cnt1==cnt2 || cnt1==cnt2+1 || cnt2==cnt1+1)
        {
            printf("0\n");
            continue;
        }
        if(cnt1<cnt2)
        {
            for(i=cnt1+1;i<cnt2;i++)
                sum+=od[i];
        }
        else
        {
            for(i=cnt2+1;i<cnt1;i++)
                sum+=ev[i];
        }
        printf("%d\n",abs(sum));
    }

    return 0;
}
