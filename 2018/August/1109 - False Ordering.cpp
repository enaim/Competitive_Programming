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
    int c=0,ind;
};
node ar[1010];

bool compare(node a,node b)
{
    if(a.c==b.c)
        return a.ind>b.ind;
    return a.c<b.c;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i/2;j++)
            if(i%j==0)
                ar[i].c++;
        ar[i].c++;
        ar[i].ind = i;
    }
    sort(&ar[1],&ar[1001],compare);

    int tks,ks=1,n;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",ks++,ar[n].ind);
    }

    return 0;
}
