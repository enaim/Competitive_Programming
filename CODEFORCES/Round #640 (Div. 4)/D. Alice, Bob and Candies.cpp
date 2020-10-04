#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

int ar[1010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,sum1,sum2,n,l,r,last;

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);

        sum1 = sum2 = 0;
        l = 0;
        r = n-1;
        last = 0;
        int f = 0;
        while(l<=r)
        {
            if(f%2==0)
            {
                int x = 0;
                while(x<=last && l<=r)
                {
                    x+=ar[l];
                    l++;
                }
                sum1+=x;
                last = x;
                f++;
            }
            else
            {
                int x = 0;
                while(x<=last && l<=r)
                {
                    x+=ar[r];
                    r--;
                }
                sum2+=x;
                last = x;
                f++;
            }
        }
        printf("%d %d %d\n",f,sum1,sum2);
    }

    return 0;
}
