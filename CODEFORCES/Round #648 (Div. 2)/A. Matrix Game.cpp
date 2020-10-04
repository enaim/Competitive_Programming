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

int ar[52][52];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n,m,r,c;
        r = c = 0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&ar[i][j]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(ar[i][j]!=0)
                    break;
            if(j==m)
                r++;
        }
        for(j=0;j<m;j++)
        {
            for(i=0;i<n;i++)
                if(ar[i][j]!=0)
                    break;
            if(i==n)
                c++;
        }
        int x = min(r,c);
        if(x&1)
            printf("Ashish\n");
        else
            printf("Vivek\n");
    }

    return 0;
}
