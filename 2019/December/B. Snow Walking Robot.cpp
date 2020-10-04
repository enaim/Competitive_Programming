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

char str[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%s",str);
        int n = strlen(str);
        int l,r,u,d,i;
        l = r = u = d = 0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='L')     l++;
            if(str[i]=='R')     r++;
            if(str[i]=='U')     u++;
            if(str[i]=='D')     d++;
        }
        l = min(l,r);
        r = min(l,r);
        u = min(u,d);
        d = min(u,d);

        if(l && r && u==0 && d==0)
        {
            printf("2\nLR\n");
            continue;
        }
        if(l==0 && r==0 && u && d)
        {
            printf("2\nUD\n");
            continue;
        }
        if(l+r+u+d==0)
        {
            printf("0\n\n");
            continue;
        }
        printf("%d\n",l+r+u+d);
        for(i=0;i<l;i++)
            printf("L");
        for(i=0;i<u;i++)
            printf("U");
        for(i=0;i<r;i++)
            printf("R");
        for(i=0;i<d;i++)
            printf("D");
        printf("\n");
    }

    return 0;
}
