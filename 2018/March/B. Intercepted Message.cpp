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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[100010];
    int br[100010];
    int n,m,i,j,sum1,sum2;
    while(2==scanf("%d%d",&n,&m))
    {
        int cnt = 0;
        for(i=0;i<n;i++)
            cin>>ar[i];
        for(i=0;i<m;i++)
            cin>>br[i];
        i=-1;
        j=-1;
        sum1=0;
        sum2=0;
        while(i!=n && j!=m)
        {
            if(sum1<sum2)
            {
                i++;
                sum1+=ar[i];
            }
            if(sum2<sum1)
            {
                j++;
                sum2+=br[j];

            }
            if(sum1==sum2)
            {
                if(sum1)
                    cnt++;
                i++;
                j++;
                sum1 = ar[i];
                sum2 = br[j];
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
