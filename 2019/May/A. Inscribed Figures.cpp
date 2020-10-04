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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

    int n,ar[110],i,f,sum;
    while(1==scanf("%d",&n))
    {
        sum = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        f =  0;
        for(i=1;i<n;i++)
        {
            if(ar[i-1]==1)
            {
                if(ar[i]==2)
                    sum+=3;
                else
                    sum+=4;
            }
            if(ar[i-1]==2)
            {
                if(ar[i]==1)
                    sum+=3;
                else
                    f = 1;
            }
            if(ar[i-1]==3)
            {
                if(ar[i]==1)
                    sum+=4;
                else
                    f = 1;
            }
            if(i>=2 && ar[i-2]==3 && ar[i-1]==1 && ar[i]==2)
                sum--;
        }
        if(f)
            printf("Infinite\n");
        else
            printf("Finite\n%d\n",sum);
    }

    return 0;
}
