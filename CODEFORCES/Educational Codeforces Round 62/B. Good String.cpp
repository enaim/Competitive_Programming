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

    int tks,ks=1,i,les,grt,n,cnt,mn;
    char str[110];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%s",&n,str);
        for(i=0;i<n;i++)
            if(str[i]=='<')
                les++;
            else
                grt++;
        if(les==0 || grt==0)
        {
            printf("0\n");
            continue;
        }
        mn = OO;
        cnt = 0;
        for(i=n-1;i>=0;i--)
            if(str[i]=='>')
                cnt++;
            else
                break;
        mn = min(mn,cnt);
        cnt = 0;
        for(i=0;i<n;i++)
            if(str[i]=='<')
                cnt++;
            else
                break;
        mn = min(mn,cnt);
        printf("%d\n",mn);
    }

    return 0;
}
