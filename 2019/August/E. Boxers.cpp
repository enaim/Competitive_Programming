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

int ar[150010];
int flag[150010];
int i,n;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        memset(flag,0,sizeof flag);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(&ar[0],&ar[n]);
        for(i=0;i<n;i++)
        {
            if(flag[ar[i]-1]==0 && ar[i]>1)
                flag[ar[i]-1]++;
            else if(flag[ar[i]]==0)
                flag[ar[i]]++;
            else if(flag[ar[i]+1]==0)
                flag[ar[i]+1]++;
        }
        int cnt = 0;
        for(i=1;i<=150001;i++)
            if(flag[i])
                cnt++;

        printf("%d\n",cnt);
    }

    return 0;
}
