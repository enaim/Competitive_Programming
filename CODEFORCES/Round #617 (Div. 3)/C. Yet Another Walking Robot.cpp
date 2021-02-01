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

map<pii,int>mp;
char str[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,x,y,a,b;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        scanf("%d",&n);
        scanf("%s",str);
        pii pos = make_pair(0,0);
        mp[pos]=-1;
        x = y = 0;
        int ans = OO;
        for(i=0;i<n;i++)
        {
            if(str[i]=='L')
                x--;
            if(str[i]=='R')
                x++;
            if(str[i]=='U')
                y++;
            if(str[i]=='D')
                y--;;
            pos = make_pair(x,y);
            if(mp.find(pos)==mp.end())
                mp[pos]=i;
            else
            {
                if(i-mp[pos]<ans)
                {
                    ans = i-mp[pos];
                    a = mp[pos]+1;
                    b = i;
                }
                mp[pos]=i;
            }
        }
        if(ans==OO)
            printf("-1\n");
        else
            printf("%d %d\n",a+1,b+1);
    }

    return 0;
}
