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
    int i,len,p,s,cnt;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%s",&len,str);
        p = s = cnt = 0;
        for(i=0;i<len;i++)
            if(str[i]=='P')
                p++;
        for(i=2;i<len-2;i++)
        {
            if(str[i]=='A' && (str[i-1]=='P' || str[i-2]=='P') && (str[i+1]=='P' || str[i+2]=='P'))
                s++;
        }
        cnt = (len/4)*3 + len%4;
        if(p+s<cnt)
            printf("-1\n");
        else
            printf("%d\n",max(0,cnt-p));
    }

    return 0;
}
