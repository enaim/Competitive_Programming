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

    int ar[1010];
    int n,i,x,j,k,ans,y;

    while(1==scanf("%d",&n))
    {
        vector<int>vec;
        x = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&y);
            ar[i]=y-x;
            x = y;
        }
        ans = 0;
        for(i=1;i<=n;i++)
        {
            k = 1;
            for(j=1;j<=n;j++)
            {
                if(ar[k]==ar[j])
                {
                    k++;
                    if(k==i+1)
                        k = 1;
                }
                else
                    break;
            }
            if(j==n+1)
            {
                ans++;
                vec.pb(i);
            }
        }
        sort(vec.begin(),vec.end());
        cout<<ans<<endl;
        for(i=0;i<ans;i++)
            cout<<vec[i]<<" ";
        printf("\n");
    }

    return 0;
}
