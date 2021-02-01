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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

struct node{
    char str[30];
    int val;
};
node ar[110];

bool compare(node a,node b)
{
    return a.val<b.val;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,x,y,z,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",ar[i].str);
            scanf("%d%d%d",&x,&y,&z);
            ar[i].val = x*y*z;
        }

        sort(&ar[0],&ar[n],compare);
        if(ar[0].val==ar[n-1].val)
            printf("Case %d: no thief\n",ks++);
        else
            printf("Case %d: %s took chocolate from %s\n",ks++,ar[n-1].str,ar[0].str);
    }

    return 0;
}
