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
const int SIZE = 100;

int n;
int ar[SIZE];
int BIT[SIZE];

void update(int index,int v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

int Query(int index)
{
    int ans = 0;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,l,r,t,x,v,z,ans;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for(i=1;i<=n;i++)
        {
            update(i,ar[i]);
        }
//        for(i=1;i<=n;i++)
//        {
//            update(i,ar[i]);
//            update(i+1,-ar[i]);
//        }

        while(true)
        {
            scanf("%d",&t);
//          Point update Range Query
            if(t==1)                            //update
            {
                scanf("%d%d",&x,&v);            // array[x] = v
                z = ar[x];
                ar[x] = v;
                update(x,v-z);
            }
            else                                //Query
            {
                scanf("%d%d",&l,&r);
                ans = Query(r) - Query(l-1);
                printf("%d -> %d = %d\n",l,r,ans);
            }
//          Range update Point Query
//            if(t==1)                            //update
//            {
//                scanf("%d%d%d",&l,&r,&v);      // (l->r) + v
//                update(l,v);
//                update(r+1,-v);
//            }
//            else                                //Query
//            {
//                scanf("%d",&x);
//                ans = Query(x);
//                printf("%d -> %d\n",x,ans);
//            }
        }
    }

    return 0;
}
