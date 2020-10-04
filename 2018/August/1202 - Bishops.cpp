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

    int tks,ks=1,r1,c2,r2,c1,x,y;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        x =abs(r1-r2);
        y =abs(c1-c2);
        if(x==y)
            printf("Case %d: 1\n",ks++);
        else if((x%2==0 && y%2==0) || x%2!=0 && y%2!=0)
            printf("Case %d: 2\n",ks++);
        else
            printf("Case %d: impossible\n",ks++);
    }

    return 0;
}
