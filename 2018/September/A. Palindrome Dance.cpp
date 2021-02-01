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
#include <stack>
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

    int i,x,n,sum,mn,a,b;
    int ar[110];

    while(3==scanf("%d%d%d",&n,&a,&b))
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        mn = 0;
        if(a>b)
            mn = 1;

        x = n/2;
        i=0;
        sum = 0;

        while(x>=i)
        {
            if(ar[n-i-1] !=2 && ar[i]==2)
            {
                ar[i] = ar[n-i-1];
                if(ar[i]==1)
                    sum+=b;
                else
                    sum+=a;
            }
            else if(ar[n-i-1] == 2 && ar[i]!=2)
            {
                ar[n-i-1] = ar[i];
                if(ar[i]==1)
                    sum+=b;
                else
                    sum+=a;
            }
            i++;
        }

        for(i=0;i<n;i++)
            if(ar[i]==2)
            {
                ar[i]=mn;
                if(ar[i]==1)
                    sum+=b;
                else
                    sum+=a;
            }

        i = 0;
        while(i<=x)
        {
            if(ar[i] != ar[n-i-1])
                break;
            i++;
        }
        if(i!=x+1)
        {
            printf("-1\n");
            continue;
        }
        cout<<sum<<endl;
    }

    return 0;
}
