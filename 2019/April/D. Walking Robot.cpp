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


int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,a,b;
    while(3==scanf("%d%d%d",&n,&b,&a))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);
        int x = a;
        for(i=1;i<=n;i++)
        {
            if(b && ar[i] && a<x)
                b--,a++;
            else if(a)
                a--;
            else if(b && ar[i])
                b--,a++;
            else if(b)
                b--;
            else
                break;
        }
        printf("%d\n",i-1);
    }

    return 0;
}
