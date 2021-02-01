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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[1010];
    int tks,ks=1,n,i,o,z,x,t;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        n = strlen(str);
        o = t = z = 0;
        for(i=0;i<n;i++)
        {
            x = str[i]-'0';
            x%=3;
            if(x==0)
                z++;
            if(x==1)
                o++;
            if(x==2)
                t++;
        }

        int ans=0;
        if(((t*2 + o*1)%3 == 1 && o) || ((t*2 + o*1)%3 == 2 && t))
            ans  = z + 1;
        else if(t%3==o%3)
            ans = z;

        if(ans%2==0)
            printf("Case %d: T\n",ks++);
        else
            printf("Case %d: S\n",ks++);
    }

    return 0;
}
