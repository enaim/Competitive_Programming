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


    int tks,ks=1,n,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        if(n>=0)
        {
            for(i=0;i<=n;i++)
            {
                if(i==n)
                    printf("%d\n",i);
                else
                    printf("%d ",i);
            }
        }
        else
        {
            for(i=n;i<=0;i++)
            {
                if(i==0)
                    printf("%d\n",i);
                else
                    printf("%d ",i);
            }
        }

//        printf("Case %d: ",ks++);
    }

    return 0;
}
