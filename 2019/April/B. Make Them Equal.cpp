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

    int i,n,x,f,d;
    while(1==scanf("%d",&n))
    {
        f = 0;
        set<int>st;
        int ar[110];
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]),st.insert(ar[i]);

        sort(&ar[0],&ar[n]);
        int mn = ar[0];
        int mx = ar[n-1];
        if(st.size()==1)
        {
            printf("0\n");
            continue;
        }
        if(st.size()==2)
        {
            if((mx-mn)%2==0)
                printf("%d\n",(mx-mn)/2);
            else
                printf("%d\n",mx-mn);
            continue;
        }
        d = (mx-mn)/2;
        x = mn+d;
        for(i=0;i<n;i++)
        {
            if(ar[i]<x)
                ar[i]+=d;
            else if(ar[i]==x)
                continue;
            else
                ar[i]-=d;
        }
        for(i=0;i<n-1;i++)
            if(ar[i]!=ar[i+1])
                f = 1;
        if(f)
            printf("-1\n");
        else
            printf("%d\n",d);

    }

    return 0;
}
