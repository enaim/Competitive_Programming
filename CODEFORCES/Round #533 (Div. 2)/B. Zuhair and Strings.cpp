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

char str[200010];
vector<int>vec[30];
int ar[30],i,j,cnt,n,k,x,sz;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&k))
    {
        scanf("%s",str);

        for(i=0;i<n;i++)
        {
            x = str[i]-'a';
            vec[x].pb(i);
        }
        for(i=0;i<26;i++)
        {
            sz = vec[i].size();
            cnt = 0;
            for(j=0;j<sz;j++)
            {
                if(j==0)
                    cnt++;
                else if(vec[i][j]==vec[i][j-1]+1)
                    cnt++;
                else
                    cnt = 1;
                if(cnt>=k)
                {
                    ar[i]++;
                    cnt = 0;
                }
            }
            if(cnt>=k)
                ar[i]++;
        }
        int mx = 0;
        for(i=0;i<26;i++)
            mx = max(mx,ar[i]);
        printf("%d\n",mx);
    }

    return 0;
}
