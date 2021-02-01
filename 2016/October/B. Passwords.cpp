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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[110];
    int len[110];
    int i,n,k,best,worst,x,sum_les,cn,cnt,ln;

    while(2 == scanf("%d%d",&n,&k))
    {
        cn = 0;
        cnt = 0;
        best = 0;
        worst = 0;
        sum_les= 0;
        for(i=0;i<=n;i++)
        {
            scanf("%s",str);
            ln = strlen(str);
            len[i]=ln;
        }

        for(i=0;i<n;i++)
        {
            if(len[n] > len[i])
                cnt++;
            if(len[n] < len[i])
                cn++;
        }
        if(cnt!=0)
        {
            x = cnt/k;
            sum_les=(x*5)+cnt;
        }

        x = (n-cn-1)/k;
        best = sum_les+1;
        worst = (x*5)+(n-cn);
        printf("%d %d\n",best,worst);
    }

    return 0;
}
