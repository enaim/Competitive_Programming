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
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int ar[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x;
    while(1==scanf("%d",&n))
    {
        memset(ar,0,sizeof ar);
        ar[0]=1;
        int cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(ar[x])
                cnt++;
            ar[x] = 1;
        }
        printf("%d\n",cnt);;
    }

    return 0;
}
