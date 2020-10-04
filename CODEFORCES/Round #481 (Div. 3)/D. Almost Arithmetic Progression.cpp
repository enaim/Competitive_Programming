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


int ar[100010];
int temp[100010],ans,cnt,i,n,d,x;
int divv;

void go()
{
    for(i=n-2;i>=0;i--)
    {
        d = ar[i+1]-ar[i];
        if(d==x)
            continue;
        if(x-d==1)
        {
            ar[i]--;
            cnt++;
        }
        else if(x-d==-1)
        {
            ar[i]++;
            cnt++;
        }
        else
            break;
    }

    if(i==-1)
        ans = min(ans,cnt);
}

void func()
{
    cnt = 0;
    for(i=0;i<n;i++)
        ar[i]=temp[i];
    go();

    for(i=0;i<n;i++)
        ar[i]=temp[i];
    ar[n-1]++;
    cnt = 1;
    go();

    for(i=0;i<n;i++)
        ar[i]=temp[i];
    ar[n-1]--;
    cnt = 1;
    go();
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int j,k,z,t,br[100010],a;
    while(1==scanf("%d",&n))
    {
        ans = OO;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            br[i] = ar[i];
            temp[i]=ar[i];
        }
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        t = n;
        if(ar[0]>ar[n-1])
        {
            for(i=0;i<n;i++)
            {
                ar[i] = br[t-1];
                temp[i]=ar[i];
                t--;
            }
        }

        divv = abs(ar[n-1]-ar[0]);

        x = divv/(n-1);
        func();
        if((x*(n-1))!=divv)
            x++;
        func();
        if(ans == OO)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }

    return 0;
}
