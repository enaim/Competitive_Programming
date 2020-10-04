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

template<class T>T sqr(T a)
{
    return a*a;
}
template<class T> T abs(T x)
{
    if(x<0)
        return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,k,n=4;
    int ar[10];
    int sum = 0;
    for(i=0; i<4; i++)
    {
        scanf("%d",&ar[i]);
        sum+=ar[i];
    }
    if(sum%2!=0)
    {
        printf("NO\n");
        return 0;
    }
    for(i=0; i<n; i++)
        if(sum+ar[i]==sum/2)
        {
            printf("YES\n");
            return 0;
        }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(ar[i]+ar[j]==sum/2)
            {
                printf("YES\n");
                return 0;
            }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            for(k=j+1; k<n; k++)
                if(ar[i]+ar[j]+ar[k]==sum/2)
                {
                    printf("YES\n");
                    return 0;
                }
    printf("NO\n");
    return 0;
}
