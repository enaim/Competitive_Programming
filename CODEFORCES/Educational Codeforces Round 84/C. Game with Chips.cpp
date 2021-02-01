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

    int i,j,n,m,a,b,k;
    while(3==scanf("%d%d%d",&n,&m,&k))
    {
        for(i=0;i<k*2;i++)
            scanf("%d%d",&a,&b);

        string ans="";
        for(i=0;i<n;i++)
            ans+="U";
        for(i=0;i<m;i++)
            ans+="L";
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                for(j=0;j<m-1;j++)
                    ans+="R";
                continue;
            }
            if(i%2==1)
            {
                ans+="D";
                for(j=0;j<m-1;j++)
                    ans+="L";
                continue;
            }
            else
            {
                ans+="D";
                for(j=0;j<m-1;j++)
                    ans+="R";
            }
        }
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }

    return 0;
}
