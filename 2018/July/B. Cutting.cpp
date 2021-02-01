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

int ar[110];
int ev[110];
int od[110];
int br[110];
int n,b,i;

bool func()
{
    if(i/2==od[i-1] && od[i-1] && ev[i-1] && abs(ar[i]-ar[i-1])<=b && od[i-1]==ev[i-1])
        return true;
    return false;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&b))
    {
        int e = 0;
        int o = 0;
        int cnt = 0;
        int sum = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]%2==0)
                e++;
            else
                o++;
            ev[i]= e;
            od[i]= o;
        }
        for(i=2;i<=n;i++)
        {
            if(func())
            {
                br[cnt++]= abs(ar[i]-ar[i-1]);
            }
        }
        sort(&br[0],&br[cnt]);
        for(i=0;i<cnt;i++)
        {
            sum+=br[i];
            if(sum>b)
                break;
        }
        printf("%d\n",i);
    }

    return 0;
}
