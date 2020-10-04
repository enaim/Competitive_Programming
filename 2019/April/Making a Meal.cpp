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

int i,j,n,mn,len;
int flag[30];
char str[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,0,sizeof flag);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            len = strlen(str);
            for(j=0;j<len;j++)
                flag[str[j]-'a']++;
        }
        mn = OO;
        mn = min(mn,flag['c'-'a']/2);
        mn = min(mn,flag['o'-'a']);
        mn = min(mn,flag['d'-'a']);
        mn = min(mn,flag['e'-'a']/2);
        mn = min(mn,flag['h'-'a']);
        mn = min(mn,flag['f'-'a']);
        printf("%d\n",mn);
    }


    return 0;
}
