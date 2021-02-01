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

int ar[200010];
int br[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        int cnt = 0;
        ar[n]=ar[0];
        for(i=0;i<n;i++)
        {
            if(ar[i]!=ar[i+1])
                break;
        }

        int ans = 2;
        if(i==n)
            ans = 1;

        int temp = -1;
        if(ans==2 && n%2==1)
        {
            ans = 3;
            for(i=0;i<n;i++)
            {
                if(ar[i]==ar[i+1])
                {
                    temp = i;
                    ans = 2;
                    break;
                }
            }
        }

        if(ans==1)
        {
            for(i=0;i<n;i++)
                br[i]=0;
        }

        if(ans==2)
        {
            int f = 0;
            temp = max(temp+1,0);
            for(i=0;i<n;i++)
            {
                br[(temp+i)%n] = f;
                f = !f;
            }
        }
        if(ans==3)
        {
            int f = 0;
            for(i=0;i<n;i++)
            {
                br[i]=f;
                f=!f;
            }
            br[n-1]=2;
        }
        cout<<ans<<endl;
        for(i=0;i<n;i++)
            printf("%d ",br[i]+1);
        cout<<endl;
    }

    return 0;
}
