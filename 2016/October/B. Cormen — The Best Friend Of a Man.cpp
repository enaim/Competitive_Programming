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
    int n,k,i,cnt,add;
    int ar[510],br[510];

    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        cnt = 1;
        add=0;
        br[0]=ar[0];
        while(cnt!=n)
        {
            if((k-ar[cnt-1]) > ar[cnt])
            {
                br[cnt]=k-ar[cnt-1];
                add+=(br[cnt]-ar[cnt]);
                ar[cnt]=k-ar[cnt-1];
            }
            else
                br[cnt]=ar[cnt];

            cnt++;
        }
        printf("%d\n",add);
        for(i=0;i<n;i++)
        {
            if(i==(n-1))
                printf("%d\n",br[i]);
            else
                printf("%d ",br[i]);
        }
    }

    return 0;
}

