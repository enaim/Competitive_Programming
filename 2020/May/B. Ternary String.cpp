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

char str[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,j,ans,mn,mx;
        scanf("%s",str);
        n = strlen(str);
        int ar[3];
        ar[0]=ar[1]=ar[2]=-1;
        ans=OO;
        for(i=0;i<n;i++)
        {
            ar[str[i]-'1']=i;
            for(j=0;j<3;j++)
                if(ar[j]==-1)
                    break;
            if(j==3)
            {
                mn = min(ar[2],min(ar[0],ar[1]));
                mx = max(ar[2],max(ar[0],ar[1]));
                ans = min(ans,mx-mn+1);
            }
        }
        if(ans==OO)
            printf("0\n",ans);
        else
            printf("%d\n",ans);
    }

    return 0;
}
