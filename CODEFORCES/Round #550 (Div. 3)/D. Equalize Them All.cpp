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

int ar[200010];
int flag[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,mx=-OO,ans;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            flag[ar[i]]++;
            if(mx<flag[ar[i]])
            {
                ans = ar[i];
                mx = flag[ar[i]];
            }
        }
        printf("%d\n",n-mx);
        vector<int>vec;
        for(i=1;i<=n;i++)
            if(ar[i]==ans)
                vec.pb(i);
        int cnt = 0;
        for(i=vec[0]-1;i>=1;i--)
        {
            if(ar[i]<ar[i+1])
                printf("1 %d %d\n",i-cnt,i+1-cnt);
            else
                printf("2 %d %d\n",i-cnt,i+1-cnt);
            ar[i]=ar[i+1];
        }
        for(i=vec[0];i<n;i++)
        {
            if(ar[i]==ar[i+1] && ar[i]==ans)
                continue;
            if(ar[i]==ans && ar[i+1]!=ans)
            {
                if(ar[i]<ar[i+1])
                    printf("2 %d %d\n",i+1,i);
                else
                    printf("1 %d %d\n",i+1,i);
                ar[i+1]=ar[i];
            }
        }
    }

    return 0;
}
