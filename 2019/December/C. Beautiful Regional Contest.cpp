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

ll ar[400010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll i,j,k,n,a,b,c;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        n = n/2;

        if(n<5)
        {
            printf("0 0 0\n");
            continue;
        }
        i=1;
        while(ar[i-1]==ar[i] && i<n)
            i++;
        j = i+i + 1LL;
        while(ar[j-1]==ar[j] && j<n)
            j++;
        k = n-1;
        while(j<k && ar[k]==ar[k+1])
            k--;
        k++;
        if(!(i<j && j<k))
        {
            printf("0 0 0\n");
            continue;
        }
        a = i;
        b = j - a;
        c = k - a - b;
        if(a<b && a<c)
            printf("%lld %lld %lld\n",a,b,c);
        else
            printf("0 0 0\n");
    }

    return 0;
}
