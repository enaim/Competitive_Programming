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

    int ar[100010],a,b,c,d,e,n,cnt,i;
    while(5==scanf("%d%d%d%d%d",&a,&b,&c,&d,&n))
    {
        cnt = 0;
        memset(ar,0,sizeof ar);
        for(i=1;i<=n;i++)
        {
            if(i%a==0 || i%b==0 || i%c==0 || i%d==0)
                ar[i]++;
        }
        for(i=1;i<=n;i++)
            if(ar[i]==0)
                cnt++;
        printf("%d\n",n-cnt);
    }

    return 0;
}
