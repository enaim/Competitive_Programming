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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int z = 0;
        int n,x,y,i;
        scanf("%d",&n);
        scanf("%d",&x);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&y);
            if(y-x==1)
                z = 1;
            x = y;
        }
        if(z)
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }


    return 0;
}
