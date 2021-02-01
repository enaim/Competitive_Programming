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

int ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,i,mx,mn,box,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        sort(&ar[0],&ar[n]);
        box = 1;
        cnt = 0;
        for(i=n-1;i>0;i--)
        {
            mx = ar[i];
            mn = ar[i-1];
            if(mx==mn)
            {
                cnt++;
                if(cnt>=box)
                    box++;
            }
            else
                cnt = 0;
        }
        printf("Case %d: %d\n",ks++,box);
    }


    return 0;
}
