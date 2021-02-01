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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[100010],br[100010],n,x,temp,i;
    while(1==scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ar[i]=x;
            br[x]=i;
        }
        temp = 0;
        for(i=1;i<=n;i++)
        {
            if(ar[i]==br[i])
                continue;
            else
            {
                temp = 1;
                break;
            }
        }

        if(temp == 0)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }

    return 0;
}
