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
//    freopen("output1.txt","w",stdout);

    int tks,ks=1,n,i,x,cnt1,cnt2,cnt;
    int ar[100010];
    int br[100010];
    int temp[100010];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        cnt1 = 1;
        cnt2 = 1;
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
                scanf("%d",&ar[cnt1++]);
            else
                scanf("%d",&br[cnt2++]);
        }
        sort(&ar[0],&ar[cnt1]);
        sort(&br[0],&br[cnt2]);
        cnt = 0;
        for(i=1;i<=n/2;i++)
        {
            temp[cnt++]=ar[i];
            temp[cnt++]=br[i];
        }
        if(n%2!=0)
            temp[cnt++] = ar[i];

        for(i=1;i<n;i++)
        {
            if(temp[i-1]>temp[i])
                break;
        }
        if(i==n)
            printf("Case #%d: OK\n",ks++);
        else
            printf("Case #%d: %d\n",ks++,i-1);
    }

    return 0;
}
