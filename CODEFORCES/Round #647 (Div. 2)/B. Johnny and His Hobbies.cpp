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

int ar[1050];
int flag[1050];
int flag1[1050];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n;
        memset(flag,0,sizeof flag);
        memset(flag1,0,sizeof flag1);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            flag[ar[i]]++;
        }

        int ans = -1;
        for(i=1;i<=1024;i++)
        {
            for(j=0;j<n;j++)
                flag1[(ar[j]^i)]++;
            for(j=0;j<=1029;j++)
                if(flag[j]!=flag1[j])
                    break;
            if(j==1030)
            {
                ans = i;
                break;
            }
            memset(flag1,0,sizeof flag1);
        }
        printf("%d\n",ans);
    }

    return 0;
}
