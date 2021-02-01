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

    char str[210];
    int ar[1010][30];
    int tks,ks=1,n,i,j,cnt,len;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(ar,0,sizeof ar);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            len = strlen(str);
            for(j=0;j<len;j++)
                ar[i][str[j]-'a']++;
        }
        cnt = 0;
        for(i=0;i<26;i++)
        {
            int mn = OO;
            for(j=0;j<n;j++)
            {
                mn = min(mn,ar[j][i]);
            }
            if(mn)
                cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
