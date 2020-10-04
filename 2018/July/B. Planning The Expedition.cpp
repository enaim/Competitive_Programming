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

    int ar[110],i,j,k,cnt,n,m;
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
           scanf("%d",&ar[i]) ;

        sort(&ar[0],&ar[m]);

        cnt = 0;
        for(i=1;i<=110;i++)
        {
            j = 1;
            k = 0;
            while(j<=n && k<m)
            {
                if(k+i-1<m)
                {
                    if(ar[k]==ar[k+i-1])
                    {
                        k = k+i;
                        j++;
                    }
                    else
                        k++;
                }
                else
                    k++;
            }
            if(j>n)
                cnt++;
            else
                break;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
