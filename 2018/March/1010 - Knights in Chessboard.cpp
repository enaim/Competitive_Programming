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

    int tks,ks=1,x,m,n,ans;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&m,&n);
        if(m==1 || n==1)
            ans = m*n;
        else if(m<=2 || n<=2)
        {
            x = m*n;
            ans = ((m*n)/8)*4;
            x = (m*n)%8;
            if(x>=4)
                ans+=4;
            else if(x!=0)
                ans+=2;
        }
        else
        {
            x = n/2;
            ans = x * m;
            if(n%2!=0)
                ans += (m+1)/2;
        }
        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
