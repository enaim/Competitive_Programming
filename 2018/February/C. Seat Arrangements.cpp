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

char str[3000][3000];


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int r,c,cnt,i,j,k;
    while(3==scanf("%d%d%d",&r,&c,&k))
    {
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        ll ans = 0;

        for(i=0;i<r;i++)
        {
            cnt = 0;
            for(j=0;j<=c;j++)
            {
                if(str[i][j]=='.' && j<c)
                    cnt++;
                else
                {
                    if(cnt>=k)
                    {
                        ans += (cnt-k+1);
                    }
                    cnt = 0;
                }
            }
        }

        if(k!=1)
        {
            for(i=0;i<c;i++)
            {
                cnt = 0;
                for(j=0;j<=r;j++)
                {
                    if(str[j][i]=='.' && j<r)
                        cnt++;
                    else
                    {
                        if(cnt>=k)
                        {
                            ans += (cnt-k+1);
                        }
                        cnt = 0;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
