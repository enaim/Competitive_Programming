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

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int n;
long long dp[70000];
vector<int>vec[20];
long long invalid;

long long megamans(int pos)
{
    int i,j,x,z,temp;
    if(pos == ((1<<n)-1))
        return 1;
    
    long long &re = dp[pos];
    if(re != invalid)
        return re;

    re = 0;

    for(i=1;i<=n;i++)
    {
        x = pos & (1<<i-1);
        if(x == 0)
        {
            for(j=0;j<vec[i].size();j++)
            {
                if(vec[i][j] == 0)
                {
                    re += megamans(pos | (1<<i-1));
                    break;
                }
                z = pos & (1<<vec[i][j]-1);
                
                if(z != 0)
                {
                    re += megamans(pos | (1<<i-1));
                    break;
                }
            }
        }
    }

    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset(&invalid,0x1f,sizeof invalid);

    int tks,ks=1,i,j;
    long long res;
    char str[20];
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,0x1f,sizeof dp);
        scanf("%d",&n);
        
        for(i=0;i<20;i++)
            vec[i].clear();

        for(i=0;i<=n;i++)
        {
            scanf("%s",str);
            for(j=0;j<n;j++)
            {
                if(str[j] == '1')
                    vec[j+1].pb(i);
            }
        }

        res = megamans(0);

        printf("Case %d: %lld\n",ks++,res);
    }


    return 0;
}
