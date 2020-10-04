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
typedef pair<int,int>pii;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,i,x,y;
    while(1==scanf("%d",&n))
    {
        int sum1,sum2;
        sum1 = sum2 = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x<0)
                sum1++;
            else
                sum2++;
        }
        if(sum1 ==n || sum2 == n || sum1 == n-1 || sum2 ==n-1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
