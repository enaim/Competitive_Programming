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
        int sum,sum1,ans;
        sum = sum1 = ans = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==2)
                sum++;
            else
                sum1++;
        }
        if(sum1>=sum)
        {
            ans+=sum;
            sum1-=sum;
            ans += sum1/3;
        }
        else if(sum1)
            ans = sum1;
        else
            ans = 0;
        printf("%d\n",ans);
    }

    return 0;
}
