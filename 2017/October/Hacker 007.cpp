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


    int tks,ks=1,x,y,sum1,sum2,cnt,n,i;
    scanf("%d",&tks);
    while(tks--)
    {
        sum1 = sum2 = cnt = 0;
        scanf("%d",&n);
        for(i=0;i<11;i++)
        {
            scanf("%d%d",&x,&y);
            sum1+=x;
            sum2+=y;
            if(x==1 && y==1)
                cnt = 1;
        }

        if(sum1>sum2)
            printf("Case %d: Hacked!\n",ks++);
        else if(sum1 == 1 && sum2 ==1)
        {
            if(cnt==1)
                printf("Case %d: Hacked!\n",ks++);
        }
//        else if(sum2 != n)
//            printf("Case %d: Hacked!\n",ks++);
        else
            printf("Case %d: Can't say!\n",ks++);

//        printf("Case %d: ",ks++);
    }

    return 0;
}
