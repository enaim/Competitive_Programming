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

int a[100010];
int a1[100010];
int a2[100010];
int b;
int ar[100010];
int flag[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,m,k;

    while(2==scanf("%d%d",&n,&m))
    {
        int cnt = 0;
        for(i=1;i<=n+m;i++)
        {
            if(i<=n)
                scanf("%d",&a1[i]);
            else
                scanf("%d",&a2[i-n]);
        }
        k = 0;
        for(i=1;i<=n+m;i++)
        {
            scanf("%d",&b);
            if(b==1)
            {
                cnt++;
                if(i<=n)
                    ar[cnt]=a1[i];
                else
                    ar[cnt]=a2[i-n];
            }
            else
            {
                ++k;
                if(i<=n)
                    a[k]=a1[i];
                else
                    a[k]=a2[i-n];
            }
        }

        k = 1;
        for(i=1;i<=n;i++)
        {
            if(k+1<=cnt)
            {
                if(abs(a[i]-ar[k])<=abs(a[i]-ar[k+1]))
                    flag[k]++;
                else
                {
                    k++;
                    i--;
                }
            }
            else
                flag[k]++;
        }
        for(i=1;i<=cnt;i++)
            printf("%d ",flag[i]);
    }

    return 0;
}
