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

    int i,n,b,k,x;

    while(2==scanf("%d%d",&b,&k))
    {
        int cnt = 0;
        for(i=0;i<k;i++)
        {
            scanf("%d",&x);
            if(x%2!=0)
                cnt++;
        }
        if(b%2==0 && x%2!=0)
        {
            printf("odd\n");
            continue;
        }
        else if(b%2==0)
        {
            printf("even\n");
            continue;
        }
        else if(cnt%2==0)
            printf("even\n");
        else
            printf("odd\n");
    }

    return 0;
}
