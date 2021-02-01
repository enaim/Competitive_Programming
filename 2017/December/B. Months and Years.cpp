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

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;
typedef pair<int,int>pii;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,x,y;
    int ar[100];
    int cnt = 0;
    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 29;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 29;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    ar[cnt++] = 31;
    ar[cnt++] = 28;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;
    ar[cnt++] = 30;
    ar[cnt++] = 31;

    int cnt1,br[100];
    while(1==scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&br[i]);

        cnt1 = 0;
        for(int i=0;i<96;i++)
        {
            int k = i;
            cnt1 = 0;
            for(int j=0;j<n;j++)
            {
                if(ar[k++]==br[j])
                    cnt1++;
                else
                    cnt1 = 0;
            }
            if(cnt1 == n)
                break;
        }
        if(cnt1==n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
