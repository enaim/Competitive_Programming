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

long long ar[20000010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    long long tks,ks=1,n,rid,pid,i,t;
    scanf("%lld",&tks);
    while(tks--)
    {
        memset(ar,0,sizeof ar);
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&t);
            if(t==1)
            {
                scanf("%lld%lld",&pid,&rid);
                if(ar[rid]== 0)
                {
                    printf("Y\n");
                    ar[rid] = pid;
                }
                else
                    printf("N\n");
            }
            else
            {
                scanf("%lld",&rid);
                if(ar[rid]== 0)
                {
                    printf("F\n");
                }
                else
                {
                    printf("%lld\n",ar[rid]);
                    ar[rid]= 0;
                }
            }
        }
    }

    return 0;
}
