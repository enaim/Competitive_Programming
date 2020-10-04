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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,n;
    int ar[110];
    int flag[110];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            flag[i]=0;
        }
        for(i=1;i<=n-1;i++)
        {
            for(j=1;j<n;j++)
            {
                if(ar[j]==i && ar[j-1]>ar[j] && flag[j-1]==0)
                {
                    swap(ar[j],ar[j-1]);
                    flag[j-1]=1;
                    j--;
                    j--;
                }
                if(ar[j]==i)
                    break;
            }
        }
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
