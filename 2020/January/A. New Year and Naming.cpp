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

int i,x,a,b,n,m,q;
char str1[100][100];
char str2[100][100];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
            scanf("%s",str1[i]);
        for(i=0;i<m;i++)
            scanf("%s",str2[i]);

        scanf("%d",&q)    ;
        while(q--)
        {
            scanf("%d",&x);
            a = x%n;
            b = x%m;
            if(a==0)
                printf("%s",str1[n-1]);
            else
                printf("%s",str1[a-1]);

            if(b==0)
                printf("%s",str2[m-1]);
            else
                printf("%s",str2[b-1]);
            printf("\n");
        }
    }

    return 0;
}
